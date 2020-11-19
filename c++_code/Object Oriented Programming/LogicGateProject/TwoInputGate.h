#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H

#include <memory>
#include "Component.h"

//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};

/*
  * @brief Assignment 8
   * @author Zachary McBride
  */
class TwoInputGate : public Component{
private:
    std::shared_ptr<Component> input1;
    std::shared_ptr<Component> input2;
    LogicOperation gateType;
public:
    TwoInputGate(LogicOperation);
    virtual bool getOutput() const override;
    void setInput1(std::shared_ptr<Component>);
    void setInput2(std::shared_ptr<Component>);
    virtual void prettyPrint(std::string) const override;
    virtual void linearPrint() const override;
    virtual std::stringstream linearPrintStream() const override;
    void setType(LogicOperation);
};



#endif // TWOINPUTGATE_H
