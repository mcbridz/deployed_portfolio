/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#include "TwoInputGate.h"
#include <iostream>

using namespace std;

TwoInputGate::TwoInputGate(LogicOperation newType){
    gateType = newType;
    input1 = nullptr;
    input2 = nullptr;
}
void TwoInputGate::setInput1(std::shared_ptr<Component> input){
    input1 = input;
}
void TwoInputGate::setInput2(std::shared_ptr<Component> input){
    input2 = input;
}
bool TwoInputGate::getOutput() const{
    if(gateType == AND){
        if(input1->getOutput() && input2->getOutput()){
            return true;
        }else{
            return false;
        }
    }
    if(gateType == OR){
        if(input1->getOutput() || input2->getOutput()){
            return true;
        }else{
            return false;
        }
    }
    else{
        if(input1->getOutput()){
            if(!input2->getOutput()){
                return true;
            }else{
                return false;
            }
        }
        else{
            if(!input1->getOutput() && input2->getOutput()){
                return true;
            }else{
                return false;
            }
        }
    }
}
void TwoInputGate::setType(LogicOperation type){
    gateType = type;
}
void TwoInputGate::linearPrint() const{
    string joiner;
    if(gateType == AND){
        joiner = "&&";
    }else if(gateType == OR){
        joiner = "||";
    }else{
        joiner = "^";
    }
    cout << "(";
    input1->linearPrint();
    cout << " " << joiner << " ";
    input2->linearPrint();
    cout << ")";
}
stringstream TwoInputGate::linearPrintStream() const{
    string joiner;
    if(gateType == AND){
        joiner = "&&";
    }else if(gateType == OR){
        joiner = "||";
    }else{
        joiner = "^";
    }
    stringstream a1 = input1->linearPrintStream();
    stringstream a2 = input2->linearPrintStream();
    string output = "(";
    output += a1.str();
    output += " ";
    output += joiner;
    output += " ";
    output += a2.str();
    output += ")";
    stringstream finalOutput;
    finalOutput << output;
    return finalOutput;
}
void TwoInputGate::prettyPrint(std::string pad) const{
    string joiner;
    if(gateType == AND){
        joiner = "AND";
    }else if(gateType == OR){
        joiner = "OR";
    }else{
        joiner = "XOR";
    }
    cout << pad;
    cout << joiner << endl;
    pad += "--";
    input1->prettyPrint(pad);
    cout << endl;
    input2->prettyPrint(pad);
    cout << endl;
}
