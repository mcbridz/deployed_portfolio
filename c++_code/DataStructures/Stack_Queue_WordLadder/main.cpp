#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <time.h>
#include <math.h>

using namespace std;
char getChar() {
    static char nextChar = 'A' - 1;

    ++nextChar;
    if(nextChar > 'Z')
        nextChar = 'A';

    return nextChar;
}
int main(){
    ///////////////Start Stack Testing//////////////////
    ////////////////Push and Pop Testing////////////////
    cout << "------------Section 1---------------------" << endl;
    cout << "----Testing Push, Pop, Peek and Print-----" << endl;
    Stack<char> s1;
    cout << "Pushing 'B'." << endl;
    s1.push('B');
    cout << "Pushing 'A'." << endl;
    s1.push('A');
    cout << "Pushing 'R'." << endl;
    s1.push('R');
    cout << "Peeking at s1." << endl;
    cout << "//" << s1.peek() << endl;
    cout << "Popping s1." << endl;
    s1.pop();
    cout << "Pushing 'D'." << endl;
    s1.push('D');
    cout << "Forward Print:" << endl;
    s1.print();
    cout << "Reverse Print:" << endl;
    s1.reversePrint();
    cout << endl;
    ////////////////End Stack Testing//////////////////
    ////////////Start Queue Testing////////////////////
    cout << "--------------Section 3----------------" << endl;
    cout << "------------Testing Queue--------------" << endl;
    Queue<char> q1;
    cout << "Queuing 'F' 'L' and 'A'" << endl;
    q1.enqueue('F');
    q1.enqueue('L');
    q1.enqueue('A');
    cout << "Dequeing." << endl;
    q1.dequeue();
    cout << "Enqueuing 'T'." << endl;
    q1.enqueue('T');
    cout << "Contents of queue" << endl;
    q1.print();
    cout << "Enqueuing 'E'." << endl;
    q1.enqueue('E');
    cout << "Dequeing." << endl;
    q1.dequeue();
    cout << "Contents of queue" << endl;
    q1.print();
    cout << "Queuing 1000 '?'s" << endl;
    for(int i=0;i<1000;i++){
        q1.enqueue('?');
    }
    cout << "Dequeuing 1000 times." << endl;
    for(int i=0;i<1000;i++){
        q1.dequeue();
    }
    cout << "Enqueuing 'S'" << endl;
    q1.enqueue('S');
    cout << "Contents of queue" << endl;
    q1.print();
    /////////////End Queue Testing/////////////////////
    return 0;
}
