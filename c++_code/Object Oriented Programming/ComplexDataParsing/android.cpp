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

//using namespace std;

inline void WaitEnter() {
    std::cout << "Press Enter to continue...";
    while (std::cin.get()!='\n');
}

void writeToLog(std::string message, int entry){
    std::ofstream log;
    log.open("log.txt", std::ios::app);
    log << message << " for entry " << entry << " completed." << std::endl;
}

int monthToNumber(std::string input){
    int output = 0;
    if (bool(input.find("Jan") <= 7) == true){
        output = 1;
        return output;
    }else
        if (bool(input.find("Feb") <= 7) == true){
            output = 2;
            return output;
        }else
            if (bool(input.find("Mar") <= 7) == true){
                output = 3;
                return output;
            }else
                if (bool(input.find("Apr") <= 7) == true){
                    output = 4;
                    return output;
                }else
                    if (bool(input.find("May") <= 7) == true){
                        output = 5;
                        return output;
                    }else
                        if (bool(input.find("Jun") <= 7) == true){
                            output = 6;
                            return output;
                        }else
                            if (bool(input.find("Jul") <= 7)== true){
                                output = 7;
                                return output;
                            }else
                                if (bool(input.find("Aug") <= 7) == true){
                                    output = 8;
                                    return output;
                                }else
                                    if (bool(input.find("Sep") <= 7) == true){
                                        output = 9;
                                        return output;
                                    }else
                                        if (bool(input.find("Oct") <= 7)== true){
                                            output = 10;
                                            return output;
                                        }else
                                            if (bool(input.find("Nov") <= 7) == true){
                                                output = 11;
                                                return output;
                                            }else
                                                if (bool(input.find("Dec") <= 7) == true){
                                                    output = 12;
                                                    return output;
                                                }
                                                else{
                                                    return output;
                                                }

}

int howBigIsFile(std::string filename){
    int output = 0;
    std::ifstream dataSource;
    dataSource.open (filename);
    if(dataSource.fail()){
        std::cout << "Failed to open input file." << std::endl;
        return 0;
    }
    while(!dataSource.eof()){
        std::string tempString;
        getline(dataSource, tempString);
        output++;
    }
    dataSource.close();
    return output;
}

void readInColumnHeaders(header& output, std::string input){
    int findCommaName = input.find(',', 0);
    int findCommaCategory = input.find(',', (findCommaName + 1));
    int findCommaRating = input.find(',', (findCommaCategory + 1));
    int findCommaNumberReviews = input.find(',', (findCommaRating + 1));
    int findCommaAppSize = input.find(',', (findCommaNumberReviews + 1));
    int findCommaNumberInstalls = input.find(',', (findCommaAppSize + 1));
    int findCommaType = input.find(',', findCommaNumberInstalls + 1);
    int findCommaPrice = input.find(',', findCommaType + 1);
    int findCommaContentRating = input.find(',', (findCommaPrice + 1));
    int findCommaGenre = input.find(',', (findCommaContentRating + 1));
    int findCommaLastUpdated = input.find(',', (findCommaGenre + 1));
    int findCommaAppVersion = input.find(',', (findCommaLastUpdated + 1));
    int findCommaAndroidVersion = input.find(',', (findCommaAppVersion + 1));

    output.name = input.substr(0, findCommaName); //name
    output.category = input.substr((findCommaName + 1), ((findCommaCategory - findCommaName) - 1)); //category
    output.rating = input.substr((findCommaCategory + 1), ((findCommaRating - findCommaCategory - 1))); //rating
    output.numberReviews = input.substr((findCommaRating + 1), ((findCommaNumberReviews - findCommaRating) - 1)); //reviews
    output.appSize = input.substr((findCommaNumberReviews + 1), ((findCommaAppSize - findCommaNumberReviews) - 1)); //appSize
    output.numberInstalls = input.substr((findCommaAppSize + 1), ((findCommaNumberInstalls - findCommaAppSize) - 1)); //installs
    output.type = input.substr((findCommaNumberInstalls + 1), ((findCommaType - findCommaNumberInstalls) - 1)); //type
    output.price = input.substr((findCommaType + 1), ((findCommaPrice - findCommaType) - 1)); //price
    output.contentRating = input.substr((findCommaPrice + 1), ((findCommaContentRating - findCommaPrice) - 1)); //contentRating
    output.genre = input.substr((findCommaContentRating + 1), ((findCommaGenre - findCommaContentRating) - 1)); //genre
    std::string lastUpdated = input.substr((findCommaGenre + 1), ((findCommaLastUpdated - findCommaGenre) - 1));
    output.lastUpdated = input.substr((findCommaGenre + 1), ((findCommaLastUpdated - findCommaGenre) - 1)); //last updated
    output.currentAppVersion = input.substr((findCommaLastUpdated + 1), ((findCommaAppVersion - findCommaLastUpdated) - 1)); //currentAppVersion
    output.androidVersion = input.substr((findCommaAppVersion + 1), ((findCommaAndroidVersion - findCommaAppVersion) - 1)); //android version

}

