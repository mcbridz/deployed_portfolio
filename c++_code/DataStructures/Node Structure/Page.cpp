#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "Page.h"

using namespace std;
Page* null = nullptr;

//empty constructor
Page::Page() {
    url = "";
    visits = 0;
    usedLinks = 0;
    links[0] = null;
    links[1] = null;
    links[2] = null;
}
//full constructor
Page::Page(string urlValue){
    url = urlValue;
    visits = 0;
    usedLinks = 0;
    links[0] = null;
    links[1] = null;
    links[2] = null;
}


//member functions
string Page::getURL(){
    return url;
}
int Page::getNumLinks(){
    return usedLinks;
}
Page* Page::getRandomLink(){
    srand (time(NULL));
    int randomLinkInt = rand() % 3;
    return links[randomLinkInt];
}
void Page::addLink(Page* other){
    if (usedLinks == 3){
        throw invalid_argument("Page Links Maxed Out");
    }
    links[getNumLinks()] = other;
    usedLinks++;
}
void Page::visit(){
    visits++;
}
int Page::getNumVisits(){
    return visits;
}
