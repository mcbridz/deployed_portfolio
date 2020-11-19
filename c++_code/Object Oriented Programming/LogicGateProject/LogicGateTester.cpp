//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Pin.h"
#include "NotGate.h"
#include "TwoInputGate.h"
#include <sstream>
#include <iostream>


/*
  * @brief Assignment 8
   * @author Zachary McBride
  */

using namespace std;


TEST_CASE( "Components/Pin" ) {
    cout << "Pin Only Test..." << endl;    

    shared_ptr<Pin> a(new Pin("A"));
    a->setValue(false);

    REQUIRE(a->getOutput() == false);

    a->setValue(true);
    REQUIRE(a->getOutput() == true);
}
TEST_CASE( "Not Gate"){
    cout << "Testing Not Gate with Pin" << endl;
    shared_ptr<Pin> a(new Pin("A"));
    a->setValue(true);
    shared_ptr<NotGate> b(new NotGate());
    b->setInput(a);
    REQUIRE(b->getOutput() == false);
}
TEST_CASE("Two Input Gate"){
    cout << "Testing Two True Inputs" << endl;
    shared_ptr<Pin> a1(new Pin("A1"));
    a1->setValue(true);
    shared_ptr<Pin> a2(new Pin("A2"));
    a2->setValue(true);
    shared_ptr<TwoInputGate> b(new TwoInputGate(AND));
    b->setInput1(a1);
    b->setInput2(a2);
    REQUIRE(b->getOutput() == true);
    cout << "Alternating False Inputs To Test AND" << endl;
    a2->setValue(false);
    REQUIRE(b->getOutput() == false);
    a2->setValue(true);
    a1->setValue(false);
    REQUIRE(b->getOutput() == false);
    cout << "Testing OR" << endl;
    b->setType(OR);
    REQUIRE(b->getOutput() == true);
    a1->setValue(true);
    REQUIRE(b->getOutput() == true);
    a2->setValue(false);
    REQUIRE(b->getOutput() == true);
    a1->setValue(false);
    REQUIRE(b->getOutput() == false);
    cout << "Testing XOR" << endl;
    b->setType(XOR);
    REQUIRE(b->getOutput() == false);
    a1->setValue(true);
    REQUIRE(b->getOutput() == true);
    a2->setValue(true);
    REQUIRE(b->getOutput() == false);
    a1->setValue(false);
    REQUIRE(b->getOutput() == true);
}
TEST_CASE("Complex Circuit"){
    cout << "Setting Up Complex Gate" << endl;
    shared_ptr<Pin> a(new Pin("A"));
    a->setValue(true);
    shared_ptr<Pin> b(new Pin("B"));
    b->setValue(true);
    shared_ptr<Pin> c(new Pin("C"));
    c->setValue(true);
    shared_ptr<NotGate> d(new NotGate());
    d->setInput(c);
    shared_ptr<TwoInputGate> e(new TwoInputGate(XOR));
    e->setInput1(a);
    e->setInput2(b);
    shared_ptr<TwoInputGate> f(new TwoInputGate(AND));
    f->setInput1(e);
    f->setInput2(d);
    cout << "Testing Pins A-C True" << endl;
    REQUIRE(f->getOutput() == false);
    cout << "Testing Pin B=True, A&C=False" << endl;
    a->setValue(false);
    c->setValue(false);
    REQUIRE(f->getOutput() == true);
    cout << "Testing Pins A-C False" << endl;
    b->setValue(false);
    REQUIRE(f->getOutput() == false);
    cout << "Testing Pins B&C=True and A=False" << endl;
    REQUIRE(f->getOutput() == false);
}
TEST_CASE("LinearPrint"){
    //I've converted all linearPrint() to stringstream type to
    //be able to test it.
    cout << "Testing Linear Print For Simple Gates (I've converted all linearPrint() to stringstream type to"
            " be able to test it.)" << endl;
    stringstream checker1;
    shared_ptr<Pin> a(new Pin("A"));
    checker1 << "A";
    stringstream linearPrint1;
    linearPrint1 = a->linearPrintStream();
    a->linearPrint();
    cout << endl;
    REQUIRE(linearPrint1.str() == checker1.str());
    cout << "Testing Pin with Not Gate" << endl;
    shared_ptr<NotGate> d(new NotGate());
    shared_ptr<Pin> c(new Pin("C"));
    d->setInput(c);
    stringstream checker2;
    checker2 << "~(C)";
    stringstream linearPrint2;
    linearPrint2 = d->linearPrintStream();
    d->linearPrint();
    cout << endl;
    REQUIRE(linearPrint2.str() == checker2.str());
    cout << "Testing Two Pins With A TwoInputGate(XOR)" << endl;
    shared_ptr<TwoInputGate> e(new TwoInputGate(XOR));
    shared_ptr<Pin> b(new Pin("B"));
    e->setInput1(a);
    e->setInput2(b);
    stringstream checker3;
    checker3 << "(A ^ B)";
    stringstream linearPrint3 = e->linearPrintStream();
    e->linearPrint();
    cout << endl;
    REQUIRE(linearPrint3.str() == checker3.str());
    cout << "Testing Linear Print For Complex Gate" << endl;
    shared_ptr<TwoInputGate> f(new TwoInputGate(OR));
    f->setInput1(b);
    f->setInput2(d);
    shared_ptr<TwoInputGate> g(new TwoInputGate(AND));
    g->setInput1(e);
    g->setInput2(f);
    stringstream checker4;
    checker4 << "((A ^ B) && (B || ~(C)))";
    stringstream linearPrint4 = g->linearPrintStream();
    g->linearPrint();
    cout << endl;
    REQUIRE(linearPrint4.str() == checker4.str());
}
TEST_CASE("Pretty Print"){
    cout << "Testing Pretty Print" << endl;
    shared_ptr<Pin> a(new Pin("A"));
    shared_ptr<Pin> b(new Pin("B"));
    shared_ptr<Pin> c(new Pin("C"));
    shared_ptr<NotGate> d(new NotGate());
    shared_ptr<TwoInputGate> e(new TwoInputGate(XOR));
    shared_ptr<TwoInputGate> f(new TwoInputGate(OR));
    shared_ptr<TwoInputGate> g(new TwoInputGate(AND));
    d->setInput(c);
    e->setInput1(a);
    e->setInput2(b);
    f->setInput1(b);
    f->setInput2(d);
    g->setInput1(e);
    g->setInput2(f);
    a->setValue(true);
    b->setValue(true);
    c->setValue(false);
    g->prettyPrint("");
}