std::string removeQuotes(std::string tempString){
    while (tempString.find('"') != std::string::npos){
        /*        for (int i = 0; i < tempString.length(); i++){
            if (tempString.at(i) == '"'){
                tempString.erase(i, 1);
            }*/
        int i = tempString.find('"');
        tempString.erase(i, 1);
    }
    return tempString;
}

int findTheRealNameComma(std::string tempString, int& findCommaName){
    for (int i = 3; i < (tempString.length() - 2); i++){
        char temp1 = tempString.at(i);
        char temp2 = tempString.at(i + 1);
        char tempMinus1 = tempString.at(i - 2);
        if (((temp1 <= 90) && (temp1 >= 65)) == true){
            if (((temp2 <= 90) && (temp2 >= 65)) == true){
                if (tempMinus1 == ','){
                    findCommaName = (i - 2);
                }
                if (findCommaName > 0){
                    break;
                }
            }
        }
    }
    return findCommaName;
}

void makeTempAppData(std::string tempString, tempApp* tempAppData, int entry){
    writeToLog(tempString, entry);
    int findCommaName = 0;
    findCommaName = findTheRealNameComma(tempString, findCommaName);
    writeToLog("findTheRealNameComma", entry);
    int findCommaCategory = tempString.find(',', (findCommaName + 1));
    int findCommaRating = tempString.find(',', (findCommaCategory + 1));
    int findCommaNumberReviews = tempString.find(',', (findCommaRating + 1));
    int findCommaAppSize = tempString.find(',', (findCommaNumberReviews + 1));
    int whereThePlusSignIs = tempString.find('+');
    int findCommaEndNumberInstalls = whereThePlusSignIs + 2;
    int findCommaType = tempString.find(',', findCommaEndNumberInstalls + 1);
    int findCommaPrice = tempString.find(',', findCommaType + 1);
    int findCommaContentRating = tempString.find(',', (findCommaPrice + 1));
    int findCommaGenre = tempString.find(',', (findCommaContentRating + 1));
    int findCommaLastUpdated = tempString.find(',', (findCommaGenre + 1));
    int findCommaEndLastUpdated = tempString.find(',', (findCommaLastUpdated + 1));
    int findCommaAppVersion = tempString.find(',', (findCommaEndLastUpdated + 1));
    int findCommaAndroidVersion = tempString.find(',', (findCommaAppVersion + 1));
    std::string name = tempString.substr(0, findCommaName);
    //    writeToLog(name, entry);
    tempAppData[entry].name = name; //name
    std::string category = tempString.substr((findCommaName + 1), ((findCommaCategory - findCommaName - 1)));
    //    writeToLog(category, entry);
    tempAppData[entry].category = category; //category
    std::string rating = tempString.substr((findCommaCategory + 1), ((findCommaRating - findCommaCategory - 1)));
    //    writeToLog(rating, entry);
    tempAppData[entry].rating = rating; //rating
    std::string numberReviews = tempString.substr((findCommaRating + 1), ((findCommaNumberReviews - findCommaRating) - 1));
    //    writeToLog(numberReviews, entry);
    tempAppData[entry].numberReviews = numberReviews; //reviews
    std::string appSize = tempString.substr((findCommaNumberReviews + 1), ((findCommaAppSize - findCommaNumberReviews) - 1));
    //    writeToLog(appSize, entry);
    tempAppData[entry].appSize = appSize; //appSize
    std::string numberInstalls = tempString.substr((findCommaAppSize + 2), ((findCommaEndNumberInstalls - findCommaAppSize) - 3));
    //    writeToLog(numberInstalls, entry);
    tempAppData[entry].numberInstalls = numberInstalls; //installs
    std::string type = tempString.substr((findCommaEndNumberInstalls + 1), ((findCommaType - findCommaEndNumberInstalls) - 1));
    //    writeToLog(type, entry);
    tempAppData[entry].type = type; //type
    std::string price = tempString.substr((findCommaType + 1), ((findCommaPrice - findCommaType) - 1));
    //    writeToLog(price, entry);
    tempAppData[entry].price = price; //price
    std::string contentRating = tempString.substr((findCommaPrice + 1), ((findCommaContentRating - findCommaPrice) - 1));
    //    writeToLog(contentRating, entry);
    tempAppData[entry].contentRating = contentRating; //contentRating
    std::string genre = tempString.substr((findCommaContentRating + 1), ((findCommaGenre - findCommaContentRating) - 1));
    //    writeToLog(genre, entry);
    tempAppData[entry].genre = genre; //genre
    std::string lastUpdated = tempString.substr((findCommaGenre + 2), ((findCommaEndLastUpdated - findCommaGenre) - 3));
    //    writeToLog(lastUpdated, entry);
    tempAppData[entry].lastUpdated = lastUpdated; //last updated
    std::string currentAppVersion = tempString.substr((findCommaEndLastUpdated + 1), ((findCommaAppVersion - findCommaEndLastUpdated) - 1));
    //    writeToLog(currentAppVersion, entry);
    tempAppData[entry].currentAppVersion = currentAppVersion; //currentAppVersion
    std::string androidVersion = tempString.substr((findCommaAppVersion + 1), ((findCommaAndroidVersion - findCommaAppVersion) - 1));
    //    writeToLog(androidVersion, entry);
    tempAppData[entry].androidVersion = androidVersion; //android version
    //    writeToLog("Make tempAppData", entry);
}

