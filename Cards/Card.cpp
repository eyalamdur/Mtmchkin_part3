#include "Card.h"
#include <iostream>

const int MINIMUM_VALUE = 0;

// Functions decleration
bool applyBattleEncounter(Player& player, int cardForce, int cardLoot, int cardHpLossOnDefeat);
void applyBuffEncounter(Player& player, int cardCost, int cardValue);
void applyHealEncounter(Player& player, int cardCost, int cardValue);
void applyTreasureEncounter(Player& player, int cardLoot);

/* C'tor of Card class
 * @param type - The type of the card.
 * @param stats - The numeral stats of the card.
 * @return a new instance of Card.*/
Card::Card(CardType type, const CardStats& stats){
    // Paremter validation
    if (type < CardType::Battle || type > CardType::Treasure){
        return;
    }
    m_effect = type;
    m_stats = stats;
    return;
}

/* Prints the card info: */
void Card::printInfo() const{
    switch (this->m_effect)
    {
    case CardType::Battle:
        printBattleCardInfo(this->m_stats);
        break;
    case CardType::Buff:
        printBuffCardInfo(this->m_stats);
        break;
    case CardType::Heal:
        printHealCardInfo(this->m_stats);
        break;
    case CardType::Treasure:
        printTreasureCardInfo(this->m_stats);
        break;
    default:
        break;
    }
    return;
}

/* Handling the player's applyEncounter with the card:
 * @param player - The player.
 * @return void. */
void Card::applyEncounter(Player& player) const{
    switch (this->m_effect)
    {
    case CardType::Battle:
        printBattleResult(applyBattleEncounter(player, this->m_stats.force, this->m_stats.loot, this->m_stats.hpLossOnDefeat));
        break;
    case CardType::Buff:
        applyBuffEncounter(player, this->m_stats.cost, this->m_stats.buff);
        break;
    case CardType::Heal:
        applyHealEncounter(player, this->m_stats.cost, this->m_stats.heal);
        break;
    case CardType::Treasure:
        applyTreasureEncounter(player, this->m_stats.loot);
        break;
    default:
        break;
    }
    return;
}

/* Handling the player's applyEncounter with battle card
 * @param player - The player.
 * @param cardForce - The card force.
 * @param cardLoot - The card loot on win.
 * @param cardHpLossOnDefeat - The card hp to decrease from the player if lose.
 * @return void. */
bool applyBattleEncounter(Player& player, int cardForce, int cardLoot, int cardHpLossOnDefeat){
    if (cardForce <= player.getAttackStrength()){
        player.levelUp();
        player.addCoins(cardLoot);
        return true;
    }
    player.damage(cardHpLossOnDefeat);
    return false;
}

/* Handling the player's applyEncounter with Buff card
 * @param player - The player.
 * @param cardCost - The card cost.
 * @param cardValue - The card force points to add to player.
 * @return void. */
void applyBuffEncounter(Player& player, int cardCost, int cardValue){
        if (player.pay(cardCost)){
            player.buff(cardValue);
        }
    return;
}

/* Handling the player's applyEncounter with Heal card
 * @param player - The player.
 * @param cardCost - The card cost.
 * @param cardValue - The card heal points to add to player.
 * @return void. */
void applyHealEncounter(Player& player, int cardCost, int cardValue){
        if (player.pay(cardCost)){
            player.heal(cardValue);
        }
    return;
}

/* Handling the player's applyEncounter with Treasure card
 * @param player - The player.
 * @param cardCost - The coins number to add the player.
 * @return void. */
void applyTreasureEncounter(Player& player, int cardLoot){
    player.addCoins(cardLoot);
    return;
}


