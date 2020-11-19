#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item (std::string name, int cost){
    this->name = name;
    value = cost;
}

string Item::getName() const{
    return name;
}

int Item::getValue() const{
    return value;
}

string Item::toString(){
    string output = name;
    output.append(" (value: ");
    output.append(to_string(value));
    output.append(")");
    return output;
}
