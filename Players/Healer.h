#ifndef EX4_HEALER_H
#define EX4_HEALER_H

#include "Player.h"
#include "../utilities.h"

class Healer : Player {
public:
    /* C'tor of Healer class - 1 param.
     * @param name - The name of the Healer.
     * @return a new instance of Healer. */
    Healer(std::string name);

    /* D'tor of Healer class. */
    ~Healer() = default;

    /* Copy of Healer class.
     * @param Healer& - reference to another Healer object.
     * @return a new instance of Healer with copied values as the given Healer. */
    Healer(const Healer&) = default;

    /* Assigning of Healer class.
     * @param Healer& - reference to another Healer object.
     * @return a new instance of Healer with copied values as the given Healer. */
    Healer& operator=(const Healer& other) = default;

    /* Operator << of Healer class.
     * @param std::ostream& - reference to ostream object.
     * @return a new instance of ostream. */
    friend std::ostream& operator<<(std::ostream& os, const Healer& healer);

    /* Prints the Healer info*/
    std::ostream& printInfo(std::ostream& os) const override;

    /* Increase the Healer HP by (2 * given ammount) (up to the maximum allowed HP - maxHP)
     * @param healthPoints - The intented health points to give to the player.
     * If player has full HP or gets invalid param - nothing changed. */
    virtual void heal(int healthPoints) override;
};

#endif //EX4_HEALER_H
