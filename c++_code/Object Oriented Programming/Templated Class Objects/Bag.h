/*
  * @brief Assignment 6
   * @author Zachary McBride
  */
#ifndef BAG_H
#define BAG_H
#include <exception>
#include <ostream>
#include <iostream>
#include <time.h>
#include <math.h>

template<class T>
class Bag{
private:
    int numberOfObjects;
    T* contents;
    int capacity;
    void grow();
public:
    Bag();
    Bag(const Bag&);
    ~Bag();
    bool operator==(const Bag&);
    Bag<T>& operator=(const Bag&);
    void addItem(T);
    bool contains(const T&);
    void dump();
    bool isEmpty();
    bool removeItem(T);
    int numberOf(const T&);
    void removeAll(const T&);
    T& pickRandom();
    void dumpInto(Bag<T>&);
    Bag<T> extractAll(const T&);
    template<class R>
    friend std::ostream& operator<<(std::ostream& output, const Bag<R>& input);
};
template<typename T>
Bag<T>::Bag(){
    numberOfObjects = 0;
    contents = new T[10];
    capacity = 10;
}
template<typename T>
Bag<T>::Bag(const Bag& input){
    numberOfObjects = input.numberOfObjects;
    contents = new T[input.capacity];
    for (int i=0; i < numberOfObjects; i++){
        contents[i] = input.contents[i];
    }
    capacity = input.capacity;
}
template<typename T>
Bag<T>::~Bag<T>(){
    delete [] contents;
}
template<typename T>
Bag<T>& Bag<T>::operator=(const Bag& input){
    if(this == &input){
        return *this;
    }
    delete [] contents;
    numberOfObjects = input.numberOfObjects;
    contents = new T[input.capacity];
    capacity = input.capacity;
    for (int i=0; i < numberOfObjects; i++){
        contents[i] = input.contents[i];
    }
    return *this;
}
template<typename T>
bool Bag<T>::operator==(const Bag& input){
    if(this == &input){
        return true;
    }
    if(numberOfObjects == input.numberOfObjects){
        if(capacity == input.capacity){
            for (int i=0; i<numberOfObjects; i++){
                if (contents[i] != input.conents[i]){
                    return false;
                }
            }
        }
    }
    return true;
}
template<typename T>
void Bag<T>::grow(){
    T* temp = contents;
    capacity = capacity * 2;
    contents = new T[capacity];
    for (int i=0; i<numberOfObjects; i++){
        contents[i] = temp[i];
    }
    delete [] temp;
}
template<typename T>
void Bag<T>::addItem(T input){
    if (numberOfObjects >= capacity){
        grow();
    }
    contents[numberOfObjects] = input;
    numberOfObjects++;
}
template<typename T>
bool Bag<T>::contains(const T& check){
    for(int i=0; i<numberOfObjects; i++){
        if(contents[i] == check){
            return true;
        }
    }
    return false;
}
template<typename T>
void Bag<T>::dump(){
    delete [] contents;
    contents = new T[10];
    numberOfObjects = 0;
    capacity = 10;
}
template<typename T>
bool Bag<T>::isEmpty(){
    if(numberOfObjects == 0){
        return true;
    }
    return false;
}
template<typename T>
bool Bag<T>::removeItem(T remove){
    int whereIsIt = -1;
    for (int i=0; i<numberOfObjects; i++){
        if(contents[i] == remove){
            whereIsIt = i;
        }
    }

    int tempNumberOfObjects = numberOfObjects;
    if(whereIsIt == -1){
        return false;
    } else{
        T* temp = new T[capacity];
        for (int i=0; i<numberOfObjects; i++){
            temp[i] = contents[i];
        }
        int tempCapacity = capacity;
        delete [] contents;
        contents = new T[tempCapacity];
        capacity = tempCapacity;
        numberOfObjects = 0;
        for(int i=0; i < tempNumberOfObjects; i++){
            if(i!=whereIsIt){
                addItem(temp[i]);
            }
        }
        delete [] temp;
        return true;
    }
}
template<typename T>
int Bag<T>::numberOf(const T& check){
    int output = 0;
    for(int i=0;i<numberOfObjects;i++){
        if(contents[i] == check){
            output++;
        }
    }
    return output;
}
template<typename T>
void Bag<T>::removeAll(const T& remove){
    if(numberOfObjects == 0){
        throw std::logic_error("!");
    }
    while(numberOf(remove) != 0){
        Bag<T>::removeItem(remove);
    }
}
template<typename T>
T& Bag<T>::pickRandom(){
    for(int i=0;i<pow(10,6);i++) //comment this line for Dr. Memory! Timeout/hang will occur if not.
    srand(time(NULL));
    int director = rand() % (numberOfObjects);
    T temp=contents[director];
    T& output = temp;
    removeItem(contents[director]);
    return output;
}
template<typename T>
void Bag<T>::dumpInto(Bag<T>& input){
    for(int i=0;i<numberOfObjects;i++){
        input.addItem(contents[i]);
    }
    dump();
}
template<typename T>
Bag<T> Bag<T>::extractAll(const T &item){
    Bag<T> output;
    for (int i=0;i<numberOfObjects;i++){
        if(item == contents[i]){
            output.addItem(contents[i]);
            removeItem(contents[i]);
            i--;
        }
    }
    return output;
}
template<typename R>
std::ostream& operator<<(std::ostream& output, const Bag<R>& input){
    output << "{";
    for(int i=0; i<input.numberOfObjects; i++){
        output << input.contents[i];
        if(i < (input.numberOfObjects - 1)){
            output << ", ";
        }
    }
    output << "}";
    return output;
}
#endif // BAG_H
