#include "Treasure.h"

/* C'tor of Treasure class
 * @param type - The type of the Treasure.
 * @param stats - The numeral stats of the Treasure.
 * @return A new instance of Treasure.*/
Treasure::Treasure(int loot){
    this->m_loot = loot;
}

/* Handling the player's applyEncounter with the Treasure:
 * @param player - The player.
 * @return void */
void Treasure::applyEncounter(Player& player) const{
    player.addCoins(this->m_loot);
    printTreasureMessage();
    return;
}

std::ostream& operator<<(std::ostream& os, const Treasure& treasure){
    return treasure.printInfo(os);
}

/* Prints the Mana info*/
std::ostream& Treasure::printInfo(std::ostream& os) const{
    printCardDetails(os, "Treasure");
    printEndOfCardDetails(os);
    return os;
}