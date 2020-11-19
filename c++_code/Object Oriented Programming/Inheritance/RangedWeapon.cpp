#include "RangedWeapon.h"
#include <iostream>

using namespace std;

RangedWeapon::RangedWeapon(std::string name, int damageValue, int rangeValue, int ammoValue, int cost) : Weapon (name, damageValue, cost)
{
    range = rangeValue;
    ammo = ammoValue;
}
std::string RangedWeapon::toString(){
    string output = Item::toString();
    output.append(" Damage: ");
    output.append(to_string(getDamage()));
    output.append(" Ammo: ");
    output.append(to_string(getAmmo()));
    output.append(" Range: ");
    output.append(to_string(getRange()));
    return output;
}
int RangedWeapon::getRange(){
    return range;
}
int RangedWeapon::getAmmo() const{
    return ammo;
}
int RangedWeapon::use(int rangeToTarget){
    int output = 0;
    if (ammo == 0){
        return output;
    }else
        if (rangeToTarget > range){
        ammo--;
        return output;
    }else{
        ammo--;
        output = Weapon::getDamage();
        return output;
    }
}

