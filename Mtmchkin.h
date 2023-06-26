#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include "Exception.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Barfight.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"

using namespace std;

class Mtmchkin{

public:
    /* C'tor of Mtmchkin class
     * @param filename - a file which contains the cards of the deck.
     * @return  A new instance of Mtmchkin. */
    explicit Mtmchkin(const std::string &fileName);

    /* D'tor of Mtmchkin class. */
    ~Mtmchkin() = default;

    /* Copy of Mtmchkin class.
     * @param Mtmchkin& - reference to another Mtmchkin object.
     * @return a new instance of Mtmchkin with copied values as the given Mtmchkin. */
    Mtmchkin(const Mtmchkin&) = delete;

    /* Assigning of Mtmchkin class.
     * @param Mtmchkin& - reference to another Mtmchkin object.
     * @return a new instance of Mtmchkin with copied values as the given Mtmchkin. */
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

    /* Play the next Round of the game - according to the instruction in the exercise document.
     * @return void */
    void playRound();
    
    /* Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
     * @return void */
    void printLeaderBoard() const;
    
    /* Checks if the game ended:
     * @return True if the game ended, False otherwise */    
    bool isGameOver() const;
    
	/* Returns the number of rounds played.
     * @return int - number of rounds played */
    int getNumberOfRounds() const;

protected:
    const int CARD_TYPES_NUM = 8;

    /* Deck Creator
     * @param filename - a file which contains the cards of the deck.
     * @return void*/
    void createDeck(const string &fileName);

    /* Card factory
     * @param cardName - a card type.
     * @return  A new instance of unique_ptr<Card>. */
    unique_ptr<Card> createCard(const std::string &cardType);

    /* Card Map Creator
     * @return  A new instance of map conecets card name and its constructor */
    map<string, function<unique_ptr<Card>()>> createCardMap();

    /* Players vector Creator  
     * @param fileName - a file which contains the cards of the deck.
     * @return void*/
    void createPlayersVector();

    /* Team size validator  
    * @return the team size */
    int checkValidTeamSize();

    /* Players full input validator  
     * @param playerName - player's name.
     * @param playerType - player's type.
     * @return true if the input is valid and false if not */
    bool checkInput(string &playerName, string &playerType);

    /* Players name validator  
     * @param playerName - player's name.
     * @return true if the name is valid and false if not */
    bool checkValidName(string &playerName);

    /* Players type validator  
     * @param playerJob - player's job.
     * @return true if the job is valid and false if not */
    bool checkValidType(string &playerType);
    
    /* Player factory
     * @param playerName - the Player's Name.
     * @param playerType - the Player's type.
     * @return  A new instance of shared_ptr<Name>. */
    shared_ptr<Player> createPlayer(const std::string &playerName, const std::string &playerType);

    /* Player Map Creator
     * @return A new instance of map that connects Player type and its constructor */
    map<string, function<shared_ptr<Player>(const string)>> createPlayerMap();

    /* Checks all players status and reorganizes the players vector accourdingly */
    void updatePlayerStatus(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> currentPlayer);

    /* Improves given player position the its appropriate place in leaderboard */
    void improvePosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex);

    /* Deproves given player position the its appropriate place in leaderboard */
    void deprovePosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex);
    
    /* change given player position the its appropriate place by given currnet index and new index
     * @param copiedVector - the copied vector refernce.
     * @param player - the Player refernce.
     * @param currentIndex - the Player current index.
     * @param newIndex - the Player new index. */
    void changePlayerPosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex, int newIndex);

    /* Returns the size of the player vector*/
    int getPlayersVectorSize();

private:
    vector<unique_ptr<Card>> m_deck;
    vector<shared_ptr<Player>> m_players;
    int m_roundsPlayed;
};



#endif /* MTMCHKIN_H_ */
