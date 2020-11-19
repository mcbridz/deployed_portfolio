//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H
#include <exception>
#include <iostream>
/**
 * @brief Queue defined using array as ring
 */
const int defaultSize = 10;
template <class T>
class Queue
{
private:
    T* data;
    int start;
    int end;
    int dataSize;

    /**
     * @brief used to allocate a larger backing array when storage fills
     */
    void grow();

public:
    /**
     * @brief Construct empty stack
     */
    Queue();

    /**
     * @brief Copy constructor
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue(const Queue<T>& other);

    /**
     * @brief Assignment Operator
     *
     * Implement if you need it, otherwise not required
     * Declared to prevent default shallow copy
     */
    Queue<T>& operator=(const Queue<T>& other){
        delete [] data;
        dataSize = other.dataSize;
        data = new T[dataSize];
        for(int i=0; i<dataSize; i++){
            data[i] = other.data[i];
        }
        start = other.start;
        end = other.end;
    }

    /**
     * @brief Destructor
     */
    ~Queue();

    /**
     * @brief Check if queue is empty
     * @return true if nothing in the queue, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief add item to back of queue
     * @param value Item to add
     */
    void enqueue(const T& item);

    /**
     * @brief Remove and return front item from queue
     * @return Item that was at the front of the queue
     * Can throw exception/blow up with assertion if currently empty
     */
    T dequeue();

    /**
     * @brief Return a copy of the front item
     * @return Item that is at the front of the queue
     */
    T front() const;
    bool isFull() const;
    void print() const;
    void wordLadderPrint() const;
};

//--------------------------------------------------------------------
// Queue Implementations
//--------------------------------------------------------------------

template <class T>
Queue<T>::Queue(){
    data = new T[defaultSize];
    start = 0;
    end = 0;
    dataSize = defaultSize;
}
template <class T>
Queue<T>::Queue(const Queue<T>& other){
    data = new T[other.dataSize];
    dataSize = other.dataSize;
    for(int i=0; i<dataSize - 1; i++){
        data[i] = other.data[i];
    }
    start = other.start;
    end = other.end;
}
template <class T>
Queue<T>::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
    delete [] data;
}
template <class T>
void Queue<T>::grow(){
    T * newData;
    newData = new T[dataSize * 2];
    for(int i=0;i<dataSize;i++){
        newData[i] = dequeue();
    }
    delete [] data;
    data = newData;
    start = 0;
    end = dataSize - 1;
    dataSize = dataSize * 2;
}
template <class T>
bool Queue<T>::isEmpty() const{
    return (start == end);
}
template <class T>
bool Queue<T>::isFull() const{
    if((end == start - 1) || ((start == dataSize - 1) &&(end == 0)) || ((start == 0) && (end == dataSize - 1))){
        return true;
    }else{
        return false;
    }
}
template <class T>
void Queue<T>::enqueue(const T& item){
    if(isFull()){
        grow();
    }
    data[end] = item;
    if(end == dataSize - 1){
        end = 0;
    }else{
        end++;
    }
}
template <class T>
T Queue<T>::dequeue(){
    T output = data[start];
    if(start == dataSize - 1){
        start = 0;
    }else{
        start++;
    }
    return output;
}
template <class T>
T Queue<T>::front() const{
    return data[start];
}
template <class T>
void Queue<T>::print() const{
    std::cout << "//";
    for(int i=0;i<dataSize;i++){
        if(start < end){
            if((i < end) &&(i >= start)){
                std::cout << data[i];
            }
        }else if(end < start){
            if(i<end){
                std::cout << data[i] << " ";
            }else if(!((i>end)&&(i<=start))){
                std::cout << data[i];
            }
        }
    }
    std::cout << std::endl;
}
template <class T>
void Queue<T>::wordLadderPrint() const{
    for(int i=0;i<dataSize;i++){
        if(start < end){
            if((i < end) &&(i >= start)){
                std::cout << data[i] << "->";
            }
        }else if(end < start){
            if(i<end){
                std::cout << data[i] << "->";
            }else if(!((i>end)&&(i<=start))){
                std::cout << data[i];
            }
        }
//        std::cout << "->";
    }
//    std::cout << std::endl;
}
#endif // STACK_H
