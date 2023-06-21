#ifndef EX4_NINJA_H
#define EX4_NINJA_H

#include "Player.h"
#include "../utilities.h"

const std::string NINJA = "Ninja";

class Ninja : public Player {
public:
    /* C'tor of Ninja class - 1 param.
     * @param name - The name of the Ninja.
     * @return a new instance of Ninja. */
    Ninja(std::string name);

    /* D'tor of Ninja class. */
    ~Ninja() = default;

    /* Copy of Ninja class.
     * @param Ninja& - reference to another Ninja object.
     * @return a new instance of Ninja with copied values as the given Ninja. */
    Ninja(const Ninja&) = default;

    /* Assigning of Ninja class.
     * @param Ninja& - reference to another Ninja object.
     * @return a new instance of Ninja with copied values as the given Ninja. */
    Ninja& operator=(const Ninja& other) = default;

    /* Operator << of Ninja class.
     * @param std::ostream& - reference to ostream object.
     * @return a new instance of ostream. */
    friend std::ostream& operator<<(std::ostream& os, const Ninja& ninja);

    /* Prints the Ninja info*/
    std::ostream& printInfo(std::ostream& os) const override;

    /* Increase the Ninja coins by 2 * given ammount.
     * @param coins - The intented coins points to add to the Ninja. */
    void addCoins(int coins) override;

};

#endif //EX4_NINJA_H
