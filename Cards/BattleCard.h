#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {
public:
    /* C'tor of BattleCard class
     * @param type - The type of the BattleCard.
     * @param stats - The numeral stats of the BattleCard.
     * @return A new instance of BattleCard.*/
    BattleCard() = default;

    /* Handling the player's applyEncounter with the BattleCard:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const;

    /* Prints the BattleCard info:*/
    virtual std::ostream& printInfo(std::ostream& os) const = 0;

    /* Here we are explicitly telling the compiler to use the default methods */
    BattleCard(const BattleCard&) = default;
    ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& other) = default;

    /* Sets the loot of the Battle card in case of win. 
     * @param int - loot of the Battle card. */
    void setLoot(int loot);

    /* Sets the force of the Battle card. 
     * @param int - force of the Battle card. */
    void setForce(int force);

    /* Sets the hp loss of the Battle card in case of lose. 
     * @param int - hp loss of the Battle card. */
    void setHPLossOnDefeat(int hpLoss);

    /* @return the loot of the Battle card. */
    int getLoot() const;

    /* @return the force of the Battle card. */
    int getForce() const;

    /* @return the hp loss of the Battle card. */
    int getHPLossOnDefeat() const;

    const int GREMLIN_FORCE = 5;
    const int WITCH_FORCE = 11;

    private:
        int m_force;  // The force of the monster
        int m_loot; // The profit you get when winning a battle or when getting a "Treasure" card
        int m_hpLossOnDefeat; // The amount of hp you lose when losing the battle
};


#endif //EX4_BATTLECARD_H
