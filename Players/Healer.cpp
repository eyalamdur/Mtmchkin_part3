#include "Healer.h"

/* C'tor of Healer class - 1 param.
 * @param name - The name of the Healer.
 * @return a new instance of Healer. */
Healer::Healer(std::string name){
    this->setForce(DEFAULT_FORCE);
    this->setMaxHP(DEFAULT_MAX_HP);
    this->setName(name);
    this->setLevel(DEFAULT_LEVEL);
    this->setHP(DEFAULT_MAX_HP);
    this->setCoins(DEFAULT_COINS);
    return;
}

/* Operator << of Healer class.
 * @param std::ostream& - reference to ostream object.
 * @return a new instance of ostream. */
std::ostream& operator<<(std::ostream& os, const Healer& healer){
    return healer.printInfo(os);
}

/* Prints the Healer info*/
std::ostream& Healer::printInfo(std::ostream& os) const{
    return os << this->getName() << " " << "Healer";
}

/* Increase the Healer HP by given ammount (up to the maximum allowed HP - maxHP)
 * @param healthPoints - The intented health points to give to the Healer.
 * If Healer has full HP or gets invalid param - nothing changed. */
void  Healer::heal(int healthPoints){
    // Exception check
    if (healthPoints < MINIMUM_VALUE){
        throw ("Focuk");
    }

    if (healthPoints + this->getHP() < this->getMaxHP()){
        this->setHP(this->getHP() + (DOUBLE * healthPoints));
    }
    else{
        this->setHP(this->getMaxHP());
    }
    return;
}