//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>
#include <string>
//Node node for Set
template <class T>
struct SetNode
{
    T data;
    SetNode<T>* left;
    SetNode<T>* right;

    SetNode(const T& value);
};


//Set based on a BST
template <class T>
class MySet
{
private:
    SetNode<T>* root;

public:
    //Construct empty set
    MySet();

    //Copy constructor
    MySet(const MySet<T>& other);

    //Assignment operator - implement if needed
    MySet<T>& operator=(const MySet<T>& other);

    //Destructor
    ~MySet();

    //get number of items contained
    int size() const;

    //get depth of underlying tree
    int depth() const;

    //Add item to set
    //  Do not add duplicates of existing items - ignore any duplicate add
    void add(const T& item);

    //Check if item is in the set
    bool contains(const T& item) const;

    //Remove given item from the set if it exists
    void remove(const T& item);

    //returns the smallest item from the set (does not remove it)
    T getSmallest() const;

    //removes the largest item from the set and returns it
    T removeLargest();

    //Generates a new set containing all the items that are in either
    //  this set or another set
    //  intersections of {A, B, C, D} and {B, D, F} would be {A, B, C, D, F}
    //  Both original sets are left unmodified
    MySet<T> unionWith(const MySet<T>& other) const;

    //Generates a new set containing all the items that are in both
    //  this set and another set
    //  intersections of {A, B, C, D} and {B, D, F} would be {B, D}
    //  Both original sets are left unmodified
    MySet<T> intersectionWith(const MySet<T>& other) const;

    //Returns a vector of items in the set that are >= start and < end
    std::vector<T> getRange(const T& startValue, const T& endValue) const;

    void printSubTree(SetNode<T>* current) const;
    void printWholeTree() const;
    SetNode<T>* getLocalIPs(SetNode<T>* current, std::vector<T>& output, std::string bottomRange = "192.168.000.000", std::string topRange = "192.168.254.254");
    void getLocalIPsStarter(std::vector<T>& output);
    std::vector<T> toVector(SetNode<T>* current) const;
    void unionHelper(SetNode<T>* current, MySet<T>& output) const;
};


//--------------------------------------------------------------------
// SetNode implementations
//--------------------------------------------------------------------

template <class T>
SetNode<T>::SetNode(const T& value)
    : data(value)
{
    left = nullptr;
    right = nullptr;
}

//--------------------------------------------------------------------
// Set Implementations
//--------------------------------------------------------------------

template <class T>
MySet<T>::MySet(){
    root = nullptr;
}
template <class T>
SetNode<T>* copySubTree(SetNode<T>* current){
    if(current == nullptr){
        return nullptr;
    }else{
        SetNode<T>* newNode = new SetNode<T>(current->data);
        newNode->left = copySubTree(current->left);
        newNode->right = copySubTree(current->right);
        return newNode;
    }
}
template <class T>
MySet<T>::MySet(const MySet<T>& other){
    root = copySubTree(other.root);
}

