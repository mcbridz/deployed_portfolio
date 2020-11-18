from django.db import models
from django.contrib.auth.models import User


class BlogPost(models.Model):
    title = models.CharField(max_length=100)
    body = models.TextField()
    image = models.ImageField(
        upload_to='profile/images/', null=True, default='profile/images/200.jpg')
    user = models.ForeignKey(
        User, on_delete=models.CASCADE, related_name='posts')
    public = models.BooleanField(default=False)
    date_created = models.DateTimeField(auto_now_add=True)
    date_edited = models.DateTimeField(null=True, blank=True)
    # BlogPost.comments accesses comments associated with instanced BlogPost

    def __str__(self):
        return self.title + ': ' + str(self.date_created)


class UserProfile(models.Model):
    profile_picture = models.ImageField(upload_to='profile/images/', null=True)
    login_name = models.OneToOneField(
        User, on_delete=models.CASCADE, related_name='profile')

    def __str__(self):
        return self.login_name.last_name + ', ' + self.login_name.first_name


class Comment(models.Model):
    content = models.TextField()
    parent_comment = models.ForeignKey(
        'Comment', on_delete=models.PROTECT, related_name='children', null=True)
    blog_post = models.ForeignKey(
        BlogPost, on_delete=models.PROTECT, related_name='comments')
    deleted_comment = models.BooleanField(default=False)
    user = models.ForeignKey(
        User, on_delete=models.CASCADE, related_name='comments')

    def __str__(self):
        output = 'Content: ' + str(self.content) + \
            '\n' + 'Blog Post: ' + str(self.blog_post)
        return output
