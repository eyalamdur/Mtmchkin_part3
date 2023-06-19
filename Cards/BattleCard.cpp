#include "BattleCard.h"

/* Sets the loot of the Battle card in case of win. 
 * @param int - loot of the Battle card. */
void BattleCard::setLoot(int loot){
    this->m_loot = loot;
    return;
}

/* Sets the force of the Battle card. 
 * @param int - force of the Battle card. */
void BattleCard::setForce(int force){
    this->m_force = force;
    return;
}

/* Sets the hp loss of the Battle card in case of lose. 
* @param int - hp loss of the Battle card. */
void BattleCard::setHPLossOnDefeat(int hpLoss){
    this->m_hpLossOnDefeat = hpLoss;
    return;
}

/* @return the loot of the Battle card. */
int BattleCard::getLoot() const{
    return this->m_loot;
}

/* @return the force of the Battle card. */
int BattleCard::getForce() const{
    return this->m_force;
}

/* @return the hp loss of the Battle card. */
int BattleCard::getHPLossOnDefeat() const{
    return this->m_hpLossOnDefeat;
}

