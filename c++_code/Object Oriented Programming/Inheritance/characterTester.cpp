/**
  * Tests Character - do not use until Armor and Weapon are working.
  */

//Bring in unit testing code
#include "catch.hpp"

#include <iostream>
using namespace std;

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "RangedWeapon.h"
#include "Character.h"

TEST_CASE( "Character equip weapons" ) {
    cout << "Running Character equip weapons..." << endl;

    Character c("Link");
    Weapon w("Mace", 4, 20);
    c.aquire(&w);
    c.equip(0); //know that the mace is in slot 0

    Weapon* wptr = c.getWeapon();
    CHECK(wptr->getName() == "Mace");


    RangedWeapon w2("Bow", 3, 10, 20, 30);
    c.aquire(&w2);
    c.equip(1); //know that the bow is in slot 1

    Weapon* wptr2 = &w2;
    CHECK(wptr2->getName() == "Bow");
    CHECK(wptr2->getRange() == 10);
}

TEST_CASE( "Character equip armor" ) {
    cout << "Running Character equip armor..." << endl;

    Character c("Link");

    Armor a("Mail vest", 4, 40);
    c.aquire(&a);
    c.equip(0); //know that the mail is in slot 0
    Item* iptr = &a;

    Armor* aptr = c.getArmor();
    CHECK(aptr->getName() == "Mail vest");
}

TEST_CASE( "Character equip invalid" ) {
    cout << "Running Character equip invalid..." << endl;

    Character c("Link");

    Item i("Silver vase", 50);
    c.aquire(&i);
    c.equip(0); //know that the vase is in slot 0, nothing should happen if we try to equip

    c.equip(1); //know that 1 is null, nothing should happen if we try to equip

    //Verify armor and weapon did not change
    Weapon* wptr = c.getWeapon();
    CHECK(wptr->getName() == "Bare Hands");

    Armor* aptr = c.getArmor();
    CHECK(aptr->getName() == "Skin");
}



