#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H

#include "BattleCard.h"

const std::string GREMLIN = "Gremlin";
const int GREMLIN_DEFAULT_LOOT = 2;
const int GREMLIN_DEFAULT_FORCE = 5;
const int GREMLIN_DEFAULT_HPLOSS = 10;

class Gremlin : BattleCard {
public:
    /* C'tor of Gremlin class
     * @param type - The type of the Gremlin.
     * @param stats - The numeral stats of the Gremlin.
     * @return A new instance of Gremlin.*/
    Gremlin();

    /* Handling the player's applyEncounter with the Gremlin:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Gremlin info:*/
    friend std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Gremlin(const Gremlin&) = default;
    ~Gremlin() = default;
    Gremlin& operator=(const Gremlin& other) = default;
};


#endif //EX4_GREMLIN_H
