#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <string>

class Armor : public Item {
private:
    int protection;
public:
    /**
     * @brief Armor Constructor for Armor class
     * @param name String name
     * @param protectionValue Integer protection value
     * @param cost Integer cost value
     */
    Armor(std::string name, int protectionValue, int cost);
    /**
     * @brief getProtection Fetch for protection value
     * @return Integer protection value
     */
    int getProtection();
    /**
     * @brief toString Outputs all relevant member data as a string.
     * @return Output string.
     */
    virtual std::string toString() override;
};



#endif // ARMOR_H
