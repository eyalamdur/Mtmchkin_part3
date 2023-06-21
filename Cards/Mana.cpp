#include "Mana.h"

/* Handling the player's applyEncounter with the Mana:
 * @param player - The player.
 * @return void */
void Mana::applyEncounter(Player& player) const{
    // The player is a Healer, aplly the Healer's Encounter
    if (dynamic_cast<Healer*>(&player)) {
        printManaMessage(true);
        player.heal(this->DEFAULT_HEAL);
    } 
    // The player is not a Healer, aplly the Player's Encounter
    else {
        printManaMessage(false);
    }
    return;
}

std::ostream& operator<<(std::ostream& os, const Mana& mana){
    return mana.printInfo(os);
}

/* Prints the Mana info*/
std::ostream& Mana::printInfo(std::ostream& os) const{
    printCardDetails(os, "Mana");
    printEndOfCardDetails(os);
    return os;
}