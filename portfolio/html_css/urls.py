from django.urls import path
from . import views

app_name = 'html_css'
urlpatterns = [
    path('landing/', views.landing, name='landing')
]
