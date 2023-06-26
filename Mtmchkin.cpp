#include "Mtmchkin.h"

/* C'tor of Mtmchkin class
 * @param filename - a file which contains the cards of the deck.
 * @return  A new instance of Mtmchkin. */
Mtmchkin::Mtmchkin(const string &fileName)
{
    // Build Mtmchkin object
    printStartGameMessage();
    createDeck(fileName);
    createPlayersVector();
    this->m_roundsPlayed = 0;
}

/* Deck Creator
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createDeck(const string &fileName)
{
    // Open File and check validation
    ifstream cards(fileName);
    if (cards.fail())
    {
        throw(DeckFileNotFound());
    }
    string cardName;
    int currentLine = 0;

    // Read next line from text file untill end.
    while (std::getline(cards, cardName))
    {
        // If not empty line
        if (cardName.size() > 0)
        {
            try{
                currentLine++;
                unique_ptr<Card> newCard = move(createCard(cardName));
                this->m_deck.push_back(move(newCard));
            }
            catch (CardNotFound &e)
            {
                throw(DeckFileFormatError(currentLine));
            }
        }
    }
    // Invalid size of deck
    if (currentLine < 5)
    {
        throw(DeckFileInvalidSize());
    }
}

/* Card factory
 * @param cardName - a card type.
 * @return  A new instance of unique_ptr<Card>. */
unique_ptr<Card> Mtmchkin::createCard(const std::string &cardType)
{
    // Create map that connects card name and its constructor
    map<string, function<unique_ptr<Card>()>> cardTypeMap = createCardMap();

    // Call given card type constructor
    map<string, function<unique_ptr<Card>()>>::iterator currentype = cardTypeMap.find(cardType);
    if (currentype != cardTypeMap.end())
    {
        unique_ptr<Card> newCard = move((currentype->second)());
        return newCard;
    }

    throw(CardNotFound());
}

/* Card Map Creator
 * @return A new instance of map that connects card name and its constructor */
map<string, function<unique_ptr<Card>()>> Mtmchkin::createCardMap()
{
    map<string, function<unique_ptr<Card>()>> cardTypeMap;
    cardTypeMap["Barfight"] = []()
    { return move(unique_ptr<Card>(new Barfight)); };
    cardTypeMap["Mana"] = []()
    { return move(unique_ptr<Card>(new Mana)); };
    cardTypeMap["Well"] = []()
    { return move(unique_ptr<Card>(new Well)); };
    cardTypeMap["Treasure"] = []()
    { return move(unique_ptr<Card>(new Treasure)); };
    cardTypeMap["Merchant"] = []()
    { return move(unique_ptr<Card>(new Merchant)); };
    cardTypeMap["Dragon"] = []()
    { return move(unique_ptr<Card>(new Dragon)); };
    cardTypeMap["Witch"] = []()
    { return move(unique_ptr<Card>(new Witch)); };
    cardTypeMap["Gremlin"] = []()
    { return move(unique_ptr<Card>(new Gremlin)); };
    return cardTypeMap;
}

/* Players vector Creator
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createPlayersVector()
{
    // Team size input untill valid one
    int teamSize = checkValidTeamSize();

    // Players input untill all valid
    string playerNameAndType, name, type;
    while (teamSize != 0)
    {
        printInsertPlayerMessage();
        do
        {
            getline(cin, playerNameAndType);
            istringstream line(playerNameAndType);
            line >> name;
            line >> type;
        } while (!checkInput(name, type));

        // If valid input create player
        this->m_players.push_back(createPlayer(name, type));
        teamSize--;
    }
}

/* Team size validator
 * @return the team size*/
int Mtmchkin::checkValidTeamSize()
{
    string teamSize;
    while (true){
        // Enter team size message and get input
        printEnterTeamSizeMessage();
        std::getline(std::cin, teamSize);
        if (teamSize.size() == 1 && std::isdigit(teamSize[0])){
            if ((teamSize[0] - '0' <= 6) && (teamSize[0] - '0' >= 2)){
                return teamSize[0] - '0';
            }
        }
        printInvalidTeamSize();
    }
}

/* Players full input validator
 * @param playerName - player's name.
 * @param playerType - player's job.
 * @return true if the input is valid and false if not */
bool Mtmchkin::checkInput(string &playerName, string &playerType)
{
    // Invalid name
    if (!checkValidName(playerName))
    {
        printInvalidName();
        return false;
    }

    // Invalid class
    if (!checkValidType(playerType))
    {
        printInvalidClass();
        return false;
    }

    // Valid input
    return true;
}

/* Players name validator
 * @param playerName - player's name.
 * @return true if the name is valid and false if not*/
bool Mtmchkin::checkValidName(string &playerName)
{
    int nameLength = 0;

    // Content validation
    for (char c : playerName)
    {
        nameLength++;
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        {
            return false;
        }
    }

    // Length validation
    if (nameLength > 15)
    {
        return false;
    }

    return true;
}

/* Players type validator
 * @param playerJob - player's job.
 * @return true if the job is valid and false if not*/
bool Mtmchkin::checkValidType(string &playerType)
{
    if (playerType == "Ninja" || playerType == "Warrior" || playerType == "Healer")
    {
        return true;
    }
    return false;
}

/* Player factory
 * @param playerName - the Player's Name.
 * @param playerType - the Player's type.
 * @return  A new instance of shared_ptr<Name>. */
shared_ptr<Player> Mtmchkin::createPlayer(const std::string &playerName, const std::string &playerType)
{
    // Create map that connects player name and its constructor
    map<string, function<shared_ptr<Player>(const string)>> playerTypeMap = createPlayerMap();

    // Call given player type constructor
    map<string, function<shared_ptr<Player>(const string)>>::iterator currentype = playerTypeMap.find(playerType);
    if (currentype != playerTypeMap.end())
    {
        shared_ptr<Player> newPlayer = (currentype->second)(playerName);
        return newPlayer;
    }

    throw(PlayerCreationFailure());
}

