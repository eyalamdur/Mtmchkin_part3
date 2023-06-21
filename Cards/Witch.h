#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "BattleCard.h"

class Witch : public BattleCard {
public:
    /* C'tor of Witch class
     * @param type - The type of the Witch.
     * @param stats - The numeral stats of the Witch.
     * @return A new instance of Witch.*/
    Witch();

    /* Prints the Witch info:*/
    friend std::ostream& operator<<(std::ostream& os, const Witch& witch);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Witch(const Witch&) = default;
    ~Witch() = default;
    Witch& operator=(const Witch& other) = default;

    const int WITCH_LOOT = 2;
    const int WITCH_HPLOSS = 10;
};


#endif //EX4_WITCH_H
