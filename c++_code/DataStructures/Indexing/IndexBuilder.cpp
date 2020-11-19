#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include "IndexBuilder.h"
#include "IndexMap.h"
#include "IndexRecord.h"

using namespace std;

int main(){
    cout << "Building index from 'Great Expectations'." << endl;
    fstream source;
    source.open("GreatExpectations.txt");
    if(!source.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }else{
        cout << "Great Expectations is open." << endl;
    }
    int word = 1;
    int page = 1;
    IndexMap index;
    string temp;
    clock_t start1 = clock();
    while(!source.eof()){
        source >> temp;
        if(temp[0] != '-'){
            index.add(temp, page, word);            
//            if(page == 100 && word == 1){
//                cout << temp;
//            }
            word++;
        }else{
            word = 1;
            page++;
        }
    }
    clock_t end1 = clock();
    double time1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
    cout << "Building the index took: " << time1 << endl;
    cout << "The index has " << index.numKeys() << " unique words." << endl;
    IndexRecord fathers = index.get("fathers");
    cout << fathers << endl;
    index.findWordPairs("great", "expectations");
    string firstWord = index.firstWordOnPage(100);
    cout << firstWord << endl;
    string firstWord2 = index.firstWordOnPage(1);
    cout << firstWord2 << endl;
}
