#include "Gremlin.h"

/* C'tor of Gremlin class
 * @param type - The type of the Gremlin.
 * @param stats - The numeral stats of the Gremlin.
 * @return A new instance of Gremlin.*/
Gremlin::Gremlin(){
    this->setForce(GREMLIN_FORCE);
    this->setLoot(GREMLIN_LOOT);
    this->setHPLossOnDefeat(GREMLIN_HPLOSS);
}

std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin){
    return gremlin.printInfo(os);
}

/* Prints the Gremlin info*/
std::ostream& Gremlin::printInfo(std::ostream& os) const{
    printCardDetails(os, "Gremlin");
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}