#include "Dragon.h"

/* C'tor of Dragon class
 * @param type - The type of the Dragon.
 * @param stats - The numeral stats of the Dragon.
 * @return A new instance of Dragon.*/
Dragon::Dragon(){
    this->setForce(DRAGON_FORCE);
    this->setLoot(DRAGON_LOOT);
    this->setHPLossOnDefeat(DRAGON_HPLOSS);
}

std::ostream& operator<<(std::ostream& os, const Dragon& dragon){
    return dragon.printInfo(os);
}

/* Prints the Dragon info*/
std::ostream& Dragon::printInfo(std::ostream& os) const{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), true);
    printEndOfCardDetails(os);
    return os;
}