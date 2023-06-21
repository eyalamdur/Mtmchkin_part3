#include "Witch.h"

/* C'tor of Witch class
 * @param type - The type of the Witch.
 * @param stats - The numeral stats of the Witch.
 * @return A new instance of Witch.*/
Witch::Witch(){
    this->setForce(WITCH_FORCE);
    this->setLoot(BattleCard::WITCH_FORCE);
    this->setHPLossOnDefeat(WITCH_HPLOSS);
}

std::ostream& operator<<(std::ostream& os, const Witch& witch){
    return witch.printInfo(os);
}

/* Prints the Witch info*/
std::ostream& Witch::printInfo(std::ostream& os) const{
    printCardDetails(os, "Witch");
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}