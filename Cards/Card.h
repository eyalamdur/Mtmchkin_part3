#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"
#include "../utilities.h"

/*  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  MERCHANT - Allow option to buy Health potion or force buff.
 *  WELL -  Decrease player's health points by 10 unless player is Ninja.
 *  BARFIGHT -  Decrease player's health points by 8 unless player is Warrior.
 *  MANA - If player is Healer increase your player's HP by 10 points (no more than maxHP points).
 *  TREASURE - Get 10 coins. */

enum class CardType {Battle, Merchant, Well, Barfight, Mana, Treasure}; // The type of the Card

class Card {
public:
    /* C'tor of Card class
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return A new instance of Card.*/
    Card() = default;

    /* Handling the player's applyEncounter with the card:
     * @param player - The player.
     * @return void */
    virtual void applyEncounter(Player& player) const = 0;

    /* Prints the card info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual std::ostream& printInfo(std::ostream& os) const = 0;

    /* Here we are explicitly telling the compiler to use the default methods */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;

};


#endif //EX4_CARD_H
