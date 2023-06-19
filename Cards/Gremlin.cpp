#include "Gremlin.h"

/* C'tor of Gremlin class
 * @param type - The type of the Gremlin.
 * @param stats - The numeral stats of the Gremlin.
 * @return A new instance of Gremlin.*/
Gremlin::Gremlin(){
    this->setForce(GREMLIN_DEFAULT_FORCE);
    this->setLoot(GREMLIN_DEFAULT_LOOT);
    this->setHPLossOnDefeat(GREMLIN_DEFAULT_HPLOSS);
}

/* Handling the player's applyEncounter with the Gremlin:
 * @param player - The player.
 * @return void */
void Gremlin::applyEncounter(Player& player) const{
    if (this->getForce() <= player.getAttackStrength()){
        player.levelUp();
        player.addCoins(this->getLoot());
        printWinBattle(player.getName(), GREMLIN);
        return;
    }
    player.damage(this->getHPLossOnDefeat());
    printLossBattle(player.getName(), GREMLIN);
    return;
}

std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin){
    return gremlin.printInfo(os);
}

/* Prints the Gremlin info*/
std::ostream& Gremlin::printInfo(std::ostream& os) const{
    printCardDetails(os, GREMLIN);
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}