/* Player Map Creator
 * @return A new instance of map that connects Player type and its constructor */
map<string, function<shared_ptr<Player>(const string)>> Mtmchkin::createPlayerMap()
{
    map<string, function<shared_ptr<Player>(const string)>> playerTypeMap;
    playerTypeMap["Ninja"] = [](const string &playerName)
    { return make_shared<Ninja>(playerName); };
    playerTypeMap["Warrior"] = [](const string &playerName)
    { return make_shared<Warrior>(playerName); };
    playerTypeMap["Healer"] = [](const string &playerName)
    { return make_shared<Healer>(playerName); };
    return playerTypeMap;
}

/* Play the next Round of the game - according to the instruction in the exercise document.
 * @return void */
void Mtmchkin::playRound()
{
    printRoundStartMessage(getNumberOfRounds() + 1);
    vector<shared_ptr<Player>> copiedVector = this->m_players;
    // Draw card for each player which still playing
    for (shared_ptr<Player> currentPlayer : this->m_players)
    {
        // If player is playing
        if (!(currentPlayer.get()->isKnockedOut() || currentPlayer.get()->getLevel() == 10))
        {
            printTurnStartMessage(currentPlayer.get()->getName());
            this->m_deck.front().get()->applyEncounter(*currentPlayer.get());

            // Move card to end of deck
            this->m_deck.push_back(move(this->m_deck.front()));
            this->m_deck.erase(this->m_deck.begin());
            updatePlayerStatus(copiedVector, currentPlayer);
        }
    }
    this->m_players = copiedVector;
    // If game over
    if (this->isGameOver())
    {
        printGameEndMessage();
        return;
    }
    this->m_roundsPlayed++;
    return;
}

/* Checks all players status and reorganizes the players vector accourdingly */
void Mtmchkin::updatePlayerStatus(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> currentPlayer)
{
    // Find player index
    int currentPlayerIndex = -1;
    while (currentPlayer != copiedVector[++currentPlayerIndex]);

    // Check if currentPlayer reached level 10
    if (currentPlayer->getLevel() == 10)
    {
        improvePosition(copiedVector, currentPlayer, currentPlayerIndex);
    }

    // Check if currentPlayer died
    if (currentPlayer->isKnockedOut())
    {
        deprovePosition(copiedVector, currentPlayer, currentPlayerIndex);
    }
    return;
}

/* Improves given player position the its appropriate place in leaderboard
 * @param player - the Player refernce.*/
void Mtmchkin::improvePosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex)
{
    int bestIndex = 0;
    while (bestIndex < currentIndex && copiedVector[bestIndex]->getLevel() == 10)
    {
        ++bestIndex;
        // Prevent vector boundry cross
        if (bestIndex >= getPlayersVectorSize())
        {
            bestIndex = getPlayersVectorSize() - 1;
            break;
        }
    }

    if (currentIndex != bestIndex)
    {
        changePlayerPosition(copiedVector, player, currentIndex, bestIndex);
    }
}

/* Deproves given player position the its appropriate place in leaderboard
 * @param player - the Player refernce.*/
void Mtmchkin::deprovePosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex)
{
    int firstDeadPlayerIndex = getPlayersVectorSize() - 1;
    while (copiedVector[firstDeadPlayerIndex]->isKnockedOut() && firstDeadPlayerIndex != currentIndex)
    {
        --firstDeadPlayerIndex;
        // Prevent vector boundry cross
        if (firstDeadPlayerIndex < 0)
        {
            firstDeadPlayerIndex = 0;
            break;
        }
    }

    if (currentIndex != firstDeadPlayerIndex)
    {
        changePlayerPosition(copiedVector, player, currentIndex, firstDeadPlayerIndex);
    }
}

/* change given player position the its appropriate place by given currnet index and new index
 * @param copiedVector - the copied vector refernce.
 * @param player - the Player refernce.
 * @param currentIndex - the Player current index.
 * @param newIndex - the Player new index. */
void Mtmchkin::changePlayerPosition(vector<shared_ptr<Player>> &copiedVector, shared_ptr<Player> &player, int currentIndex, int newIndex)
{
    if (currentIndex < getPlayersVectorSize() && newIndex < getPlayersVectorSize() &&
        currentIndex >= 0 && newIndex >= 0)
    {
        copiedVector.erase(copiedVector.begin() + currentIndex);
        copiedVector.insert(copiedVector.begin() + newIndex, player);
    }
    return;
}

/* Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
 * @return void */
void Mtmchkin::printLeaderBoard() const
{
    int rank = 1;
    printLeaderBoardStartMessage();
    for (shared_ptr<Player> currentPlayer : this->m_players)
    {
        cout << rank++ << "          " << *currentPlayer.get() << endl;
    }
    return;
}

/* Checks if the game ended:
 * @return True if the game ended, False otherwise */
bool Mtmchkin::isGameOver() const
{
    for (shared_ptr<Player> currentPlayer : this->m_players)
    {
        // If player is playing
        if (!(currentPlayer.get()->isKnockedOut() || currentPlayer.get()->getLevel() == 10))
        {
            return false;
        }
    }

    return true;
}

/* Returns the number of rounds played.
 * @return int - number of rounds played */
int Mtmchkin::getNumberOfRounds() const
{
    return this->m_roundsPlayed;
}

/* Returns the size of the player vector*/
int Mtmchkin::getPlayersVectorSize()
{
    return static_cast<int>(this->m_players.size());
}