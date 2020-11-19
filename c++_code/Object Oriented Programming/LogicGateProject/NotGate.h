/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
#ifndef NOTGATE_H
#define NOTGATE_H

#include <memory>
#include "Component.h"
#include <sstream>

class NotGate : public Component{
private:
    std::shared_ptr<Component> input;
public:
    NotGate();
    virtual bool getOutput() const override;
    void setInput(std::shared_ptr<Component>);
    virtual void linearPrint() const override;
    virtual void prettyPrint(std::string) const override;
    std::stringstream linearPrintStream() const override;
};

#endif // NOTGATE_H
