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


def materialize_rnd_password_gen(request):
    return render(request, 'html_css/materialize_random-password-generator.html')


def materialize_num_to_phrase(request):
    return render(request, 'html_css/materialize_number-to-phrase.html')


def materialize_grading(request):
    return render(request, 'html_css/materialize_grading.html')


def materialize_todo_list(request):
    return render(request, 'html_css/materialize_to-do-list.html')


def materialize_rotN(request):
    return render(request, 'html_css/materialize_rotN.html')


def materialize_weather(request):
    return render(request, 'html_css/materialize_weather.html')


def materialize_quiz(request):
    return render(request, 'html_css/materialize_quiz.html')

def canvas(request):
    return render(request, 'html_css/canvas.html')

# def handler404(request):
#     return render(request, 'html_css/handler.html', status=404)


# def handler500(request):
#     return render(request, 'html_css/handler.html', status=500)


# def handler403(request):
#     return render(request, 'html_css/handler.html', status=403)


# def handler400(request):
#     return render(request, 'html_css/handler.html', status=400)
# # 500
# # 403
# # 400
