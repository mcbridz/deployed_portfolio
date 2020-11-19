#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Person.h"

using namespace std;

int main(){
    cout << "Please enter the size of dataset to be taken greather than 10:" << endl;
    int numberinput;
    cin >> numberinput;
    //input control//
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid entry." << endl << "Please enter the size of dataset to be taken." << endl;
        cin >> numberinput;
    }
    ifstream dataSource;
    dataSource.open ("people.txt");
    //dataSource.open("peopleSorted.txt");
    if(dataSource.fail()){
        cout << "Failed to open file." << endl;
        return 0;
    }
        //ofstream log;
        //log.open("log.txt");
        //log << "Commence operations." << endl;
    Person * personData;
    personData = new Person[numberinput];
    //K numbers are 8 characters long, commas separating, last name, first name, zip code
    for(int i=0; i<numberinput; i++){
        try{
            string tempString;
            getline(dataSource, tempString);
            int comma1, comma2, comma3, lengthString;
            comma1 = 8;
            comma2 = tempString.find(',', 9);
            comma3 = tempString.find(',', comma2 + 1);
            lengthString = tempString.length();
            personData[i].kNum = tempString.substr(0,comma1);
            personData[i].last = tempString.substr(comma1 + 1,comma2 - comma1 - 1);
            personData[i].first = tempString.substr(comma2 + 1, comma3 - comma2 - 1);
            string zipCode = tempString.substr(comma3 + 1, lengthString - comma3);
            stringstream dump(zipCode);
            dump >> personData[i].zipCode;
        }catch(...){
            cout << "An unexpected error occured at entry: " << i << endl;
        }
    }
    ///////////////////////////countLastName////////////////////////////////////////////
    cout << "Checking for the last name: Mertz" << endl;
    const int TIMING_REPETITIONS1 = 100000;
    clock_t start1 = clock();
    for(int i=0; i<1; i++){
//    for(int i=0; i<TIMING_REPETITIONS1; i++){
        cout << countLastName("Mertz", personData, numberinput) << endl;
    }
    clock_t end1 = clock();
    double time1 = (double) (end1-start1) / CLOCKS_PER_SEC /* /TIMING_REPETITIONS1 */;
    time1 = time1 * 1000;
    cout << "CountLastName took :" << time1 << "ms." << endl;
    /////////////////////////partialZipSort//////////////////////////////////////////////
    cout << "Partial Zipcode sorting test:" << endl;
    partialZipSort(personData, 2, 7);
    for (int i = 0; i<10; i++){
        cout << personData[i].kNum << " " << personData[i].last << " " << personData[i].first <<
                " " << personData[i].zipCode << endl;
    }
    cout << "End Partial Zipcode sorting test." << endl;
    ///////////////////////////////nameSort//////////////////////////////////////////////
    cout << "Name Sorting Test." << endl;
    const int TIMING_REPETITIONS2 = 10000;
    clock_t start2 = clock();
    for(int i=0; i<1; i++){
//    for(int i=0; i<TIMING_REPETITIONS2; i++){
        nameSort(personData, numberinput);
    }
    clock_t end2 = clock();
    double time2 = (double) (end2-start2) / CLOCKS_PER_SEC/* /TIMING_REPETITIONS2 */;
    time2 = time2 * 1000;
    for(int i=0;i<10;i++){
        cout << personData[i].kNum << " " << personData[i].last << " " << personData[i].first <<
                " " << personData[i].zipCode << endl;
    }
    cout << "NameSort took :" << time2 << "ms." << endl;
    cout << "End Name Sorting Test" << endl;
    /////////////////////////////binaryfinding///////////////////////////////////////////
    cout << "Binary Search Testing:" << endl;
    cout << "BinaryFindFirstByLastName for 'Abbott'" << endl;
    cout << binaryFindFirstByLastName("Abbott", personData, numberinput) << endl;
    cout << "BinaryFirndLastByLastName for 'Abbott'" << endl;
    cout << binaryFindLastByLastName("Abbott", personData, numberinput) << endl;
    cout << "BinaryFindFirstByLastName for 'Zulauf'" << endl;
    cout << binaryFindFirstByLastName("Zulauf", personData, numberinput) << endl;
    cout << "BinaryFindLastByLastName for 'Zulauf'" << endl;
    cout << binaryFindLastByLastName("Zulauf", personData, numberinput) << endl;
    cout << "End Binary Search Testing" << endl;
    ///////////////////////////countLastNameInSorted/////////////////////////////////////
    cout << "Count Last Names In Sorted list testing:" << endl;
    const int TIMING_REPETITIONS3 = 10000;
    clock_t start3 = clock();
//    for(int i=0; i<TIMING_REPETITIONS3; i++){
    for(int i=0;i<1;i++){
        cout << countLastNameInSorted("Mertz", personData, numberinput) << " Mertz's in data." << endl;
    }
    clock_t end3 = clock();
    double time3 = (double) (end3-start3) / CLOCKS_PER_SEC /*/ TIMING_REPETITIONS3*/;
    time3 = time3 * 1000;
    cout << "CountLastNameInSorted took " << time3 << "ms." << endl;
    cout << "End Count Last Names In Sorted list testing." << endl;
    /////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
