/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#include "Pin.h"
#include <iostream>

using namespace std;

Pin::Pin(string newLabel){
    value = false;
    this->label = newLabel;
}
Pin::~Pin(){}
bool Pin::getOutput() const {
    return value;
}
void Pin::setValue(bool set) {
    value = set;
}
void Pin::linearPrint() const {
    cout << label;
}
stringstream Pin::linearPrintStream() const{
    stringstream output;
    output << label;
    return output;
}
void Pin::prettyPrint(string padding) const{
    cout << padding << label << " : " << value;
}