void transferRatingData(tempApp* tempAppData, app* appData, int entry){
    std::stringstream tempStream(tempAppData[entry].rating);
    double rating = 0.0;
    tempStream >> rating;
    if (tempStream.fail()){
        rating = 0.0;
    }
    rating = rating * 100;
    rating = round(rating);
    rating = rating / 100;
    appData[entry].rating = rating;
    writeToLog("Convert rating data", entry);
}
void convertAppSize(tempApp* tempAppData, app* appData, int entry){
    if (tempAppData[entry].appSize.find("M") != std::string::npos ){
        long int tempData = 0;
        tempAppData[entry].appSize.erase(tempAppData[entry].appSize.find("M"), 1);
        std::stringstream dataStream(tempAppData[entry].appSize);
        dataStream >> tempData;
        tempData = tempData * 1000000;
        appData[entry].appSize = tempData;
    } else if (tempAppData[entry].appSize.find("K") != std::string::npos){
        long int tempData = 0;
        tempAppData[entry].appSize.erase(tempAppData[entry].appSize.find("K"), 1);
        std::stringstream dataStream(tempAppData[entry].appSize);
        dataStream >> tempData;
        tempData = tempData * 1000;
        appData[entry].appSize = tempData;
    } else if (isalpha(tempAppData[entry].appSize.length() - 1) == 1){
        tempAppData[entry].appSize.erase(tempAppData[entry].appSize.length() - 1);
        long int tempLastResort = 0;
        std::stringstream lastStream(tempAppData[entry].appSize);
        lastStream >> tempLastResort;
        appData[entry].appSize = tempLastResort;
    }else{
        appData[entry].appSize = 0;
    }
    writeToLog("Convert app size", entry);
}

