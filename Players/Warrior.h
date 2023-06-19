#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H

#include "Player.h"

class Warrior : Player {
public:
    /* C'tor of Warrior class - 1 param.
     * @param name - The name of the Warrior.
     * @return a new instance of Warrior. */
    Warrior(std::string name);

    /* D'tor of Warrior class. */
    ~Warrior() = default;

    /* Copy of Warrior class.
     * @param Warrior& - reference to another Warrior object.
     * @return a new instance of Warrior with copied values as the given Warrior. */
    Warrior(const Warrior&) = default;

    /* Assigning of Warrior class.
     * @param Warrior& - reference to another Warrior object.
     * @return a new instance of Warrior with copied values as the given Warrior. */
    Warrior& operator=(const Warrior& other) = default;

    /* Operator << of Warrior class.
     * @param std::ostream& - reference to ostream object.
     * @return a new instance of ostream. */
    friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);

    /* Prints the Warrior info*/
    std::ostream& printInfo(std::ostream& os) const override;

    /* Calculate the Warrior attack strength (2 * force + level).
     * @return the calculated attack strngth. */
    int getAttackStrength() const override;

};

#endif //EX4_WARRIOR_H
