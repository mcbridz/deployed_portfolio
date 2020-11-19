/*
  * @brief Assignment 9
   * @author Zachary McBride
  */
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <iomanip>
#include "android.h"
#include <string>
#include <cctype>

using namespace std;

int main(){
    ifstream dataSource;
    dataSource.open ("googleplaystore.csv");
    if(dataSource.fail()){
        cout << "Failed to open input file." << endl;
        return 0;
    }
    ofstream log;
    log.open ("log.txt", ofstream::out | ofstream::trunc);
    if(log.fail()){
        cout << "Failed to open output file" << endl;
        return 0;
    }
    log.close();
    string tempString;
    getline(dataSource, tempString);
    header dataHeader;
    readInColumnHeaders(dataHeader, tempString);
    dataSource.close();
    int size = howBigIsFile("googleplaystore.csv");
    tempApp* tempAppData = new tempApp[size];
    app* appData = new app[size];
    dataSource.open("googleplaystore.csv");
    getline(dataSource, tempString); //skip the first line
    for (int entry = 1; entry < size; entry++){
        getline(dataSource, tempString);
        readInData(tempString, tempAppData, appData, entry);
    }
    string tempCategories[150];
    int numberOfCategories = findNumberOfCategories(appData, size, tempCategories);
    string* categories = new string[numberOfCategories];
    findCategories(appData, size, categories, numberOfCategories);
    displayMainMenu(appData, size, categories, numberOfCategories);
    return 0;
}


