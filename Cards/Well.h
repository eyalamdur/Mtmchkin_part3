#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"

class Well : public Card {
public:
    /* C'tor of Well class
     * @return A new instance of Well.*/
    Well() = default;

    /* Handling the player's applyEncounter with the Well:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Well info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Well& well);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Well(const Well&) = default;
    ~Well() = default;
    Well& operator=(const Well& other) = default;

    const static int DEFAULT_HEALTH_POINTS_DECREASE = 10;
};


#endif //EX4_WELL_H
