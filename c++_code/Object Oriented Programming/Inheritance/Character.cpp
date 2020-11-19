#include <iostream>
#include <cassert>


#include "Character.h"

using namespace std;


Character::Character(const std::string& nameVal)
{
    name = nameVal;
    healthPoints = 100;

    //point to our built in armor/weapon
    weapon = &hands;
    armor = &skin;
}

void Character::print() const
{
    cout << name << endl;
    cout << "Health: " << healthPoints << endl;
    cout << "Armor: " << armor->toString() << endl;
    cout << "Weapon: " << weapon->toString() << endl;
    cout << "Inventory: " << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << "[" << i << "] " << inventory[i]->toString() << endl;
        }
    }
    cout << "-----------------------------------" << endl;
}


int Character::getHealthPoints() const
{
    return healthPoints;
}

void Character::takeDamage(int amount)
{
    int damageAmount = amount - armor->getProtection();

    if(damageAmount < 0)
        damageAmount = 0;

    healthPoints -= damageAmount;
    if(healthPoints < 0)
        healthPoints = 0;
}


void Character::attack(Character& target, int range)
{
    target.takeDamage( weapon->use(range) );
}

bool Character::aquire(Item* item)
{
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

void Character::equip(int itemNumber)
{
    if ((dynamic_cast<Weapon*>(inventory[itemNumber]) == nullptr) && (dynamic_cast<Armor*>(inventory[itemNumber]) == nullptr)){
        return;
    }else if (dynamic_cast<Armor*>(inventory[itemNumber]) == nullptr){
        Weapon* toEquip = dynamic_cast<Weapon*>(inventory[itemNumber]);
        weapon = toEquip;
    }else{
        Armor* toEquip = dynamic_cast<Armor*>(inventory[itemNumber]);
        armor = toEquip;
    }
}

Weapon* Character::getWeapon()
{
    return weapon;
}

Armor* Character::getArmor()
{
    return armor;
}
