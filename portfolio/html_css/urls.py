from django.urls import path
from . import views

app_name = 'html_css'
urlpatterns = [
    path('landing/', views.landing, name='landing'),
    path('bootstrap/index/', views.bootstrap_index, name='bootstrap_index'),
    path('bootstrap/axios_ajax_vue_demo/', views.cats, name='cats'),
]