void convertNumberInstalls(tempApp* tempAppData, app* appData, int entry){
    std::string stringToBeSent = tempAppData[entry].numberInstalls;
    int tempNumberPlusSign = tempAppData[entry].numberInstalls.find('+');
    tempAppData[entry].numberInstalls.erase(tempNumberPlusSign, 1);
    while (tempAppData[entry].numberInstalls.find(',') != std::string::npos){
        int commaPlace = tempAppData[entry].numberInstalls.find(',');
        if (commaPlace > 0){
            tempAppData[entry].numberInstalls.erase(commaPlace, 1);
        }
        commaPlace = tempAppData[entry].numberInstalls.find(',');
    }
    stringToBeSent = tempAppData[entry].numberInstalls;
    int numberInstalls;
    std::stringstream numberInstallsStream(stringToBeSent);
    numberInstallsStream >> numberInstalls;
    appData[entry].numberInstalls = numberInstalls;
    writeToLog("Convert number of installs", entry);
}

void convertPrice(tempApp* tempAppData, app* appData, int entry){
    if (tempAppData[entry].price.at((tempAppData[entry].price.length() - 1) == '$')){
        tempAppData[entry].price.erase(tempAppData[entry].price.length() - 1, 1);
        double price = 0.0;
        std::stringstream priceStream(tempAppData[entry].price);
        priceStream >> price;
        appData[entry].price = price;
    }else{
        double price = 0.0;
        std::stringstream priceStream(tempAppData[entry].price);
        priceStream >> price;
        appData[entry].price = price;
    }
    writeToLog("Convert price", entry);
}

void convertDate(tempApp* tempAppData, app* appData, int entry){
    int firstDateSpace = tempAppData[entry].lastUpdated.find(" ");
    int secondDateSpace = tempAppData[entry].lastUpdated.find(" ", firstDateSpace + 1);
    std::string outToConvert = tempAppData[entry].lastUpdated.substr(0, firstDateSpace);
    int month = monthToNumber(outToConvert);
    writeToLog("Convert month to number", entry);
    appData[entry].lastUpdated.month = month;
    std::string day = tempAppData[entry].lastUpdated.substr(firstDateSpace + 1, secondDateSpace - 1);
    std::stringstream dayStream(day);
    dayStream >> appData[entry].lastUpdated.day;
    std::string year = tempAppData[entry].lastUpdated.substr(secondDateSpace + 1, tempAppData[entry].lastUpdated.length() - secondDateSpace);
    std::stringstream yearStream(year);
    int yearReturn = 0;
    yearStream >> yearReturn;
    appData[entry].lastUpdated.year = yearReturn;
    writeToLog("Convert date", entry);
}

void transferTempToMainData(tempApp* tempAppData, app* appData, int entry){
    appData[entry].name = tempAppData[entry].name;
    appData[entry].category = tempAppData[entry].category;
    transferRatingData(tempAppData, appData, entry);
    int reviews = 0;
    std::stringstream reviewsStream(tempAppData[entry].numberReviews);
    reviewsStream >> reviews;
    appData[entry].numberReviews = reviews;
    convertAppSize(tempAppData, appData, entry);
    convertNumberInstalls(tempAppData, appData, entry);
    appData[entry].type = tempAppData[entry].type;
    convertPrice(tempAppData, appData, entry);
    appData[entry].contentRating = tempAppData[entry].contentRating;
    appData[entry].genre = tempAppData[entry].genre;
    convertDate(tempAppData, appData, entry);
    appData[entry].currentAppVersion = tempAppData[entry].currentAppVersion;
    appData[entry].androidVersion = tempAppData[entry].androidVersion;
    writeToLog("transferTempToMainData", entry);
}

void readInData(std::string tempString, tempApp* tempAppData, app* appData, int entry){
    removeQuotes(tempString);
    writeToLog("Remove quotes", entry);
    makeTempAppData(tempString, tempAppData, entry);
    transferTempToMainData(tempAppData, appData, entry);
}

void displayMainMenu(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << std::endl;
    std::cout << "MAIN MENU" << std::endl << std::endl;
    std::cout << "1. Search By Name" << std::endl;
    std::cout << "2. Search By Category" << std::endl;
    std::cout << "3. Display By Entry Number" << std::endl;
    std::cout << "4. Exit" << std::endl << std::endl;
    std::cout << "Enter selection: " << std::endl;
    getUserInput(appData, size, categories, numberOfCategories);
}

