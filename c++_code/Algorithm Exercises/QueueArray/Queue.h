#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

const int QUEUE_INIT_SIZE = 8;

template <class T>
class Queue {
private:
    T *list;          //array to hold the list elements
    int arraySize;    //capacity of array used for storage

    int start;      //index of the head of the queue
    int end;        //index of the tail of the queue

    //Helper function to add additional space
    void grow();

public:
    void enqueue(const T& value);
    T dequeue();
    bool empty() const;
    bool full() const;

    Queue();

    ~Queue();

    //Disable copy ctor and assignment to avoid accidental use
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);


    //Defined inside class to avoid template/friend ugliness
    friend ostream& operator<<(ostream& os, Queue<T>& theQueue) {
        os << "Start: " << theQueue.start << " End: " << theQueue.end << " arraySize: " << theQueue.arraySize << endl;

        int length = theQueue.end - theQueue.start;
        bool wrapped = false;       //does queue wrap wround back of array?
        if(length < 0)
            wrapped = true;

        for(int i = 0; i < theQueue.arraySize; i++) {
            if( (wrapped && (i < theQueue.end || i >= theQueue.start)) ||
                    (!wrapped && (i < theQueue.end && i >= theQueue.start)) )
                os << theQueue.list[i] << " ";
            else
                os << "_ ";
        }
        cout << endl;
        return os;
    }
};


template <class T>
void Queue<T>::enqueue(const T& value) {
    if( full() ) {
        grow();
    }
    list[end] = value;
    if(end == arraySize - 1){
        end = 0;
    }else{
        end++;
    }
}

template <class T>
T Queue<T>::dequeue() {
    if( empty() ) {
        throw out_of_range("Dequeue on empty queue");
    }
    T output = list[start];
    if(start != arraySize - 1){
        start++;
    }else{
        start = 0;
    }
    return output;
}


template <class T>
bool Queue<T>::empty() const {
    if(start == end && (start != 0 && end != 0))
        return true;
    else
        return false;
}


template <class T>
bool Queue<T>::full() const {

    if(start == end + 1 || (start == 0 && end == arraySize - 1)){
        return true;
    }else{
        return false;
    }
}

template <class T>
void Queue<T>::grow() {
    T * temp;
    temp = new T[arraySize];
    for(int i = 0; i < arraySize - 1; i++){
        temp[i] = dequeue();
    }
    delete [] list;
    list = new T[arraySize * 2];
    for(int i = 0; i < arraySize; i++){
        list[i] = temp[i];
    }
    start = 0;
    end = arraySize - 1;
    arraySize = arraySize * 2;
    delete [] temp;
}






///-------------------Constructors/Destructor----------------
template <class T>
Queue<T>::Queue() {
    arraySize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    list = new T[arraySize];
}

template <class T>
Queue<T>::~Queue() {
    delete [] list;
}


#endif // QUEUE_H

