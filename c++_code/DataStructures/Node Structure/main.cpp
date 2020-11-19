#include <iostream>
#include "Page.h"
#include <iomanip>
#include <string>


using namespace std;

int main()
{
    //construct base webpages
    Page page1("http://page1.edu");
    Page page2("http://page2.edu");
    Page page3("http://page3.edu");
    Page page4("http://page4.edu");
    //construct page pointers
    Page* page1pointer = &page1;
    Page* page2pointer = &page2;
    Page* page3pointer = &page3;
    Page* page4pointer = &page4;
    //connect webpages
    page1.addLink(page2pointer);
    page1.addLink(page3pointer);
    page1.addLink(page4pointer);
    page2.addLink(page1pointer);
    page2.addLink(page3pointer);
    page2.addLink(page4pointer);
    page3.addLink(page1pointer);
    page3.addLink(page2pointer);
    page3.addLink(page4pointer);
    page4.addLink(page1pointer);
    page4.addLink(page2pointer);
    page4.addLink(page3pointer);
    int pageWeAreOn = 1;
    srand (time(NULL));
    for (int i = 0; i < 10000; i++){
        int whatToDo = rand() % 100 + 1;
        Page* goTo;
        if (whatToDo <= 85){
            switch(pageWeAreOn){
            case 1:goTo = page1.getRandomLink(); break;
            case 2:goTo = page2.getRandomLink(); break;
            case 3:goTo = page3.getRandomLink(); break;
            case 4:goTo = page4.getRandomLink(); break;
            case 5:break;
                goTo->visit();
                if (goTo->getURL() == "http://page1.edu"){
                    pageWeAreOn = 1;
                } else if(goTo->getURL() == "http://page2.edu"){
                    pageWeAreOn = 2;
                } else if(goTo->getURL() == "http://page3.edu"){
                    pageWeAreOn = 3;
                } else {
                    pageWeAreOn = 4;
                }
            }
        }
        else {
            int randomRestart = rand() % 4 + 1;
            switch(randomRestart){
            case 1: pageWeAreOn = 1; page1.visit(); break;
            case 2: pageWeAreOn = 2; page2.visit(); break;
            case 3: pageWeAreOn = 3; page3.visit(); break;
            case 4: pageWeAreOn = 4; page4.visit(); break;
            case 5: break;
            }
        }
    }
    cout << page1.getURL() << " " << (page1.getNumVisits() / 10000) * 100 << "%" << endl;
    cout << page2.getURL() << " " << (page2.getNumVisits() / 10000) * 100 << "%" << endl;
    cout << page3.getURL() << " " << (page3.getNumVisits() / 10000) * 100 << "%" << endl;
    cout << page4.getURL() << " " << (page4.getNumVisits() / 10000) * 100 << "%" << endl;

}
