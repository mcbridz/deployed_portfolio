# Generated by Django 3.1.1 on 2020-11-19 21:32

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('blog', '0002_auto_20201118_1512'),
    ]

    operations = [
        migrations.AlterField(
            model_name='userprofile',
            name='login_name',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, related_name='profile_ref', to=settings.AUTH_USER_MODEL),
        ),
    ]
