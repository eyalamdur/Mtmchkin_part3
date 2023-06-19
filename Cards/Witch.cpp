#include "Witch.h"

/* C'tor of Witch class
 * @param type - The type of the Witch.
 * @param stats - The numeral stats of the Witch.
 * @return A new instance of Witch.*/
Witch::Witch(){
    this->setForce(WITCH_DEFAULT_FORCE);
    this->setLoot(WITCH_DEFAULT_LOOT);
    this->setHPLossOnDefeat(WITCH_DEFAULT_HPLOSS);
}

/* Handling the player's applyEncounter with the Witch:
 * @param player - The player.
 * @return void */
void Witch::applyEncounter(Player& player) const{
    if (this->getForce() <= player.getAttackStrength()){
        player.levelUp();
        player.addCoins(this->getLoot());
        printWinBattle(player.getName(), WITCH);
        return;
    }
    player.damage(this->getHPLossOnDefeat());
    printLossBattle(player.getName(), WITCH);
    return;
}

std::ostream& operator<<(std::ostream& os, const Witch& witch){
    return witch.printInfo(os);
}

/* Prints the Witch info*/
std::ostream& Witch::printInfo(std::ostream& os) const{
    printCardDetails(os, WITCH);
    printMonsterDetails(os, this->getForce(), this->getHPLossOnDefeat(), this->getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}