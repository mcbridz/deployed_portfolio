#include "CharBST.h"
#include <vector>
#include <iostream>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

void CharBST::deleteSubTree(BSTNode<char>* curNode) {
    if(curNode==nullptr){
        return;
    }else{
        deleteSubTree(curNode->left);
        deleteSubTree(curNode->right);
        BSTNode<char>* toBeDeleted = curNode;
        delete toBeDeleted;
    }
    return;
}

CharBST::~CharBST() {
    deleteSubTree(root);
}

void CharBST::insertFakeData() {
    if(root)            //delete any existing nodes
        delete root;

    root = new BSTNode<char>('G');
    root->left = new BSTNode<char>('C');
    root->left->right = new BSTNode<char>('F');
    root->right = new BSTNode<char>('P');
    root->right->right = new BSTNode<char>('Y');
    root->right->left = new BSTNode<char>('J');
}

///----------------------Print----------------------------
///Nonmember helper function
void printHelper(BSTNode<char>* curNode) {
    if(curNode == nullptr)
        return;

    printHelper(curNode->left);
    cout << curNode->value << " ";
    printHelper(curNode->right);
}

void CharBST::print() const {
    printHelper(root);
}


///----------------------Search---------------------------

bool containsHelper(BSTNode<char>* curNode, char valToFind) {
    if(curNode->value == valToFind){
        return true;
    }else if(valToFind > curNode->value && curNode->right != nullptr){
        containsHelper(curNode->right, valToFind);
    }else if(valToFind < curNode-> value && curNode->left != nullptr){
        containsHelper(curNode->left, valToFind);
    }else{
        return false;
    }
}

///recursive version
bool CharBST::containsRecursive(char valToFind) const {
    return containsHelper(root, valToFind);
}

///iterative version
bool CharBST::containsIterative(char valToFind) const {
    BSTNode<char>* current = root;
    if(current-> value == valToFind) return true;
    while(current!=nullptr){
        if(valToFind < current->value){
            current = current->left;
            if (current == nullptr) break;
            if(valToFind == current->value){
                return true;
            }
        }else if(valToFind > current->value){
            current = current->right;
            if (current == nullptr) break;
            if(valToFind == current->value){
                return true;
            }
        }
    }
    return false;
}

///----------------------insert---------------------------

BSTNode<char>* insertHelper(BSTNode<char>* curNode, char insertVal) {
    //TODO - fixme
    return new BSTNode<char>(insertVal);
}

void CharBST::insertRecursive(char insertVal) {
    root = insertHelper(root, insertVal);
}


void CharBST::insertIterative(char insertVal) {
    //TODO - fixme
    root = new BSTNode<char>(insertVal);
}

