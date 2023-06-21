#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    /* C'tor of Treasure class
     * @param type - The type of the Treasure.
     * @param stats - The numeral stats of the Treasure.
     * @return A new instance of Treasure.*/
    Treasure(int loot = DEFAULT_LOOT);

    /* Handling the player's applyEncounter with the Treasure:
     * @param player - The player.
     * @return void */
    void applyEncounter(Player& player) const override;

    /* Prints the Treasure info:
     * @return void */
    friend std::ostream& operator<<(std::ostream& os, const Treasure& treasure);
    std::ostream& printInfo(std::ostream& os) const override;

    /* Here we are explicitly telling the compiler to use the default methods */
    Treasure(const Treasure&) = default;
    ~Treasure() = default;
    Treasure& operator=(const Treasure& other) = default;

    const static int DEFAULT_LOOT = 10;

    private:
        int m_loot;
};


#endif //EX4_TREASURE_H
