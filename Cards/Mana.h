#ifndef EX4_MANA_H
#define EX4_MANA_H

#include "Card.h"

class Mana : public Card {
public:
    /* C'tor of Mana class
     * @return A new instance of Mana.*/
    Mana() = default;

    /* Handling the player's applyEncounter with the Mana:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Mana info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Mana& mana);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Mana(const Mana&) = default;
    ~Mana() = default;
    Mana& operator=(const Mana& other) = default;

    const static int DEFAULT_HEAL = 10;

};


#endif //EX4_MANA_H
