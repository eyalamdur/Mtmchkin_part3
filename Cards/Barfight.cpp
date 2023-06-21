#include "Barfight.h"

/* Handling the player's applyEncounter with the Barfight:
 * @param player - The player.
 * @return void */
void Barfight::applyEncounter(Player& player) const{
    // The player is a Warrior, aplly the Warrior's Encounter
    if (dynamic_cast<Warrior*>(&player)) {
        printBarfightMessage(true);
    } 
    // The player is not a Warrior, aplly the Player's Encounter
    else {
        printBarfightMessage(false);
        player.damage(this->DEFAULT_HEALTH_POINTS_DECREASE);
    }
    return;
}

std::ostream& operator<<(std::ostream& os, const Barfight& barfight){
    return barfight.printInfo(os);
}

/* Prints the Barfight info*/
std::ostream& Barfight::printInfo(std::ostream& os) const{
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
    return os;
}