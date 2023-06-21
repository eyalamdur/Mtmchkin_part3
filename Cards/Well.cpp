#include "Well.h"

/* Handling the player's applyEncounter with the Well:
 * @param player - The player.
 * @return void */
void Well::applyEncounter(Player& player) const{
    // The player is a Ninja, aplly the Ninja's Encounter
    if (dynamic_cast<Ninja*>(&player)) {
        printWellMessage(true);
    } 
    // The player is not a Ninja, aplly the Player's Encounter
    else {
        printWellMessage(false);
        player.damage(this->DEFAULT_HEALTH_POINTS_DECREASE);
    }
    return;
}

std::ostream& operator<<(std::ostream& os, const Well& well){
    return well.printInfo(os);
}

/* Prints the Well info*/
std::ostream& Well::printInfo(std::ostream& os) const{
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
    return os;
}