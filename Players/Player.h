#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>

const int MINIMUM_VALUE = 0;
const int DEFAULT_LEVEL = 1;
const int DOUBLE = 2;
const int DEFAULT_FORCE = 5;
const int DEFAULT_COINS = 10;
const int DEFAULT_MAX_HP = 100;
const int MAX_LEVEL = 10;

class Player {
public:
    /* C'tor of Player class - 1 param.
     * @param name - The name of the player.
     * @return a new instance of Player. */
    Player() = default;

    /* D'tor of Player class. */
    virtual ~Player() = default;

    /* Copy of Player class.
     * @param Player& - reference to another Player object.
     * @return a new instance of Player with copied values as the given Player. */
    Player(const Player&) = default;

    /* Assigning of Player class.
     * @param Player& - reference to another Player object.
     * @return a new instance of Player with copied values as the given Player. */
    Player& operator=(const Player& other) = default;

    /* Operator << of Player class.
     * @param std::ostream& - reference to ostream object.
     * @return a new instance of ostream. */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual std::ostream& printInfo(std::ostream& os) const = 0;

    /* Level up player level by one (up to a maximum of level 10).
     * If player level is 10 does nothing. */
    void levelUp();

    /* Raise the player force by given ammount
     * If invalid variable is given nothing changes. */
    void buff(int forcePoints);

    /* Increase the player HP by given ammount (up to the maximum allowed HP - maxHP)
     * @param healthPoints - The intented health points to give to the player.
     * If player has full HP or gets invalid param - nothing changed. */
    virtual void heal(int healthPoints);

    /* Decrease the player HP by given ammount (up to the minimum allowed HP - 0)
     * @param healthPoints - The intented health points to decrese from the player.
     * If given healthPoints is bigger than player current HP reduce current HP to 0. */
    void damage(int healthPoints);

    /* Checks if the player HP has reached to 0.
     * @return true if 0 and false if otherwise.  */
    bool isKnockedOut();

    /* Increase the player coins by given ammount.
     * @param coins - The intented coins points to add to the player. */
    virtual void addCoins(int coins);

    /* Checks if player has the given ammount of coins in his coin bag.
     * if so decrease the player coins by given ammount and returns true.
     * else returns false
     * @param coins - The intented coins points to decrease from the player.
     * @return true if payment succeeded and false if otherwise.  */
    bool pay(int coins);

    /* Calculate the player attack strength (force + level).
     * @return the calculated attack strngth. */
    virtual int getAttackStrength() const;

    /* Sets the name of the player. 
     * @param std::string - name of the player. */
    void setName(std::string name);

    /* Sets the level of the player. 
     * @param int - level of the player. */
    void setLevel(int level);

    /* Sets the force of the player. 
     * @param int - force of the player. */
    void setForce(int force);

    /* Sets the HP of the player. 
     * @param int - HP of the player. */
    void setHP(int hp);

    /* Sets the max HP of the player. 
     * @param int - max HP of the player. */
    void setMaxHP(int maxHP);

    /* Sets the coins of the player. 
     * @param int - coins of the player. */
    void setCoins(int coins);

    /* @return the name of the player. */
    std::string getName() const;

    /* @return the level of the player. */
    int getLevel() const;

    /* @return the force of the player. */
    int getForce() const;

    /* @return the hp of the player. */
    int getHP() const;

    /* @return the max hp of the player. */
    int getMaxHP() const;

    /* @return the coins of the player. */
    int getCoins() const;

private:
    std::string m_name;
    int m_maxHP;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
};

/*------------------------------Class Functions------------------------------*/

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
    // Exception check
    if (forcePoints < MINIMUM_VALUE){
        throw ("Focuk");
    }

    this->m_force += forcePoints;
    return;
}

/* Increase the player HP by given ammount (up to the maximum allowed HP - maxHP)
 * @param healthPoints - The intented health points to give to the player.
 * If player has full HP or gets invalid param - nothing changed. */
void  Player::heal(int healthPoints){
    // Exception check
    if (healthPoints < MINIMUM_VALUE){
        throw ("Focuk");
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
        throw ("Focuk");
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
        throw ("Focuk");
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

#endif //EX4_PLAYER_H
