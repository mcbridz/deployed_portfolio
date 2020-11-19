#ifndef PAGE_H
#define PAGE_H
#include <iostream>

class Page
{
    //Private members enumerated
    private:

    std::string url;
    int visits;
    Page* links[3];
    int usedLinks;

    //public members enumerated
    public:

    //constructors
    Page();
    Page(std::string urlValue);

    //member functions
    std::string getURL();
    int getNumLinks();
    Page* getRandomLink();
    void addLink(Page* other);
    void visit();
    int getNumVisits();
};


#endif // PAGE_H
