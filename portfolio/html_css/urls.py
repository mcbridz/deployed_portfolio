from django.urls import path
from . import views
from django.conf.urls.static import static
from django.conf import settings

app_name = 'html_css'
urlpatterns = [
    path('', views.landing, name="blank_landing"),
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
    path('materialize/index/', views.materialize_index, name='materialize_index'),
    path('materialize/axios_ajax_vue_demo/',
         views.materialize_cats, name='materialize_cats'),
    path('materialize/unit_converter/', views.materialize_unit_converter,
         name='materialize_unit_converter'),
    path('materialize/password_generator/', views.materialize_rnd_password_gen,
         name='materialize_password_generator'),
    path('materialize/number_to_phrase/', views.materialize_num_to_phrase,
         name='materialize_num_to_phrase'),
    path('materialize/grading/', views.materialize_grading,
         name='materialize_grading'),
    path('materialize/todo_list/', views.materialize_todo_list,
         name='materialize_todo_list'),
    path('materialize/rotN/', views.materialize_rotN, name='materialize_rotN'),
    path('materialize/weather/', views.materialize_weather,
         name='materialize_weather'),
    path('materialize/quiz/', views.materialize_quiz, name='materialize_quiz'),
    path('canvas/', views.canvas, name='canvas_landing'),
    #     path('error_handling/', views.handler, name='handler'),
] + static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)
