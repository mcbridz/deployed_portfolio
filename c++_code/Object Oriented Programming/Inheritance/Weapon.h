#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include <string>

class Weapon : public Item
{
private:
    int damage;
public:
    /**
     * @brief Weapon Creates a weapon based on parameter values.
     * @param name String name of weapon.
     * @param damageValue Damage value the weapon can deal.
     * @param cost Integer value of weapon value.
     */
    Weapon (std::string name, int damageValue, int cost);
    /**
     * @brief toString Outputs all relevant member data as a string.
     * @return Returns string of data.
     */
    virtual std::string toString() override;
    /**
     * @brief getDamage Returns amount of damage the weapon can deal.
     * @return Integer value of weapon's damage.
     */
    int getDamage() const;
    /**
     * @brief getRange Returns effective range of weapon.
     * @return Returns integer value of weapon's range.
     */
    virtual int getRange();
    /**
     * @brief use Attacks with weapon called.
     * @param rangeToTarget Integer value of range to target.
     * @return Damage exerted to target.
     */
    virtual int use(int range);
};


#endif // WEAPON_H