void getUserInput(app* appData, int size, std::string* categories, int numberOfCategories){
    int input = 4;
    std::cin >> input;
    //input handling
    while(std::cin.fail() || ((input < 1) && (input < 7))){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid selection, please try again." << std::endl;
        std::cin >> input;
    }
    switch (input){
    case 1: searchByNameMenu(appData, size, categories, numberOfCategories); break;
    case 2: searchByCategoryMenu(appData, size, categories, numberOfCategories); break;
    case 3: searchBySelectionMenu(appData, size, categories, numberOfCategories); break;
    case 4: return;
    }
}

void searchByCategoryMenu(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << "Select type of category search:" << std::endl << std::endl;
    std::cout << "1. Free apps by category:" << std::endl;
    std::cout << "2. All apps by category:" << std::endl;
    std::cout << "3. Stats by category:" << std::endl;
    std::cout << "4. Specified search of category:" << std::endl;
    std::cout << "5. Exit category menu" << std::endl;
    getUserInputCategoryMenu(appData, size, categories, numberOfCategories);
    displayMainMenu(appData, size, categories, numberOfCategories);
}

void getUserInputCategoryMenu(app* appData, int size, std::string* categories, int numberOfCategories){
    int input;
    std::cin >> input;
    while(std::cin.fail() || ((input < 1) && (input < 7))){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid selection, please try again." << std::endl;
        std::cin >> input;
    }
    switch(input){
    case 1: freeAppsByCategory(appData, size, categories, numberOfCategories); break;
    case 2: appsByCategory(appData, size, categories, numberOfCategories); break;
    case 3: categoryStats(appData, size, categories, numberOfCategories); break;
    case 4: specifiedSearch(appData, size, categories, numberOfCategories); break;
    case 5: break;
    }
}

void specifiedSearch(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << "Select a category" << std::endl;
    for (int i = 0; i < numberOfCategories; i++){
        std::cout << "(" << i << " " << categories[i] << ")" << "   ";
    }
    std::cout << std::endl;
    int selection = 0;
    std::cin >> selection;
    std::string categorySelection = categories[selection];
    std::cout << "Specify type of search: " << std::endl;
    std::cout << "1. Greater than 'X' reviews" << std::endl;
    std::cout << "2. Greater than 'X' installs" << std::endl;
    std::cout << "3. Smaller than 'X' size" << std::endl;
    std::cout << "4. Exit to Main Menu." << std::endl;
    getUserSpecifiedSearchInput(appData, size, categories, numberOfCategories, categorySelection);
    displayMainMenu(appData, size, categories, numberOfCategories);
}

void getUserSpecifiedSearchInput(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection){
    int input;
    std::cin >> input;
    switch(input){
    case 1: userSpecifiedSearchByReview(appData, size, categories, numberOfCategories, selection); break;
    case 2: userSpecifiedSearchByInstalls(appData, size, categories, numberOfCategories, selection); break;
    case 3: userSpecifiedSearchBySize(appData, size, categories, numberOfCategories, selection); break;
    case 4: break;
    }
}

void userSpecifiedSearchBySize(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection){
    std::cout << std::endl;
    std::cout << "Specify maximum app size (of format: 10M 5K 2B): " << std::endl;
    std::string input;
    std::cin >> input;
    long int convertedValue = convertUserSpecifiedSize(input);
    for (int i = 1; i < size; i++){
        if (appData[i].category == selection){
            if (appData[i].appSize <= convertedValue){
                std::cout << i << " " << appData[i].name << " " << returnSizeToMB(appData[i].appSize) << "   ";
            }
        }
    }
}

long int convertUserSpecifiedSize(std::string input){
    long int output = 0;
    if (input.find("M") != std::string::npos ){
        long int tempData = 0;
        input.erase(input.find("M"), 1);
        std::stringstream dataStream(input);
        dataStream >> tempData;
        tempData = tempData * 1000000;
        output = tempData;
    } else if (input.find("K") != std::string::npos){
        long int tempData = 0;
        input.erase(input.find("K"), 1);
        std::stringstream dataStream(input);
        dataStream >> tempData;
        tempData = tempData * 1000;
        output = tempData;
    } else if (isalpha(input.length() - 1) == 1){
        input.erase(input.length() - 1);
        long int tempLastResort = 0;
        std::stringstream lastStream(input);
        lastStream >> tempLastResort;
        output = tempLastResort;
    }else{
        output = 0;
    }
    return output;
}

