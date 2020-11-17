from django.shortcuts import render
from django.http import HttpResponse


def landing(request):
    return render(request, 'html_css/landing.html')


def bootstrap_index(request):
    return render(request, 'html_css/bootstrap_index.html')


def cats(request):
    return render(request, 'html_css/cats.html')


def unit_converter(request):
    return render(request, 'html_css/unit-converter.html')


def password_generator(request):
    return render(request, 'html_css/random-password-generator.html')


def number_to_phrase(request):
    return render(request, 'html_css/number-to-phrase.html')


def grading(request):
    return render(request, 'html_css/grading.html')


def todo_list(request):
    return render(request, 'html_css/to-do-list.html')


def rotN(request):
    return render(request, 'html_css/rotN.html')


def weather(request):
    return render(request, 'html_css/weather.html')


def quiz(request):
    return render(request, 'html_css/quiz.html')
