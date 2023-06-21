#include "Merchant.h"

/* Handling the player's applyEncounter with the Merchant:
 * @param player - The player.
 * @return void */
void Merchant::applyEncounter(Player& player) const{
    char playerInput[10];
    while (true){
        std::cin.getline(playerInput, 10);
        switch (Merchant::PlayerChoise(std::stoi(playerInput, nullptr))){
            case Merchant::PlayerChoise::LEAVE:
                return;
            case Merchant::PlayerChoise::HEALTH_POTION:
                if(player.pay(HEALTH_POTION_PRICE)){
                    player.heal(ONE_POINT);
                    break;
                }
                return;
            case Merchant::PlayerChoise::FORCE_BOOST:
                if(player.pay(FORCE_BOOST_PRICE)){
                    player.buff(ONE_POINT);
                    break;
                }
                return;
        }
        printInvalidInput();
    }
    
    return;
}

std::ostream& operator<<(std::ostream& os, const Merchant& Merchant){
    return Merchant.printInfo(os);
}

/* Prints the Mana info*/
std::ostream& Merchant::printInfo(std::ostream& os) const{
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
    return os;
}