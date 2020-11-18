from django.core.management.base import BaseCommand
from django.shortcuts import get_object_or_404
from ...models import Pokemon, PokemonType
import json


class Command(BaseCommand):
    def handle(self, *args, **options):
        tmp_poketypes = PokemonType.objects.all()
        for poketype in tmp_poketypes:
            poketype.delete()
        tmp_pokemons = Pokemon.objects.all()
        for pokemon in tmp_pokemons:
            pokemon.delete()
        print('Starting load_pokemon.py')
        with open('./pokedex/management/commands/pokemon.json', 'r', encoding='utf-8') as pokejson:
            pokedata = pokejson.read()
            pokedict = json.loads(pokedata)
            pokedict = pokedict['pokemon']
            # handle poketypes
            poketypes = []
            for pokemon in pokedict:
                tmp_poketypes = pokemon['types']
                for poketype in tmp_poketypes:
                    if poketype not in poketypes:
                        poketypes.append(poketype)
            print(poketypes)
            for poketype in poketypes:
                tmp_poketype = PokemonType(name=poketype)
                tmp_poketype.save()
            # handle pokemon
            for pokemon in pokedict:
                if pokemon['image_front'] is None:
                    pokemon['image_front'] = 'http://placekitten.com/96/96'
                if pokemon['image_back'] is None:
                    pokemon['image_back'] = 'http://placekitten.com/96/96'
                tmp_pokemon = Pokemon(name=pokemon['name'], number=pokemon['number'], height=pokemon['height']/10,
                                      weight=pokemon['weight']/10, image_front=pokemon['image_front'], image_back=pokemon['image_back'])
                tmp_pokemon.save()
                for poketype in pokemon['types']:
                    tmp_poketype = get_object_or_404(
                        PokemonType, name=poketype)
                    # print(tmp_poketype)
                    tmp_pokemon.types.add(tmp_poketype)
                tmp_pokemon.save()