void userSpecifiedSearchByInstalls(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection){
    std::cout << std::endl;
    std::cout << "Specify minimum number of installs desired :" << std::endl;
    int input;
    std::cin >> input;
    for (int i = 1; i < size; i++){
        if (appData[i].category == selection){
            if (appData[i].numberInstalls >= input){
                std::cout << "(" << i << " " << appData[i].name << ") ";
            }
        }
    }
}

void userSpecifiedSearchByReview(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection){
    std::cout << std::endl;
    std::cout << "Specify lowest desired review score (on 5.0 scale): " << std::endl;
    double input;
    std::cin >> input;
    for (int i = 1; i < size; i++){
        if (appData[i].category == selection){
            if (appData[i].rating >= input){
                std::cout << "(" << i << " " << appData[i].name << ") ";
            }
        }
    }
}

void freeAppsByCategory(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << "Select a category" << std::endl;
    for (int i = 0; i < numberOfCategories; i++){
        std::cout << "(" << i << " " << categories[i] << ")" << "   ";
    }
    std::cout << std::endl;
    int selection = 0;
    std::cin >> selection;
    std::string categorySelection = categories[selection];
    for (int i = 1; i < size; i++){
        std::string tempString = appData[i].category;
        if (categorySelection == tempString){
            std::string typeString = appData[i].type;
            if(typeString == "Free"){
                std::cout << "(" << i << " " << appData[i].name << ")" << "   ";
            }
        }
    }
    system ("pause");
    displayMainMenu(appData, size, categories, numberOfCategories);
}

void appsByCategory(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << "Select a category" << std::endl;
    for (int i = 0; i < numberOfCategories; i++){
        std::cout << "(" << i << " " << categories[i] << ")" << "   ";
    }
    std::cout << std::endl;
    int selection = 0;
    std::cin >> selection;
    std::string categorySelection = categories[selection];
    for (int i = 1; i < size; i++){
        std::string tempString = appData[i].category;
        if(tempString == categorySelection){
            std::cout << "(" << i << " " << appData[i].name << ")" << "   ";
        }
    }
    system("pause");
    displayMainMenu(appData, size, categories, numberOfCategories);
}

void categoryStats(app* appData, int size, std::string* categories, int numberOfCategories){
    for (int i = 0; i < numberOfCategories; i++){
        int numberOfAppsGreaterThanFourStars = 0;
        double percentageOfFreeApps = 0;
        double percentOfAppsLessThanAYearOld = 0;
        std::string currentCategory = categories[i];
        int numberOfAppsInCategory = 0;
        for (int r = 1; r < size; r++){
            std::string comparedCategory = appData[r].category;
            if (comparedCategory == currentCategory){
                double rating = appData[r].rating;
                numberOfAppsInCategory++;
                if (rating < 0){
                    rating = rating * -1;
                }
                if (rating > 4.001){
                    numberOfAppsGreaterThanFourStars++;
                }
                if (appData[r].type == "Free"){
                    percentageOfFreeApps = percentageOfFreeApps + 1;
                }
                if (appData[r].lastUpdated.year > 18){
                    percentOfAppsLessThanAYearOld = percentOfAppsLessThanAYearOld + 1;
                }
            }
        }
        percentageOfFreeApps = round((percentageOfFreeApps / numberOfAppsInCategory) * 100.0);
        percentOfAppsLessThanAYearOld = round((percentOfAppsLessThanAYearOld / numberOfAppsInCategory) * 100.0);
        std::cout << categories[i] << "\t" << numberOfAppsGreaterThanFourStars << " apps > 4 stars,\t"
                  << percentageOfFreeApps << "% free apps, \t" << percentOfAppsLessThanAYearOld
                  << "% of apps updated since 2018." << std::endl;
    }
}

void searchByNameMenu(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << "Please enter keyword:" << std::endl;
    std::string search;
    std::cin >> search;
    searchByName(appData, search, size);
    displayMainMenu(appData, size, categories, numberOfCategories);
}

