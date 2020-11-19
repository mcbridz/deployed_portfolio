/*
  * @brief Assignment 9
   * @author Zachary McBride
  */
#ifndef ANDROID_H
#define ANDROID_H

#include <string>

struct date{
    int month;
    int day;
    int year;
};

struct header{
    std::string name;
    std::string category;
    std::string rating;
    std::string numberReviews;
    std::string appSize;
    std::string numberInstalls;
    std::string type;
    std::string price;
    std::string contentRating;
    std::string genre;
    std::string lastUpdated;
    std::string currentAppVersion;
    std::string androidVersion;
};

struct tempApp{
    std::string name;
    std::string category;
    std::string rating;
    std::string numberReviews;
    std::string appSize;
    std::string numberInstalls;
    std::string type;
    std::string price;
    std::string contentRating;
    std::string genre;
    std::string lastUpdated;
    std::string currentAppVersion;
    std::string androidVersion;
};

struct app{
    std::string name;
    std::string category;
    double rating;
    long int numberReviews;
    long int appSize;
    int numberInstalls;
    std::string type;
    double price;
    std::string contentRating;
    std::string genre;
    date lastUpdated;
    std::string currentAppVersion;
    std::string androidVersion;
};

void writeToLog(std::string message, int entry);

void readInColumnHeaders(header& output, std::string input);

void readInData(std::string tempString, tempApp* tempAppData, app* appData, int entry);

std::string removeQuotes(std::string tempString);

void makeTempAppData(std::string tempString, tempApp* tempAppData, int entry);

void transferTempToMainData(tempApp* tempAppData, app* appData, int entry);

void transferRatingData(tempApp* tempAppData, app* appData, int entry);

void convertAppSize(tempApp* tempAppData, app* appData, int entry);

void convertNumberInstalls(tempApp* tempAppData, app* appData, int entry);

void convertDate(tempApp* tempAppData, app* appData, int entry);

std::string returnSizeToMB(long int input);

void displayMainMenu(app* appData, int size, std::string* categories, int numberOfCategories);

void searchByAppSize();

void searchBySelection(app* appData, int selection);

void displaySelection(app* appData, int selection);

int howBigIsFile(std::string filename);

void getUserInput(app* appData, int size, std::string* categories, int numberOfCategories);

void searchBySelectionMenu(app* appData, int size, std::string* categories, int numberOfCategories);

void searchByNameMenu(app* appData, int size, std::string* categories, int numberOfCategories);

void searchByCategoryMenu(app* appData, int size, std::string* categories, int numberOfCategories);

void searchByPriceMenu(app* appData);

void searchByAppSizeMenu(app* appData, int size);

int findNumberOfCategories(app* appData, int size, std::string categories[150]);

void findCategories(app* appData, int size, std::string* categories, int numberOfCategories);

void getUserInputCategoryMenu(app* appData, int size, std::string* categories, int numberOfCategories);

void freeAppsByCategory(app* appData, int size, std::string* categories, int numberOfCategories);

void appsByCategory(app* appData, int size, std::string* categories, int numberOfCategories);

void categoryStats(app* appData, int size, std::string* categories, int numberOfCategories);

void specifiedSearch(app* appData, int size, std::string* categories, int numberOfCategories);

void getUserSpecifiedSearchInput(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection);

void userSpecifiedSearchByReview(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection);

void userSpecifiedSearchByInstalls(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection);

void userSpecifiedSearchBySize(app* appData, int size, std::string* categories, int numberOfCategories, std::string selection);

long int convertUserSpecifiedSize(std::string input);

void displaySearchMenu();
void searchByCategory();
void searchByRating();
void searchByPrice();
void searchByName(app* appData, std::string search, int size);
void displayNameAndEntry(app* appData, int entry);
void removeCommas();
int monthToNumber();
int howBigIsFile();

#endif // ANDROID_H
