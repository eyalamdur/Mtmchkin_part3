#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

const std::string DRAGON = "Dragon";
const int DRAGON_DEFAULT_LOOT = 1000;
const int DRAGON_DEFAULT_FORCE = 25;
const int DRAGON_DEFAULT_HPLOSS = 100;

class Dragon : BattleCard {
public:
    /* C'tor of Dragon class
     * @param type - The type of the Dragon.
     * @param stats - The numeral stats of the Dragon.
     * @return A new instance of Dragon.*/
    Dragon();

    /* Handling the player's applyEncounter with the Dragon:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Dragon info:*/
    friend std::ostream& operator<<(std::ostream& os, const Dragon& dragon);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;
};


#endif //EX4_DRAGON_H
