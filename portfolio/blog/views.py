from django.shortcuts import render, reverse, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from django.contrib.auth.decorators import login_required
from django.urls import reverse
from django.conf import settings
from django.contrib.auth.models import User
from .models import UserProfile, BlogPost, Comment
import requests
import random


# from django.contrib.auth import login as login_user
import django.contrib.auth


def welcome(request):
    return HttpResponse('Hello, World!')


def index(request):
    django.contrib.auth.logout(request)
    return HttpResponseRedirect(reverse('blog_app:login'))


def home(request):
    feed_data = BlogPost.objects.all().order_by('-date_created')
    feed = []
    for post in feed_data:
        print('***********************************************')
        print(post.user.profile_picture == '')
        print('***********************************************')
        feed.append({
            'id': post.id,
            'post_text': post.body,
            'post_title': post.title,
            'image': post.image.url,
            'user': post.user.login_name.username,
            'user_image': '' if post.user.profile_picture == '' else post.user.profile_picture.url,
            'date': post.date_created.strftime('%m/%d/%Y'),
        })
    authenticated = False
    if request.user.is_authenticated:
        authenticated = True
    return render(request, 'blog/home.html', {'feed': feed, 'authenticated': authenticated})


@login_required
def logout(request):
    django.contrib.auth.logout(request)
    return HttpResponseRedirect(reverse('blog_app:login'))


@login_required
def post_detail(request, post_id):
    post = get_object_or_404(BlogPost, pk=post_id)
    if post.user != request.user:
        return HttpResponseRedirect(reverse('blog_app:home'))
    context = {
        'title': post.title,
        'body': post.body,
        'image': post.image.url,
        'date': post.date_created,
        'post': post
    }
    return render(request, 'blog/post_detail.html', context)

# def build_tree_helper(tree, level):
#     finished = False
#     for comment in tree[level]:
#         if not Comment.objects.filter(parent_comment=comment).exists():
#             finished = True
#     if finished is False:
#         return
#     ...

# def build_tree(blog_post):
#     first_comments = Comment.objects.filter(blog_post=blog_post)
#     tree = {}
#     level = 1
#     tree[level] = []
#     comment_list = {}
#     for comment in first_comments:
#         comment_list[comment.id] = comment
#     tree[level].append(comment_list)
#     build_tree_helper(tree, level)


def post_view(request, post_id):
    post = get_object_or_404(BlogPost, pk=post_id)
    context = {
        'title': post.title,
        'body': post.body,
        'image': post.image.url,
        'date': post.date_created,
        'post': post,
        'authenticated': False,
        'comments_exist': False,
    }
    if post.comments.all().exists():
        comments = post.comments.all()
        context['comments_exist'] = True
        context['comments'] = comments
    if request.user.is_authenticated:
        context['authenticated'] = True
    return render(request, 'blog/post_view.html', context)


@login_required
def delete_post(request, post_id):
    post = get_object_or_404(BlogPost, pk=post_id)
    post.delete()
    return HttpResponseRedirect(reverse('blog_app:profile'))


@login_required
def save_post(request):
    blog_data = request.POST
    print(blog_data)
    title = blog_data['title']
    body = blog_data['body']
    blog_post = BlogPost(title=title, body=body, user=request.user.profile_ref)
    if request.FILES.get('image', False):
        image = request.FILES['image']
        blog_post.image = image
    blog_post.save()
    # print(blog_post.id)
    return HttpResponseRedirect(reverse('blog_app:post_detail', args=[blog_post.id]))


@login_required
def comment_post(request, post_id):
    # print(request.POST)
    content = request.POST['comment']
    blog_post = get_object_or_404(BlogPost, pk=post_id)
    new_comment = Comment(content=content, blog_post=blog_post)
    # print(new_comment)
    new_comment.save()
    return HttpResponseRedirect(reverse('blog_app:post_view', args=[post_id]))


def comment_detail(request, comment_id):
    comment = get_object_or_404(Comment, pk=comment_id)
    context = {
        'comment': comment,
        'authenticated': False,
        'has_children': False,
    }
    if request.user.is_authenticated:
        context['authenticated'] = True
    if Comment.objects.filter(parent_comment=comment_id).exists():
        context['has_children'] = True
    return render(request, 'blog/comment_detail.html', context)


@login_required
def profile(request):
    posts = BlogPost.objects.filter(
        user=request.user.profile_ref).order_by('-date_created')
    # print(posts)
    context = {
        'user': request.user,
        'posts': posts,
    }
    if request.method == 'POST':
        # print(request.POST)
        user = request.user
        image = request.FILES['profile_picture']
        data = request.POST
        first_name = data['first_name']
        last_name = data['last_name']
        user.first_name = first_name
        user.last_name = last_name
        user.profile_ref.profile_picture = image
        user.profile_ref.save()
        user.save()
    return render(request, 'blog/profile.html', context)


