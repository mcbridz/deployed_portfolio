/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <sstream>

class Component{
public:
    virtual bool getOutput() const = 0;
    virtual void prettyPrint(std::string) const = 0;
    virtual void linearPrint() const = 0;
    virtual std::stringstream linearPrintStream() const = 0;
    virtual ~Component(){};
};

#endif // COMPONENT_H
