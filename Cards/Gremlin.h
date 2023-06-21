#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H

#include "BattleCard.h"

class Gremlin : public BattleCard {
public:
    /* C'tor of Gremlin class
     * @param type - The type of the Gremlin.
     * @param stats - The numeral stats of the Gremlin.
     * @return A new instance of Gremlin.*/
    Gremlin();

    /* Prints the Gremlin info:*/
    friend std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Gremlin(const Gremlin&) = default;
    ~Gremlin() = default;
    Gremlin& operator=(const Gremlin& other) = default;

    const int GREMLIN_LOOT = 2;
    const int GREMLIN_HPLOSS = 10;
};


#endif //EX4_GREMLIN_H
