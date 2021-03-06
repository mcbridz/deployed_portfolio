"""portfolio URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from django.conf.urls.static import static
from django.conf import settings

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('html_css.urls')),
    path('urlshortener/', include('urlshortener.urls')),
    path('pokedex/', include('pokedex.urls')),
    path('blog/', include('blog.urls')),
    path('library/', include('library.urls')),
    path('mirmir/', include('mirmir_app.urls')),
] + static(settings.STATIC_URL, document_root=settings.STATIC_ROOT) + static(settings.PROFILE_PIC_URL, document_root=settings.PROFILE_PIC_ROOT) + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

# handler404 = 'html_css.views.handler404'
# handler500 = 'html_css.views.handler500'
# handler403 = 'html_css.views.handler403'
# handler400 = 'html_css.views.handler400'