template <class T>
int sizeHelper(SetNode<T>* current, int& output){
    if (current != nullptr){
        output++;
        sizeHelper(current->left, output);
        sizeHelper(current->right, output);
    }
    return output;
}
template <class T>
int MySet<T>::size() const{
    if(root != nullptr){
        int output = 0;
        output = sizeHelper(root, output);
        return output;
    }else{
        return 0;
    }
}
template <class T>
int depthHelper(SetNode<T>* current){
    int leftHeight = 0;
    int rightHeight = 0;
    if(current->left != nullptr){
        leftHeight++;
        leftHeight += depthHelper(current->left);
    }
    if(current->right != nullptr){
        rightHeight++;
        rightHeight += depthHelper(current->right);
    }
    if(leftHeight >= rightHeight){
        return leftHeight;
    }else{
        return rightHeight;
    }
}
template <class T>
int MySet<T>::depth() const{
    if(root == nullptr){
        return 0;
    }else{
        return 1 + depthHelper(root);
    }
}
template <class T>
void MySet<T>::add(const T& item){
    if(root == nullptr){
        root = new SetNode<T>(item);
    }else{
        SetNode<T>* parent = root;
        SetNode<T>* current = root;
        do{
            parent = current;
            if(item < current->data){
                current = current->left;
            }else if(item > current->data){
                current = current->right;
            }else{
                return;
            }
        }
        while(current != nullptr);
        if(item < parent->data){
            parent->left = new SetNode<T>(item);
        }else if(item > parent->data){
            parent->right = new SetNode<T>(item);
        }
    }
}
template <class T>
void deleteSubTree(SetNode<T>* current){
    if(current == nullptr){
        return;
    }else{
        deleteSubTree(current->left);
        deleteSubTree(current->right);
        delete current;
    }
}
template <class T>
MySet<T>::~MySet<T>(){
    deleteSubTree(root);
}
template <class T>
void MySet<T>::printSubTree(SetNode<T>* current) const{
    if(current->left != nullptr){
        printSubTree(current->left);
    }
    std::cout << current->data << "     ";
    if(current->right != nullptr){
        printSubTree(current->right);
    }
}
template <class T>
void MySet<T>::printWholeTree() const{
    printSubTree(root);
}
template <class T>
T MySet<T>::getSmallest() const{
    if(root == nullptr){
        return "Empty tree.";
    }
    SetNode<T>* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current->data;
}
template <class T>
T getSmallestFromSubTree(SetNode<T>* current){
    if(current == nullptr){
        return "Empty Tree.";
    }
    while(current->left != nullptr){
        current = current->left;
    }
    return current->data;

}
template <class T>
SetNode<T>* removeHelper(SetNode<T>* current, T value){
    if(current == nullptr){
        return nullptr;
    }else if(value < current->data){
        current->left = removeHelper(current->left, value);
    }else if(value > current->data){
        current->right = removeHelper(current->right, value);
    }else{
        if(current->right == nullptr){
            SetNode<T>* temp = current->left;
            delete current;
            return temp;
        }
        if(current->left == nullptr){
            SetNode<T>* temp = current->right;
            delete current;
            return temp;
        }
        current->data = getSmallestFromSubTree(current->right);
        current->right = removeHelper(current->right, current->data);
        return current;
    }
    return current;
}
template <class T>
void MySet<T>::remove(const T& item){
    root = removeHelper(root, item);
}
template <class T>
T MySet<T>::removeLargest(){
    SetNode<T>* current = root;
    SetNode<T>* parent = root;
    while(current->right != nullptr){
        parent = current;
        current = current->right;
    }
    T output = current->data;
    if(current->left == nullptr){
        delete current;
        parent->right = nullptr;
    }else{
        SetNode<T>* temp = current->left;
        delete current;
        parent->right = temp;
    }
    return output;
}
template <class T>
SetNode<T>* MySet<T>::getLocalIPs(SetNode<T>* current, std::vector<T>& output, std::string bottomRange, std::string topRange){
    if(current == nullptr){
        return nullptr;
    }
    current->left = getLocalIPs(current->left, output, bottomRange, topRange);
    current->right = getLocalIPs(current->right, output, bottomRange, topRange);
    if(current->data >= bottomRange && current->data <= topRange){
        output.push_back(current->data);
        if(current->right == nullptr){
            SetNode<T>* temp = current->left;
            delete current;
            return temp;
        }
        if(current->left == nullptr){
            SetNode<T>* temp = current->right;
            delete current;
            return temp;
        }
        current->data = getSmallestFromSubTree(current->right);
        current->right = removeHelper(current->right, current->data);
        return current;
    }
    return current;
}
template <class T>
void MySet<T>::getLocalIPsStarter(std::vector<T>& output){
    getLocalIPs(root, output);
}
template <class T>
void setTraversalIntersection(MySet<T>& output, const MySet<T>& second, SetNode<T>* current) {
    if(current == nullptr){
        return;
    }else{
        if(second.contains(current->data)){
            output.add(current->data);
        }
        setTraversalIntersection(output, second, current->left);
        setTraversalIntersection(output, second, current->right);
    }
}
template <class T>
MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const{
    MySet<T> output;
    if(root != nullptr){
        setTraversalIntersection(output, other, root);
    }
    return output;
}
template <class T>
bool MySet<T>::contains(const T& item) const{
    SetNode<T>* current = root;
    while(current != nullptr){
        if(item < current->data){
            current = current->left;
        }else if(item > current->data){
            current = current->right;
        }else if(item == current->data){
            return true;
        }
    }
    return false;
}
template <class T>
void MySet<T>::unionHelper(SetNode<T>* current, MySet<T>& output) const{
    if(current == nullptr){
        return;
    }else{
        output.add(current->data);
        unionHelper(current->left, output);
        unionHelper(current->right, output);
    }
}
template <class T>
MySet<T> MySet<T>::unionWith(const MySet<T>& other) const{
    MySet<T> output;
    SetNode<T>* firstCurrent = root;
    SetNode<T>* secondCurrent = other.root;
    unionHelper(firstCurrent, output);
    unionHelper(secondCurrent, output);
    return output;
}
template <class T>
void getRangeHelper(const T& startValue, const T& endValue, std::vector<T>& vector, SetNode<T>* current){
    if(current == nullptr){
        return;
    }
    getRangeHelper(startValue, endValue, vector, current->left);
    getRangeHelper(startValue, endValue, vector, current->right);
    if(current->data >= startValue && current->data < endValue){
        vector.push_back(current->data);
        return;
    }
}
template <class T>
std::vector<T> MySet<T>::getRange(const T& startValue, const T& endValue) const{
    std::vector<T> output;
    getRangeHelper(startValue, endValue, output, root);
    return output;
}
#endif // MYSET_H
