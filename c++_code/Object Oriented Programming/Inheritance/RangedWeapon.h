#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H
#include "Weapon.h"

class RangedWeapon : public Weapon{
private:
    int range;
    int ammo;
public:
    /**
     * @brief RangedWeapon Constructor for Ranged Weapon class object
     * @param name String name
     * @param damageValue Integer damage value
     * @param rangeValue Integer range value
     * @param ammoValue Integer ammo value
     * @param cost Integer cost value
     */
    RangedWeapon(std::string name, int damageValue, int rangeValue, int ammoValue, int cost);
    /**
     * @brief toString Outputs all relevant member data as a string.
     * @return Returns string data.
     */
    virtual std::string toString() override;
    /**
     * @brief getRange Returns range of ranged weapon
     * @return Returns integer value of range.
     */
    virtual int getRange() override;
    /**
     * @brief getAmmo Returns ammo remaining to ranged weapon.
     * @return Returns integer value of ammo.
     */
    int getAmmo() const;
    /**
     * @brief use Attacks with weapon called.
     * @param rangeToTarget Integer value of range to target.
     * @return Damage exerted to target.
     */
    virtual int use(int rangeToTarget) override;
};




#endif // RANGEDWEAPON_H
