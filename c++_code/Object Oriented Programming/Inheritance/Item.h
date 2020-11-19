#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
private:
    std::string name;
    int value;
public:    
    /**
     * @brief Item Constructor for Item class object
     * @param name String name
     * @param cost Integer cost
     */
    Item (std::string name, int cost);
    /**
     * @brief getName Outputs name as string.
     * @return String output of data.
     */
    std::string getName() const;
    /**
     * @brief getValue Return value of item.
     * @return Integer value
     */
    int getValue() const;
    /**
     * @brief toString Outputs all relevant member data as a string.
     * @return String output of data
     */
    virtual std::string toString();
};


#endif // ITEM_H
