//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{
    ifstream inFile("Document.html");
    if( !inFile.is_open() ) {
        cout << "Error opening file" << endl;
        return 1;
    }else{
        cout << "Document.html has been accessed." << endl;
    }
    Stack<string> htmlStack;
    string dataStream;
    while(inFile >> dataStream){
        if(dataStream.at(0) == '<'){
            htmlStack.push(dataStream);
        }else{
            htmlStack.reversePrint();
            cout << " " << dataStream << endl;
        }
        if(htmlStack.peek().at(1) == '/'){
            string copy = htmlStack.pop();
            string checker;
            for(int i=0; i<copy.length(); i++){
                if(copy.at(i) != '/'){
                    checker+= copy.at(i);
                }
            }try{
                if(htmlStack.peek() != checker){
                    throw "Mismatched Tag";
                }
            }catch(...){
                cout << "Mismatched tag, no " << checker << " tag exists to match " << dataStream << "." << endl;
                return 0;
            }
            htmlStack.pop();
        }
    }
    if(!htmlStack.isEmpty()){
        cout << "Missing tag. Remaining tags are :";
        htmlStack.reversePrint();
        cout << endl;
    }
    return 0;
}

