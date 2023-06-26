#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
#include <limits>

class Merchant : public Card {
public:
    /* C'tor of Merchant class
     * @param type - The type of the Merchant.
     * @param stats - The numeral stats of the Merchant.
     * @return A new instance of Merchant.*/
    Merchant() = default;

    /* Handling the player's applyEncounter with the Merchant:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Merchant info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Merchant& merchant);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Merchant(const Merchant&) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;

    protected:
        enum class PlayerChoise {LEAVE, HEALTH_POTION, FORCE_BOOST}; // The type of the player
        const static int ONE_POINT = 1;
        const static int HEALTH_POTION_PRICE = 5;
        const static int FORCE_BOOST_PRICE = 10;
        const static int HEALTH_POINT = 1;

        /* Gets input from player until a valid one */
        int getValidInput() const;

        /* Execute buying health potion actions */
        void buyHealthPotion(Player& player) const;
        
        /* Execute buying force boost actions */
        void buyForceBoost(Player& player) const;
};


#endif //EX4_MERCHANT_H
