# Generated by Django 3.1.1 on 2020-11-19 21:32

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='CarouselSlide',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('image', models.ImageField(blank=True, null=True, upload_to='carousel_images')),
                ('caption_title', models.CharField(blank=True, max_length=100, null=True)),
                ('caption', models.CharField(blank=True, max_length=100, null=True)),
                ('display_order', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'ordering': ['display_order'],
            },
        ),
        migrations.CreateModel(
            name='Contact',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('first_name', models.CharField(max_length=50)),
                ('last_name', models.CharField(max_length=50)),
                ('company', models.CharField(blank=True, max_length=255)),
                ('city', models.CharField(blank=True, max_length=50, null=True)),
                ('state_code', models.CharField(blank=True, max_length=50, null=True)),
                ('zip_code', models.CharField(blank=True, max_length=50, null=True)),
                ('main_phone', models.CharField(blank=True, max_length=50, null=True)),
                ('email', models.CharField(max_length=100)),
                ('birthday', models.DateField()),
                ('email_address_confirmed', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='MainPageHighlight',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('image', models.ImageField(blank=True, null=True, upload_to='highlight_images')),
                ('text', models.TextField(blank=True, null=True)),
            ],
        ),
        migrations.CreateModel(
            name='MainPageWarning',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('text', models.CharField(max_length=255)),
                ('show_warning', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='Order',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('order_number', models.IntegerField()),
                ('order_date', models.DateField(auto_now_add=True)),
                ('billing_birthdate', models.DateField(blank=True)),
                ('billing_first_name', models.CharField(max_length=50)),
                ('billing_last_name', models.CharField(max_length=50)),
                ('billing_company', models.CharField(blank=True, max_length=100)),
                ('billing_address', models.CharField(max_length=100)),
                ('billing_address2', models.CharField(blank=True, max_length=100)),
                ('billing_city', models.CharField(max_length=50)),
                ('billing_state_code', models.CharField(max_length=4)),
                ('billing_zip_code', models.IntegerField()),
                ('billing_email', models.EmailField(default='mirmirswellmeadery@gmail.com', max_length=100)),
                ('shipping_birthdate', models.DateField(blank=True)),
                ('shipping_first_name', models.CharField(blank=True, max_length=50)),
                ('shipping_last_name', models.CharField(blank=True, max_length=50)),
                ('shipping_company', models.CharField(blank=True, max_length=100)),
                ('shipping_address', models.CharField(blank=True, max_length=100)),
                ('shipping_address2', models.CharField(blank=True, max_length=100)),
                ('shipping_city', models.CharField(blank=True, max_length=50)),
                ('shipping_state_code', models.CharField(blank=True, max_length=4)),
                ('shipping_zip_code', models.IntegerField(blank=True)),
                ('gift_message', models.CharField(blank=True, max_length=1024)),
                ('sub_total', models.FloatField(default=0.0)),
                ('order_notes', models.CharField(blank=True, max_length=1024)),
                ('handling', models.FloatField(default=0.0)),
                ('shipping', models.FloatField(default=0.0)),
                ('tax', models.FloatField(default=0.0)),
                ('total', models.FloatField(default=0.0)),
                ('previous_order_number', models.IntegerField(blank=True)),
                ('is_pickup', models.BooleanField(default=False)),
                ('is_paid', models.BooleanField(default=False)),
                ('shipping_service', models.CharField(blank=True, max_length=100)),
                ('shipping_tracking_number', models.CharField(blank=True, max_length=200)),
                ('contact', models.ForeignKey(null=True, on_delete=django.db.models.deletion.PROTECT, related_name='orders', to='mirmir_app.contact')),
            ],
            options={
                'ordering': ['-order_date'],
            },
        ),
        migrations.CreateModel(
            name='OrderType',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('type_string', models.CharField(max_length=50)),
                ('pretty_type', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='PaymentStatus',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('status', models.CharField(max_length=50)),
                ('pretty_status', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='Product',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('product_type', models.CharField(default='Product', max_length=50)),
                ('title', models.CharField(max_length=255)),
                ('POSTitle', models.CharField(max_length=50)),
                ('brand', models.CharField(default="Mirmir's Well Meadery", max_length=255)),
                ('subtitle', models.CharField(blank=True, max_length=50, null=True)),
                ('action_message', models.CharField(blank=True, max_length=255, null=True)),
                ('is_active', models.BooleanField(default=True)),
                ('is_display_on_website', models.BooleanField(default=True)),
                ('description', models.TextField()),
                ('description_teaser', models.CharField(blank=True, max_length=255)),
                ('date_added', models.DateField(auto_now_add=True)),
                ('date_modified', models.DateField(blank=True, null=True)),
                ('SKU_SKU', models.CharField(max_length=50)),
                ('SKU_cost_of_good', models.FloatField()),
                ('SKU_UPC_code', models.CharField(max_length=255)),
                ('SKU_unit_description', models.CharField(max_length=255)),
                ('SKU_min_order_qty', models.IntegerField()),
                ('SKU_max_order_qty', models.IntegerField()),
                ('SKU_order_in_multiples_of', models.IntegerField()),
                ('SKU_weight', models.IntegerField()),
                ('SKU_is_non_taxable', models.BooleanField(default=False)),
                ('SKU_is_no_shipping_charge', models.BooleanField(default=False)),
                ('SKU_Prices_price_level', models.CharField(max_length=50)),
                ('SKU_Prices_price', models.FloatField()),
                ('SKU_Prices_price_quantity', models.IntegerField()),
                ('SKU_Prices_is_inventory_on', models.BooleanField(default=True)),
                ('SKU_Prices_Inventory_current_inventory', models.IntegerField()),
                ('SKU_Prices_Inventory_inventory_pool', models.IntegerField()),
                ('WineProperties_bottles_in_case', models.IntegerField(blank=True, null=True)),
                ('WineProperties_bottle_size_in_ml', models.IntegerField()),
                ('WineProperties_type', models.CharField(blank=True, max_length=50, null=True)),
                ('WineProperties_alcohol', models.CharField(max_length=255)),
                ('WineProperties_bottling_date', models.DateField()),
                ('WineProperties_tasting_notes', models.TextField(blank=True, null=True)),
                ('WineProperties_wine_maker_notes', models.TextField(blank=True, null=True)),
                ('WineProperties_food_pairing_notes', models.TextField(blank=True, null=True)),
            ],
        ),
        migrations.CreateModel(
            name='ShippingStatus',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('status', models.CharField(max_length=50)),
                ('pretty_status', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='SortField',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=50)),
                ('pretty_name', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='StatusField',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('status', models.CharField(max_length=50)),
                ('pretty_status', models.CharField(blank=True, max_length=50, null=True)),
            ],
        ),
        migrations.CreateModel(
            name='TransactionType',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('t_type', models.CharField(max_length=50)),
                ('pretty_t_type', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='ProductPhoto',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('photo', models.ImageField(upload_to='product_images')),
                ('photo_image_number', models.IntegerField()),
                ('product', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='product_photos', to='mirmir_app.product')),
            ],
            options={
                'ordering': ['photo_image_number'],
            },
        ),
        migrations.CreateModel(
            name='OrderItemQuantity',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('quantity', models.IntegerField()),
                ('order', models.ForeignKey(blank=True, on_delete=django.db.models.deletion.CASCADE, related_name='items', to='mirmir_app.order')),
                ('product', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='order_items', to='mirmir_app.product')),
            ],
        ),
        migrations.AddField(
            model_name='order',
            name='order_type',
            field=models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='orders', to='mirmir_app.ordertype'),
        ),
        migrations.AddField(
            model_name='order',
            name='payment_status',
            field=models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='orders', to='mirmir_app.paymentstatus'),
        ),
        migrations.AddField(
            model_name='order',
            name='shipping_status',
            field=models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='orders', to='mirmir_app.shippingstatus'),
        ),
        migrations.AddField(
            model_name='order',
            name='transaction_type',
            field=models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='orders', to='mirmir_app.transactiontype'),
        ),
        migrations.CreateModel(
            name='EmailConfirmation',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('code', models.CharField(max_length=10)),
                ('date_created', models.DateTimeField(auto_now_add=True)),
                ('date_confirmed', models.DateTimeField(blank=True, null=True)),
                ('contact', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='email_confirmations', to='mirmir_app.contact')),
            ],
        ),
        migrations.AddField(
            model_name='contact',
            name='status',
            field=models.ForeignKey(default=2, on_delete=django.db.models.deletion.PROTECT, related_name='profile', to='mirmir_app.statusfield'),
        ),
        migrations.AddField(
            model_name='contact',
            name='username',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, related_name='profile', to=settings.AUTH_USER_MODEL),
        ),
    ]
