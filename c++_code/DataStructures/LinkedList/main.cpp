//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;


int main()
{
    int size = 0;
    cout << "Enter problem size:" << endl;
    cin >> size;
    ///////////////////Array Setup//////////////////////////////////
    ArrayList<Address> aListA;
    ArrayList<Address> aListB;

    AddressFactory aFactory("25000AddressesA.txt");
    AddressFactory aFactory2("25000AddressesB.txt");

    for(int i = 0; i < size / 2; i++) {
        Address a = aFactory.getNext();
        aListA.insertEnd(a);
        Address a2 = aFactory2.getNext();
        aListB.insertEnd(a2);
    }
    //////////////////End Array Setup//////////////////////////////

    cout << "---------------------Section 1--------------------" << endl;
    /////////////////////Combine Testing///////////////////////////
    cout << "Testing 'combine', output should be two lists, followed by a combined list and an empty list." << endl;
    cout << "aListA size is :" << aListA.listSize() << endl;
    cout << "aListB size is :" << aListB.listSize() << endl;

    clock_t start1 = clock();
    aListA.combine(aListB);
    clock_t end1 = clock();
    double time1 = (double) (end1-start1) / CLOCKS_PER_SEC;
    cout << "aListA size is: " << aListA.listSize() << endl;
    cout << "aListB size is: " << aListB.listSize() << endl;
    cout << "Combine took " << time1 << "ms" << endl;
    for(int i = (aListA.listSize()/2 - 2); i <= (aListA.listSize()/2 + 1); i++){
        cout <<aListA.retrieveAt(i);
    }
    //////////////////End Combine Testing/////////////////////////

    ////////////////Extract All Matches Testing///////////////////
    cout << "---------------------Section 2--------------------" << endl;
    cout << "Extracting all Oregon addresses from aListA to aListC." << endl;
    Address itemToMatch;
    itemToMatch.state = "OR";
    clock_t start2 = clock();
    ArrayList<Address> aListC = aListA.extractAllMatches(itemToMatch);
    clock_t end2 = clock();
    double time2 = (double) (end2-start2) / CLOCKS_PER_SEC;
    cout << "ExtractAllMatches took: " << time2 << "ms." << endl;
    cout << "aListC (OR addresses) length: " << aListC.listSize() << endl;
    cout << "aListA (non-OR addresses) length: " << aListA.listSize() << endl;
    /////////////////End Extract All Matching Testing//////////////////////

    cout << "---------------------Section 3--------------------" << endl;

    ////////////////////Address Factory Linked List////////////////////////

    AddressLinkedList linkListA;
    AddressLinkedList linkListB;
    AddressFactory aFactory3("25000AddressesA.txt");
    AddressFactory aFactory4("25000AddressesB.txt");
    for(int i = 0; i < (size / 2); i++) {
        Address a = aFactory3.getNext();
        linkListA.insertEnd(a);
        Address a2 = aFactory4.getNext();
        linkListB.insertEnd(a2);
    }
    cout << "Use printRange to print indexes 2-4 (items 3-5) of each list." << endl;
    cout << "linkListA: " << endl;
    linkListA.printRange(3,5);
    cout << "linkListB: " << endl;
    linkListB.printRange(3,5);

    ////////////////End Address Foctory Linked List Build//////////////////

    cout << "---------------------Section 4--------------------" << endl;

    ///////////////////Copy and Combine Function Testing///////////////////////////////
    cout << "Copy and Combine Function Testing :" << endl;
    AddressLinkedList linkListC(linkListA);
    AddressLinkedList linkListD(linkListB);
    cout << "Length of LinkListC :" << linkListC.listSize() << endl;
    cout << "Length of LinkListD :" << linkListD.listSize() << endl;
    clock_t start3 = clock();
    linkListC.combine(linkListD);
    clock_t end3 = clock();
    double time3 = (double) (end3 - start3) / CLOCKS_PER_SEC;
    cout << endl << "Combine took: " << time3 << " ms." << endl << endl;
    cout << "Length of LinkListC :" << linkListC.listSize() << endl;
    cout << "Length of LinkListD :" << linkListD.listSize() << endl;
    cout << endl << "Verification of combine function." << endl;
    //Print out addresses with index (size/2 - 2) to (size/2 + 1) from linkListC using printRange.
    cout << "LinkListC at the combine point." << endl;
    linkListC.printRange((size / 2) - 1, (size / 2) + 2);
    ////////////End Copy And Combine Function Testing////////////////////////////////////

    /////////////////////////Extract All Matches Testing/////////////////////////////////

    cout << "---------------------Section 5--------------------" << endl;
    cout << "Extract All Matches Testing :" << endl;
    Address findMe;
    findMe.state = "OR";
    clock_t start4 = clock();
    AddressLinkedList linkListE = linkListC.extractAllMatches(findMe);
    clock_t end4 = clock();
    double time4 = (double) (end4 - start4) / CLOCKS_PER_SEC;
    cout << "Extract all matches took : " << time4 << "ms." << endl;
    //    Print out the lengths of linkListC and linkListE.
    //    Use printRange to print out the first two records of linkListE.
    cout << "LinkListC : " << linkListC.listSize() << endl;
    cout << "LinkListE : " << linkListE.listSize() << endl;
    cout << "First two addresses in linkListE:" << endl;
    linkListE.printRange(1,2);
    ////////////////////End Extract All Matches Testing//////////////////////////////////

    ///////////////////////Interleave Function Testing///////////////////////////////////

    cout << "---------------------Section 6--------------------" << endl;
    cout << "Interleave function testing:" << endl;
    //    Use the interleave function to mix linkListB into linkListA. See the .h for documentation.
    //    Print the first 5 records from linkListA.
    cout << "LinkListA size: " << linkListA.listSize() << endl;
    cout << "LinkListB size : " << linkListB.listSize() << endl;
    clock_t start5 = clock();
    linkListA.interleave(linkListB);
    clock_t end5 = clock();
    double time5 = (double) (end5 - start5) / CLOCKS_PER_SEC;
    cout << "Interleave took :" << time5 << "ms." << endl;
    cout << "LinkListA size: " << linkListA.listSize() << endl;
    cout << "LinkListB size: " << linkListB.listSize() << endl;
    linkListA.printRange(1,5);
    ///////////////////End Interleave Function Testing//////////////////////////////////
    return 0;
}
