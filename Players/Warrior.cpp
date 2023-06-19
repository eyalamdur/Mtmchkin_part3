#include "Warrior.h"

/* C'tor of Warrior class - 1 param.
 * @param name - The name of the Warrior.
 * @return a new instance of Warrior. */
Warrior::Warrior(std::string name){
    this->setForce(DEFAULT_FORCE);
    this->setMaxHP(DEFAULT_MAX_HP);
    this->setName(name);
    this->setLevel(DEFAULT_LEVEL);
    this->setHP(DEFAULT_MAX_HP);
    this->setCoins(DEFAULT_COINS);
    return;
}

/* Operator << of Warrior class.
 * @param std::ostream& - reference to ostream object.
 * @return a new instance of ostream. */
std::ostream& operator<<(std::ostream& os, const Warrior& warrior){
    return warrior.printInfo(os);
}

/* Prints the Warrior info*/
std::ostream& Warrior::printInfo(std::ostream& os) const{
    printPlayerDetails(os, this->getName(),"Warrior", this->getLevel(), this->getForce(), this->getHP(), this->getCoins());
    return os;
}

/* Calculate the Warrior attack strength (2 * force + level).
 * @return the calculated attack strngth. */
int  Warrior::getAttackStrength() const{
    return (DOUBLE * this->getForce()) + this->getLevel();
}