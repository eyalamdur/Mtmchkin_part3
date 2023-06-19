#include "Dragon.h"

/* C'tor of Dragon class
 * @param type - The type of the Dragon.
 * @param stats - The numeral stats of the Dragon.
 * @return A new instance of Dragon.*/
Dragon::Dragon(){
    this->setForce(DRAGON_DEFAULT_FORCE);
    this->setLoot(DRAGON_DEFAULT_LOOT);
    this->setHPLossOnDefeat(DRAGON_DEFAULT_HPLOSS);
}

/* Handling the player's applyEncounter with the Dragon:
 * @param player - The player.
 * @return void */
void Dragon::applyEncounter(Player& player) const{
    if (this->getForce() <= player.getAttackStrength()){
        player.levelUp();
        player.addCoins(this->getLoot());
        printWinBattle(player.getName(), DRAGON);
        return;
    }
    player.damage(this->getHPLossOnDefeat());
    printLossBattle(player.getName(), DRAGON);
    return;
}

std::ostream& operator<<(std::ostream& os, const Dragon& dragon){
    return dragon.printInfo(os);
}

/* Prints the Dragon info*/
std::ostream& Dragon::printInfo(std::ostream& os) const{
    printCardDetails(os, DRAGON);
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), true);
    printEndOfCardDetails(os);
    return os;
}