@login_required
def reset_password(request):
    if request.method == 'GET':
        context = {
            'site_key': settings.RECAPTCHA_SITE_KEY
        }
        return render(request, 'blog/reset_password.html', context)
    else:
        secret_key = settings.RECAPTCHA_SECRET_KEY
        data = {
            'response': request.POST['g-recaptcha-response'],
            'secret': secret_key,
        }
        resp = requests.post(
            'https://www.google.com/recaptcha/api/siteverify', data=data)
        result_json = resp.json()
        # print(result_json)
        # create user logic here
        if not result_json['success'] or result_json['score'] <= 0.5:
            context = {
                'site_key': settings.RECAPTCHA_SITE_KEY
            }
            return render(request, 'blog/reset_password.html', context)
        password = request.POST['password']
        password_v = request.POST['password_v']
        if password != password_v:
            context = {
                'site_key': settings.RECAPTCHA_SITE_KEY
            }
            return render(request, 'blog/reset_password.html', context)
        user = request.user
        user.set_password(password)
        user.save()
        return HttpResponseRedirect('blog_app:profile')


def register(request):
    # print('GET' + str(request.GET))
    if request.method == 'POST':
        django.contrib.auth.logout(request)
        # print(request.POST)
        secret_key = settings.RECAPTCHA_SECRET_KEY
        data = {
            'response': request.POST['g-recaptcha-response'],
            'secret': secret_key,
        }
        resp = requests.post(
            'https://www.google.com/recaptcha/api/siteverify', data=data)
        result_json = resp.json()
        # print(result_json)
        # create user logic here
        if not result_json['success'] or result_json['score'] <= 0.5:
            context = {
                'site_key': settings.RECAPTCHA_SITE_KEY
            }
            return render(request, 'blog/registration.html', context)
        password = request.POST['password']
        password_v = request.POST['password_v']
        if password != password_v:
            context = {
                'site_key': settings.RECAPTCHA_SITE_KEY
            }
            return render(request, 'blog/registration.html', context)
        username = request.POST['username']
        if User.objects.filter(username=username).exists():
            user = django.contrib.auth.authenticate(
                request, username=username, password=password)
            if user is None:
                return HttpResponseRedirect(reverse('blog_app:login'))
            django.contrib.auth.login(request, user)
            new_profile = UserProfile(login_name=user)
            new_profile.save()
            return HttpResponseRedirect(reverse('blog_app:profile'))
        user = User.objects.create_user(
            username, request.POST['email'], password)
        user.first_name = request.POST['first_name']
        user.last_name = request.POST['last_name']
        user.save()
        django.contrib.auth.login(request, user)
        new_profile = UserProfile(login_name=user)
        new_profile.save()
        return HttpResponseRedirect(reverse('blog_app:profile'))
    context = {
        'site_key': settings.RECAPTCHA_SITE_KEY
    }
    return render(request, 'blog/registration.html', context)


@login_required
def del_account(request):
    user = request.user
    profile = user.profile_ref
    django.contrib.auth.logout(request)
    if BlogPost.objects.filter(user=profile).exists():
        posts = profile.posts.all()
        posts.delete()
    profile.delete()
    try:
        user.delete()
    except:
        django.contrib.auth.login(request, user)
        return HttpResponseRedirect(reverse('mirmir_app:profile'))
    return HttpResponseRedirect(reverse('blog_app:index'))


def login(request):
    # print(request.POST)
    # print(request.GET)
    if request.method == 'POST':
        secret_key = settings.RECAPTCHA_SECRET_KEY
        data = {
            'response': request.POST['g-recaptcha-response'],
            'secret': secret_key,
        }
        resp = requests.post(
            'https://www.google.com/recaptcha/api/siteverify', data=data)
        result_json = resp.json()
        # print(result_json)
        ################################################
        if not result_json['success'] or result_json['score'] <= 0.5:
            context = {
                'site_key': settings.RECAPTCHA_SITE_KEY
            }
            return render(request, 'blog/login.html', context)
        ################################################
        # user login logic here
        username = request.POST['username']
        password = request.POST['password']
        user = django.contrib.auth.authenticate(
            request, username=username, password=password)
        if UserProfile.objects.filter(login_name=user).exists():
            django.contrib.auth.login(request, user)
            next = request.GET.get('next', reverse('blog_app:home'))
            return HttpResponseRedirect(next)
        else:
            return HttpResponseRedirect(reverse('blog_app:login'))
    context = {
        'site_key': settings.RECAPTCHA_SITE_KEY
    }
    if request.method == 'POST' and not result_json.get('success'):
        context['is_robot'] = True
    return render(request, 'blog/login.html', context)
