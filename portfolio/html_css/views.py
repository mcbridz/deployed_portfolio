from django.shortcuts import render
from django.http import HttpResponse


def landing(request):
    return render(request, 'html_css/landing.html')

# Create your views here.
