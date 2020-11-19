#include "Item.h"
#include "Armor.h"
#include <string>
#include <iostream>

using namespace std;

Armor::Armor(std::string name, int protectionValue, int cost) : Item (name, cost){
    protection = protectionValue;
}

int Armor::getProtection(){
    return protection;
}

string Armor::toString() {
    string output = Item::toString();
    output.append(" Protection: ");
    output.append(to_string(getProtection()));
    return output;
}
