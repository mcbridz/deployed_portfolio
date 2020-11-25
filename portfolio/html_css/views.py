from django.shortcuts import render
from django.http import HttpResponse


def landing(request):
    return render(request, 'html_css/landing.html')


def bootstrap_index(request):
    return render(request, 'html_css/bootstrap_index.html')


def cats(request):
    return render(request, 'html_css/bootstrap_cats.html')


def unit_converter(request):
    return render(request, 'html_css/bootstrap_unit-converter.html')


def password_generator(request):
    return render(request, 'html_css/bootstrap_random-password-generator.html')


def number_to_phrase(request):
    return render(request, 'html_css/bootstrap_number-to-phrase.html')


def grading(request):
    return render(request, 'html_css/bootstrap_grading.html')


def todo_list(request):
    return render(request, 'html_css/bootstrap_to-do-list.html')


def rotN(request):
    return render(request, 'html_css/bootstrap_rotN.html')


def weather(request):
    return render(request, 'html_css/bootstrap_weather.html')


def quiz(request):
    return render(request, 'html_css/bootstrap_quiz.html')


def materialize_index(request):
    return render(request, 'html_css/materialize_index.html')


def materialize_cats(request):
    return render(request, 'html_css/materialize_cats.html')


def materialize_unit_converter(request):
    return render(request, 'html_css/materialize_unit_converter.html')
