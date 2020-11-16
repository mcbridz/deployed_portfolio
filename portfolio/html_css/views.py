from django.shortcuts import render
from django.http import HttpResponse


def landing(request):
    return render(request, 'html_css/landing.html')


def bootstrap_index(request):
    return render(request, 'html_css/bootstrap_index.html')


def cats(request):
    return render(request, 'html_css/cats.html')
