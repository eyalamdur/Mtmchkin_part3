#include "Player.h"
#include "../utilities.h"

/* Sets the name of the player. 
 * @param std::string - name of the player. */
void Player::setName(std::string name){
    this->m_name = name;
    return;
}

/* Sets the level of the player. 
 * @param int - level of the player. */
void Player::setLevel(int level){
    this->m_level = level;
    return;
}

/* Sets the force of the player. 
 * @param int - force of the player. */
void Player::setForce(int force){
    this->m_force = force;
    return;
}

/* Sets the HP of the player. 
 * @param int - HP of the player. */
void Player::setHP(int hp){
    this->m_hp = hp;
    return;
}

/* Sets the max HP of the player. 
 * @param int - max HP of the player. */
void Player::setMaxHP(int maxHP){
    this->m_maxHP = maxHP;
    return;
}

/* Sets the coins of the player. 
 * @param int - coins of the player. */
void Player::setCoins(int coins){
    this->m_coins = coins;
    return;
}

/* @return the name of the player. */
std::string Player::getName() const{
    return this->m_name;
}

/* @return the level of the player. */
int Player::getLevel() const{
    return this->m_level;
}

/* @return the force of the player. */
int Player::getForce() const{
    return this->m_force;
}

/* @return the hp of the player. */
int Player::getHP() const{
    return this->m_hp;
}

/* @return the max hp of the player. */
int Player::getMaxHP() const{
    return this->m_maxHP;
}

/* @return the coins of the player. */
int Player::getCoins() const{
    return this->m_coins;
}

/* Operator << of Player class.
 * @param std::ostream& - reference to ostream object.
 * @return a new instance of ostream. */
std::ostream& operator<<(std::ostream& os, const Player& player){
    return player.printInfo(os);
}

/* Level up player level by one (up to a maximum of level 10).
 * If player level is 10 does nothing. */
void Player::levelUp(){
    if (this->m_level < MAX_LEVEL){
        this->m_level +=1;
    }
    return;
}

/* Raise the player force by given ammount
 * If invalid variable is given nothing changes. */
void  Player::buff(int forcePoints){
    if (this->m_force + forcePoints >= 0){
        this->m_force += forcePoints;
    }
    return;
}

/* Increase the player HP by given ammount (up to the maximum allowed HP - maxHP)
 * @param healthPoints - The intented health points to give to the player.
 * If player has full HP or gets invalid param - nothing changed. */
void  Player::heal(int healthPoints){
    // Exception check
    if (healthPoints < MINIMUM_VALUE){
        return;
    }

    if (healthPoints + this->m_hp < this->m_maxHP){
        this->m_hp += healthPoints;
    }
    else{
        this->m_hp = this->m_maxHP;
    }
    return;
}

/* Decrease the player HP by given ammount (up to the minimum allowed HP - 0)
 * @param healthPoints - The intented health points to decrese from the player.
 * If given healthPoints is bigger than player current HP reduce current HP to 0. */
void  Player::damage(int healthPoints){
    // Exception check
    if (healthPoints < MINIMUM_VALUE){
        return;
    }

    if (this->m_hp - healthPoints >= MINIMUM_VALUE){
        this->m_hp -= healthPoints;
    }
    else{
        this->m_hp = MINIMUM_VALUE;
    }
    return;
}

/* Checks if the player HP has reached to 0.
 * @return true if 0 and false if otherwise.  */
bool  Player::isKnockedOut(){
    return this->m_hp == MINIMUM_VALUE;
}

/* Increase the player coins by given ammount.
 * @param coins - The intented coins points to add to the player. */
void  Player::addCoins(int coins){
    // Exception check
    if (coins < MINIMUM_VALUE){
        return;
    }

    this->m_coins += coins;
    return;
}

/* Checks if player has the given ammount of coins in his coin bag.
 * if so decrease the player coins by given ammount and returns true.
 * else returns false
 * @param coins - The intented coins points to decrease from the player.
 * @return true if payment succeeded and false if otherwise.  */
bool  Player::pay(int coins){
    // If negative number surely can pay
    if (coins <= MINIMUM_VALUE){
        return true;
    }

    if (this->m_coins >= coins){
        this->m_coins -= coins;
        return true;
    }
    return false;
}

/* Calculate the player attack strength (force + level).
 * @return the calculated attack strngth. */
int  Player::getAttackStrength() const{
    return this->m_force + this->m_level;
}