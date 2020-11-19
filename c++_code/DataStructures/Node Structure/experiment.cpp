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

    cout << page1.getRandomLink() << endl;
    cout << page1.getNumLinks() << endl;
    cout << page2.getRandomLink() << endl;
}
