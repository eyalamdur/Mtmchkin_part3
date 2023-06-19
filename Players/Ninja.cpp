#include "Ninja.h"

/* C'tor of Ninja class - 1 param.
 * @param name - The name of the Ninja.
 * @return a new instance of Ninja. */
Ninja::Ninja(std::string name){
    this->setForce(DEFAULT_FORCE);
    this->setMaxHP(DEFAULT_MAX_HP);
    this->setName(name);
    this->setLevel(DEFAULT_LEVEL);
    this->setHP(DEFAULT_MAX_HP);
    this->setCoins(DEFAULT_COINS);
    return;
}

/* Operator << of Ninja class.
 * @param std::ostream& - reference to ostream object.
 * @return a new instance of ostream. */
std::ostream& operator<<(std::ostream& os, const Ninja& ninja){
    return ninja.printInfo(os);
}

/* Prints the Ninja info*/
std::ostream& Ninja::printInfo(std::ostream& os) const{
    printPlayerDetails(os, this->getName(),"Ninja", this->getLevel(), this->getForce(), this->getHP(), this->getCoins());
    return os;
}

/* Increase the Ninja coins by given ammount.
 * @param coins - The intented coins points to add to the Ninja. */
void Ninja::addCoins(int coins){
    // Exception check
    if (coins < MINIMUM_VALUE){
        throw ("Focuk");
    }

    this->setCoins(this->getCoins() + (DOUBLE * coins));
    return;
}