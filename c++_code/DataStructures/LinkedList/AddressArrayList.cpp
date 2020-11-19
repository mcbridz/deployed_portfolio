//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "AddressArrayList.h"

#include <iostream>

using namespace std;


void printListRange(const ArrayList<Address>& list, int startIndex, int endIndex) {
    if(endIndex == -1)
        endIndex = list.listSize() - 1;
    for(int i = startIndex; i <= endIndex; i++) {
        cout << list.retrieveAt(i);
    }
}


template <>
void ArrayList<Address>::combine(ArrayList<Address>& otherList) {
    int otherLength = otherList.length;
    for(int i = 0; i< otherLength; i++){
        insertEnd(otherList.retrieveAt(0));
        otherList.removeAt(0);
    }
}


template <>
ArrayList<Address> ArrayList<Address>::extractAllMatches(const Address& itemToMatch) {
    ArrayList<Address> output;
    for(int i = 0; i < length; i++){
        if(retrieveAt(i).state == itemToMatch.state){
            output.insertEnd(retrieveAt(i));
            removeAt(i);
            i--;
        }
    }
    return output;
}
