#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"

/**
 * @brief The Character class represents a player in the game
 */
class Character
{
public:
    /**
     * @brief Character
     * @param nameVal : value for Character's name
     */
    Character(const std::string& nameVal);

    /**
     * @brief print out all the information about the Character
     */
    void print() const;

    /**
     * @brief getHealthPoints
     * @return healthPoints
     */
    int getHealthPoints() const;

    /**
     * @brief takeDamage reduces healthPoints by given amount minus the protection
     *         value of the character's armor (min 0)
     * @param amount : amount of damage to take
     */
    void takeDamage(int amount);

    /**
     * @brief attack use character's weapon on the given character.
     * @param target : Character being attacked
     * @param range : distance to target
     */
    void attack(Character& target, int range);

    /**
     * @brief aquire adds an item to the inventory
     * @param item : item to be added
     * @return true if added, false if no room
     *
     * Note - the Character class does NOT manange the memory of its Inventory.
     * It will not delete them on destruction or properly deep copy the Inventory.
     */
    bool aquire(Item* item);

    /**
     * @brief equip attempts to use an item from the inventory. If it is a weapon,
     *         sets it as the character's weapon. If it is armor, sets it as
     *         the character's armor
     * @param itemNumber : index in the array to equip (0 based index)
     */
    void equip(int itemNumber);

    /**
     * @brief getWeapon
     * @return currently equipped Weapon
     */
    Weapon* getWeapon();

    /**
     * @brief getArmor
     * @return currently equipped Armor
     */
    Armor* getArmor();

private:
    std::string name;
    int healthPoints;

    //Pointers to the currently equiped weapon/armor
    Weapon* weapon;
    Armor* armor;

    //Inventory is an array of 10 pointers to Items
    const static int INVENTORY_SIZE = 10;
    Item* inventory[INVENTORY_SIZE] = {0};

    //Default armor/weapon
    Armor skin = Armor("Skin", 0, 0);
    Weapon hands = Weapon("Bare Hands", 1, 0);
};

#endif // CHARACTER_H
