//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>

#include "MySet.h"

using namespace std;

//assumes x is in range [0-999]
string intTo3DigitString(int x) {
    stringstream s;
    s << setw(3) << setfill('0') << x;
    return s.str();
}

//Returns a vector containing all valid IP addresses starting with 192.168
vector<string> getLocalIPs() {
    string prefix = "192.168";

    vector<string> localIPs;

    for(int i = 0; i < 256; i++) {
        string thirdSegment = "." + intTo3DigitString(i);
        for(int j = 0; j < 256; j++) {
            string fourthSegment = "." + intTo3DigitString(j);
            localIPs.push_back(prefix + thirdSegment + fourthSegment);
        }
    }

    return localIPs;
}

int main()
{
    cout << "How many records are to read?" << endl;
    int dataSize;
    cin >> dataSize;
    ///////////////////////dataSize static//////////////////////////////
    //dataSize = 1000;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid entry." << endl << "Please enter the size of dataset to be taken." << endl;
        cin >> dataSize;
    }
    ifstream ipListA;
    ipListA.open("IPListA.txt");
    ifstream ipListB;
    ipListB.open("IPListB.txt");
    MySet<string> setA;
    for(int i=0; i<dataSize; i++){
        string ToBeAdded;
        ipListA >> ToBeAdded;
        setA.add(ToBeAdded);
    }
    // cout << "-----------Troubleshooting information------------" << endl;
    //    setA.printWholeTree();
    //    cout << endl;
    cout << "-----------------Part 1---------------------------" << endl;
    cout << "-----------Size and Depth-------------------------" << endl;
    cout << "The depth of setA is: " << setA.depth() << endl;
    cout << "The size of setA is: " << setA.size() << endl;
    cout << "The smallest IP Address is: " << setA.getSmallest() << endl;
    cout << "-----------------Part 2---------------------------" << endl;
    cout << "---------Copy Constr. and removeLargest-----------" << endl;
    clock_t start1 = clock();
    /////////////////////////////////repeater////////////////////////////
    int repeater = 1;
    for(int i=0; i<repeater; i++){
        setA.getSmallest();
    }
    clock_t end1 = clock();
    double time1 = (double) (end1-start1) / (CLOCKS_PER_SEC);
    cout << "getSmallest() was ran " << repeater << " times and took: " << time1 << "ms." << endl;
    cout << "-----------------Part 3---------------------------" << endl;
    MySet<string> setA2(setA);
    cout << "Removing 10 from setA2." << endl;
    for(int i=0; i<10; i++){
        cout << "Removed: " << setA2.removeLargest() << endl;
    }
    cout << "Current size of setA2 is: " << setA2.size() << endl;
    cout << "-----------------Part 4---------------------------" << endl;
    MySet<string> setA3(setA);
    vector<string> localIPs;
    setA3.getLocalIPsStarter(localIPs);
    //    while(!localIPs.empty()){
    //        string temp = localIPs.back();
    //        localIPs.pop_back();
    //        cout << temp << endl;
    //    }
    cout << "There are " << localIPs.size() << " local addresses." << endl;
    cout << "Current size of setA3 is " << setA3.size() << endl;
    cout << "-----------------Part 5---------------------------" << endl;
    MySet<string> setB;
    for(int i=0; i<dataSize; i++){
        string ToBeAdded;
        ipListB >> ToBeAdded;
        setB.add(ToBeAdded);
    }
    MySet<string> setAIB = setA.intersectionWith(setB);
    cout << "Current size of setAIB is: " << setAIB.size() << endl;
    cout << "The smallest item in set AIB is: " << setAIB.getSmallest() << endl;
    cout << "-----------------Part 6---------------------------" << endl;
    clock_t start2 = clock();
    MySet<string> setAUB = setA.unionWith(setB);
    clock_t end2 = clock();
    double time2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
    cout << "UnionWith took " << time2 << "ms." << endl;
    cout << "Current size of setAUB is: " << setAUB.size() << endl;
    cout << "The smallest item in set AUB is: " << setAUB.getSmallest() << endl;
    cout << "-----------------Part 7---------------------------" << endl;
    cout << "Pulling all ipAddresses from setA between 100.000.000.000 and 110.000.000.000." << endl;
    clock_t start3 = clock();
    vector<string> pullFromA = setA.getRange("100.000.000.000", "110.000.000.000");
    clock_t end3 = clock();
    double time3 = (double) (end3 - start3) / CLOCKS_PER_SEC;
    cout << "GetRange took " << time3 << "ms." << endl;
    cout << "Size of vector is " << pullFromA.size() << endl;
    vector<string>::iterator myIt = pullFromA.begin();
    if(pullFromA.size() >= 5){
        for(int i=0; i<5; i++){
            cout << *myIt << endl;
            myIt++;
        }
    }else{
        for(int i=0; i<pullFromA.size(); i++){
            cout << *myIt << endl;
            myIt++;
        }
    }
}

