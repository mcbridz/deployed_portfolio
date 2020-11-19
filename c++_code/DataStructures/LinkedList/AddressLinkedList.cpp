//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "AddressLinkedList.h"
#include <iostream>

AddressListNode::AddressListNode() {
    next = nullptr;
    //data will be default initialized
}

AddressListNode::AddressListNode(const Address& value)
    : data(value)
{
    next = nullptr;
}

AddressListNode::~AddressListNode(){
}

AddressLinkedList::AddressLinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

AddressLinkedList::~AddressLinkedList(){
    while(head != nullptr){
        removeFirst();
    }
}

Address AddressLinkedList::removeFirst(){
    if(head== nullptr){
        return Address();
    }
    Address output = head->data;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        AddressListNode* current = head;
        head = head->next;
        delete current;
    }
    length--;
    return output;
}

void AddressLinkedList::insertEnd(const Address& value){
    AddressListNode* temp = new AddressListNode(value);
    if(head == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
    length++;
}

Address AddressLinkedList::retrieveAt(int index) const{
    AddressListNode* current = head;
    for(int i=1; i<index; i++){
        current = current->next;
    }
    return current->data;
}

void AddressLinkedList::printRange(int startIndex, int endIndex) const{
    AddressListNode* current = head;
    for(int i=1; i< startIndex; i++){
        current = current->next;
    }
    for(int i = 0; i<=(endIndex - startIndex); i++){
        Address temp = current->data;
        std::cout << temp;
        current = current->next;
    }
}
void AddressLinkedList::combine(AddressLinkedList& other){
    tail->next = other.head;
    tail = other.tail;
    length+= other.length;
    other.length = 0;
    other.head = nullptr;
    other.tail = nullptr;
}

int AddressLinkedList::listSize() const{
    return length;
}

AddressLinkedList AddressLinkedList::extractAllMatches(const Address& itemToMatch){
    //This is a very large function, a bit larger than I would like, but there are many different
    //special cases for this function. Empty list differences and first/last matches. The function
    //conserves data, and prevents wasteful use of new and delete. This function is fast.
    std::string match = itemToMatch.state;
    AddressLinkedList output;
    if(head == nullptr){
        return output;
    }
    AddressListNode* current = head;
    //special case, head matches continuous
    while(current->data.state == match && head == current){
        if(output.head == nullptr){
            output.head = current;
            head = head->next;
            current = current->next;
            output.tail = current;
            output.tail->next = nullptr;
            output.length++;
            length--;
        }else{
            output.tail->next = current;
            output.tail = current;
            head = head->next;
            current = current->next;
            output.tail->next = nullptr;
            output.length++;
            length--;
        }
    }
    //now iterating normally, current is not a match, excluding last match case
    while(current->next->next != nullptr){
        if(current->next->data.state == match && output.head == nullptr){
            output.head = current->next;
            output.tail = output.head;
            current->next = output.tail->next;
            output.tail->next = nullptr;
            length--;
            output.length++;
        }else if(current->next->data.state == match){
            output.tail->next = current->next;
            output.tail = current->next;
            current->next = output.tail->next;
            output.tail->next = nullptr;
            length--;
            output.length++;
        }
        current = current->next;
    }
    //last match case empty output
    if(current->next->data.state == match && output.head == nullptr){
        output.head = current->next;
        output.tail = current->next;
        tail = current;
        current->next = nullptr;
    }else if(current->next->data.state == match){
        //last match case no empty output
        if(output.head != nullptr){
            output.tail->next = current->next;
            output.tail = current->next;
            tail = current;
            current->next = nullptr;
            length--;
            output.length++;
        }
    }
    return output;
}
void AddressLinkedList::interleave(AddressLinkedList& other){
    if(head == nullptr && other.head != nullptr){
        head = other.head;
        tail = other.tail;
        length = other.length;
        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
    }else if((head != nullptr && other.head == nullptr) || (head == nullptr && other.head == nullptr)){
        return;
    }
    AddressListNode* this1 = head;
    while(this1->next != nullptr){
        if(other.head != nullptr){
            AddressListNode* temp = other.head;
            other.head = other.head->next;
            temp->next = this1->next;
            this1->next = temp;
            length++;
            other.length--;
            this1 = this1->next->next;
        }
    }
    if(this1->next == nullptr && other.head->next == nullptr){
        this1->next = other.head;
        length++;
        other.length--;
        other.head = nullptr;
        other.tail = nullptr;
    }
}
