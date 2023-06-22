#include "BattleCard.h"

/* Handling the player's applyEncounter with the Gremlin:
 * @param player - The player.
 * @return void */
void BattleCard::applyEncounter(Player& player) const{
    // Find which monster we battle
    std::string monster = "Dragon";
    if (this->getForce() == 5) {
        monster = "Gremlin";
    }
    else if (this->getForce() == 11){
        monster = "Witch";
    }

    // Fight monster
    if (this->getForce() <= player.getAttackStrength()){
        player.levelUp();
        player.addCoins(this->getLoot());
        printWinBattle(player.getName(), monster);
        return;
    }
    player.damage(this->getHPLossOnDefeat());
    if(monster == "Witch"){
        player.buff(-1);
    }
    printLossBattle(player.getName(), monster);
    return;
}

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

