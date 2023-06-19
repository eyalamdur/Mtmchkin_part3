#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <iostream>
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

#endif //EX4_PLAYER_H
