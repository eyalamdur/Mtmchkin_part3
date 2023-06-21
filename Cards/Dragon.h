#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    /* C'tor of Dragon class
     * @param type - The type of the Dragon.
     * @param stats - The numeral stats of the Dragon.
     * @return A new instance of Dragon.*/
    Dragon();

    /* Prints the Dragon info:*/
    friend std::ostream& operator<<(std::ostream& os, const Dragon& dragon);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;

    const int DRAGON_LOOT = 1000;
    const int DRAGON_FORCE = 25;
    const int DRAGON_HPLOSS = 100;
};


#endif //EX4_DRAGON_H
