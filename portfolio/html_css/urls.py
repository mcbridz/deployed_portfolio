from django.urls import path
from . import views

app_name = 'html_css'
urlpatterns = [
    path('landing/', views.landing, name='landing'),
    path('bootstrap/index/', views.bootstrap_index, name='bootstrap_index'),
    path('bootstrap/axios_ajax_vue_demo/', views.cats, name='cats'),
    path('bootstrap/unit_converter/', views.unit_converter, name='unit_converter'),
    path('bootstrap/password_generator/',
         views.password_generator, name='password_generator'),
    path('bootstrap/number_to_phrase/',
         views.number_to_phrase, name='number_to_phrase'),
    path('bootstrap/grading/', views.grading, name='grading'),
    path('bootstrap/todo_list/', views.todo_list, name='todo_list'),
    path('bootstrap/rotN/', views.rotN, name='rotN'),
    path('bootstrap/weather/', views.weather, name='weather'),
    path('bootstrap/quiz/', views.quiz, name='quiz'),
    path('materialize/index/', views.materialize_index, name='materialize_index')
]
