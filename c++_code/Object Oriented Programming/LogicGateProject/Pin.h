/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#ifndef PIN_H
#define PIN_H

#include "Component.h"
#include <sstream>

class Pin : public Component{
private:
    bool value;
    std::string label;
public:
    Pin(std::string);
    virtual ~Pin();
    virtual bool getOutput() const override;
    void setValue(bool);
    void linearPrint() const override;
    void prettyPrint(std::string) const override;
    virtual std::stringstream linearPrintStream() const override;
};

#endif // PIN_H
