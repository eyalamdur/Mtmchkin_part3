#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "BattleCard.h"

const std::string WITCH = "Witch";
const int WITCH_DEFAULT_LOOT = 3;
const int WITCH_DEFAULT_FORCE = 12;
const int WITCH_DEFAULT_HPLOSS = 10;

class Witch : BattleCard {
public:
    /* C'tor of Witch class
     * @param type - The type of the Witch.
     * @param stats - The numeral stats of the Witch.
     * @return A new instance of Witch.*/
    Witch();

    /* Handling the player's applyEncounter with the Witch:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Witch info:*/
    friend std::ostream& operator<<(std::ostream& os, const Witch& witch);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Witch(const Witch&) = default;
    ~Witch() = default;
    Witch& operator=(const Witch& other) = default;
};


#endif //EX4_WITCH_H