void searchByName(app* appData, std::string search, int size){
    std::cout << "Searching..." << std::endl;
    for(int i = 1; i < size; i++){
        int foundSearchAt;
        foundSearchAt = appData[i].name.find(search);
        if (foundSearchAt >= 0){
            int entry = i;
            displayNameAndEntry(appData, entry);
        }
    }
    std::cout << "End Of Search." << std::endl;
    system("pause");
}

void displayNameAndEntry(app* appData, int entry){
    std::cout << std::setw(10) << std::left << entry << appData[entry].name << std::endl;
}

void searchBySelectionMenu(app* appData, int size, std::string* categories, int numberOfCategories){
    std::cout << std::endl << std::endl << "Enter selection: " << std::endl;
    int selection;
    std::cin >> selection;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid selection, please try again." << std::endl;
        std::cin >> selection;
    }
    searchBySelection(appData, selection);
    displayMainMenu(appData, size, categories, numberOfCategories);
}

std::string returnSizeToMB(long input){
    std::string output;
    if (input >= 1000000000){
        int gigaBytes = round(input / 1000000000);
        output = std::to_string (gigaBytes);
        output.append("GB");
    } else if (input >= 1000000){
        int megaBytes = round(input / 1000000);
        output = std::to_string(megaBytes);
        output.append("MB");
    } else if (input >= 1000){
        int kiloBytes = round(input / 1000);
        output = std::to_string (kiloBytes);
        output.append("KB");
    } else {
        std::stringstream outStream(output);
        output = std::to_string (input);
        output.append("BT");
    }
    return output;
}

void searchBySelection(app* appData, int selection){
    displaySelection(appData, selection);
    system("pause");
}

void displaySelection(app* appData, int selection){
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "NAME: " << appData[selection].name << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "Rating: " << appData[selection].rating
              << " " << "Category: " << appData[selection].category << std::endl; //Size, Rating, Category
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "Type: " << appData[selection].type << " " << "Price: $" << appData[selection].price << " "
              << " " << "Rating: " << appData[selection].rating << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "Number of Installs: " << appData[selection].numberInstalls << "+" << " " << "Number of Reviews: "
              << appData[selection].numberReviews << std::endl; //Number Installs, Number Reviews
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "App Size: " << returnSizeToMB(appData[selection].appSize) << " " << "Content Rating: " << appData[selection].contentRating
              << " " << std::endl;//type, content rating
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "Current App Version: " << appData[selection].currentAppVersion << " " << "Android Version: "
              << appData[selection].androidVersion << std::endl; //currentAppVersion, Android Ver
    std::cout << "----------------------------------------------------------------------" << std::endl; //70 characters
    std::cout << "Date App Last Updated: " << appData[selection].lastUpdated.month << "/" << appData[selection].lastUpdated.day
              << "/" << appData[selection].lastUpdated.year<< std::endl;
}

int findNumberOfCategories(app* appData, int size, std::string categories[150]){
    int outputTracker = 0;
    std::string tempString;
    for (int entry = 1; entry < size; entry++){
        tempString = appData[entry].category;
        int foundMatchingCategories = 0;
        for (int searcher = 0; searcher < 150; searcher++){
            std::string comparer = categories[searcher];
            if (tempString == comparer){
                foundMatchingCategories++;
            }
        }
        if (foundMatchingCategories == 0){
            categories[outputTracker] = tempString;
            outputTracker++;
        }
    }
    writeToLog("Found Number Of Categories", 0);
    return outputTracker;
}

void findCategories(app* appData, int size, std::string* categories, int numberOfCategories){
    int outputTracker = 0;
    std::string tempString;
    for (int entry = 1; entry < size; entry++){
        tempString = appData[entry].category;
        int foundMatchingCategories = 0;
        for (int searcher = 0; searcher < numberOfCategories; searcher++){
            std::string comparer = categories[searcher];
            if (tempString == comparer){
                foundMatchingCategories++;
            }
        }
        if (foundMatchingCategories == 0){
            categories[outputTracker] = tempString;
            outputTracker++;
        }
    }
    std::ofstream categorieslog;
    categorieslog.open("categories.txt", std::ios::app);
    for (int i = 0; i < numberOfCategories; i++){
        std::string categoriesLogEntry = categories[i];
        categorieslog << categoriesLogEntry << std::endl;
    }
    writeToLog("Created Categories Array", 0);
}
