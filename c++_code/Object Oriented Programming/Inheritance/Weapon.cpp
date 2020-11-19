#include "Weapon.h"
#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon (std::string name, int damageValue, int cost) : Item(name, cost){
    damage = damageValue;
}

string Weapon::toString(){
    string output = Item::toString();
    output.append(" Damage: ");
    output.append(to_string(getDamage()));
    return output;
}

int Weapon::getDamage() const{
    return damage;
}

int Weapon::getRange(){
    return 0;
}

int Weapon::use(int range){
    int output = 0;
    if (range != 0){
        return output;
    } else {
        output = damage;
        return output;
    }
}
