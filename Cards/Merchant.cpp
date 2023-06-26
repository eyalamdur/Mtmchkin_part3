#include "Merchant.h"

/* Handling the player's applyEncounter with the Merchant:
 * @param player - The player.
 * @return void */
void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int playerNumber;

    while (true){
        playerNumber = getValidInput();
        switch (Merchant::PlayerChoise(playerNumber)){
            case Merchant::PlayerChoise::LEAVE:
                printMerchantSummary(std::cout, player.getName(), 0, 0);
                return;

            case Merchant::PlayerChoise::HEALTH_POTION:
                buyHealthPotion(player);
                return;

            case Merchant::PlayerChoise::FORCE_BOOST:
                buyForceBoost(player);
                return;
        }
    }
    return;
}

/* Gets input from player until a valid one */
int Merchant::getValidInput() const{
    std::string playerInput;
    while(true){
    // Gets player input and check validation
        std::getline(std::cin, playerInput);
        if (playerInput.size() == 1 && std::isdigit(playerInput[0])){
            if ((playerInput[0] - '0' <= 2) && (playerInput[0] - '0' >=0)){
                return playerInput[0] - '0';
            }
        }
        printInvalidInput();
    }
}

/* Execute buying health potion actions */
void Merchant::buyHealthPotion(Player& player) const{
    if(player.pay(HEALTH_POTION_PRICE)){
        player.heal(ONE_POINT);
        printMerchantSummary(std::cout, player.getName(), 1, HEALTH_POTION_PRICE);
        return;
    }
    printMerchantInsufficientCoins(std::cout);
    printMerchantSummary(std::cout, player.getName(), 1, 0);
    return;
}
        
/* Execute buying force boost actions */
void Merchant::buyForceBoost(Player& player) const{
    if(player.pay(FORCE_BOOST_PRICE)){
        player.buff(ONE_POINT);
        printMerchantSummary(std::cout, player.getName(), 2, FORCE_BOOST_PRICE);
        return;
    }
    printMerchantInsufficientCoins(std::cout);
    printMerchantSummary(std::cout, player.getName(), 2, 0);
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