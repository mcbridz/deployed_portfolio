/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#include "NotGate.h"
#include <iostream>

using namespace std;

NotGate::NotGate(){
    input = nullptr;
}
void NotGate::setInput(shared_ptr<Component> in){
    input = in;
}
bool NotGate::getOutput() const {
    return !input->getOutput();
}
void NotGate::linearPrint() const{
    cout << "~(";
    input->linearPrint();
    cout << ")";
}
stringstream NotGate::linearPrintStream() const{
    stringstream output;
    output << "~(";
    stringstream output2;
    output2 = input->linearPrintStream();
    string temp = output.str();
    temp += output2.str();
    temp += ")";
    stringstream finalOutput;
    finalOutput << temp;
    return finalOutput;
}
void NotGate::prettyPrint(std::string padding) const{
    cout << padding << "NOT" << endl;
    padding += "--";
    input->prettyPrint(padding);
}
