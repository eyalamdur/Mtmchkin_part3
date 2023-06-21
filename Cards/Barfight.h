#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    /* C'tor of Barfight class
     * @return A new instance of Barfight.*/
    Barfight() = default;

    /* Handling the player's applyEncounter with the Barfight:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Barfight info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Barfight& barfight);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Barfight(const Barfight&) = default;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& other) = default;

    const static int DEFAULT_HEALTH_POINTS_DECREASE = 10;
};


#endif //EX4_BARFIGHT_H
