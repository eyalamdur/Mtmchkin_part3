#include "Mtmchkin.h"

/* C'tor of Mtmchkin class
 * @param filename - a file which contains the cards of the deck.
 * @return  A new instance of Mtmchkin. */
Mtmchkin::Mtmchkin(const string &fileName){
    // Build Mtmchkin object
    try{
        printStartGameMessage();
        createDeck(fileName);
        createPlayersVector();
        this->m_roundsPlayed = 0;
    }
    
    // If failed throw appropriate error message
    catch (DeckFileFormatError &e){
        throw(e);
    }
    catch (DeckFileNotFound &e){
        throw(e);
    }
    catch (DeckFileInvalidSize &e){
        throw(e);
    }
    catch (...){
        return;
    }
}

/* Deck Creator
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createDeck(const string &fileName){
    // Open File and check validation
    ifstream cards(fileName);
    if (cards.fail()){
        throw(DeckFileNotFound());
    }
    string cardName;
    int currentLine = 0;

    // Read next line from text file untill end.
    while (std::getline(cards, cardName))
    {
        // If not empty line
        if(cardName.size() > 0){
            try{
                unique_ptr<Card> newCard = move(createCard(cardName));
                this->m_deck.push_back(move(newCard));
                currentLine++;
            }
            catch(CardNotFound &e){
                throw(DeckFileFormatError(currentLine));
            }
        }
    }
    // Invalid size of deck
    if (currentLine < 5){
        throw(DeckFileInvalidSize());
    }
}

/* Card factory
* @param cardName - a card type.
* @return  A new instance of unique_ptr<Card>. */
unique_ptr<Card> Mtmchkin::createCard(const std::string &cardType){
    // Create map that connects card name and its constructor
    map<string, function<unique_ptr<Card>()>> cardTypeMap = createCardMap();

    // Call given card type constructor
    map<string, function<unique_ptr<Card>()>>::iterator currentype = cardTypeMap.find(cardType);
    if (currentype != cardTypeMap.end()){
        unique_ptr<Card> newCard = move((currentype->second)());
        return newCard;
    }

    throw(CardNotFound());
}

/* Card Map Creator
* @return A new instance of map that connects card name and its constructor */
map<string, function<unique_ptr<Card>()>> Mtmchkin::createCardMap(){
    map<string, function<unique_ptr<Card>()>> cardTypeMap;
    cardTypeMap["Barfight"] = []() {return move(unique_ptr<Card> (new Barfight));};
    cardTypeMap["Mana"] = []() {return move(unique_ptr<Card> (new Mana));};
    cardTypeMap["Well"] = []() {return move(unique_ptr<Card> (new Well));};
    cardTypeMap["Treasure"] = []() {return move(unique_ptr<Card> (new Treasure));};
    cardTypeMap["Merchant"] = []() {return move(unique_ptr<Card> (new Merchant));};
    cardTypeMap["Dragon"] = []() {return move(unique_ptr<Card> (new Dragon));};
    cardTypeMap["Witch"] = []() {return move(unique_ptr<Card> (new Witch));};
    cardTypeMap["Gremlin"] = []() {return move(unique_ptr<Card> (new Gremlin));};
    return cardTypeMap;
}

/* Players vector Creator  
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createPlayersVector(){
    // Team size input untill valid one
    int teamSize = checkValidTeamSize();

    // Players input untill all valid
    string playerNameAndType, name, type;
    while (teamSize != 0){
        printInsertPlayerMessage();
        getline(cin,playerNameAndType);
        istringstream line(playerNameAndType);
        line >> name;
        if(checkValidName(name)){
            line >> type;
            if(checkValidJob(type)){
                this->m_players.push_back(createPlayer(name, type));
                teamSize--;
                continue;
            }
            printInvalidClass();
            continue;
        }
        printInvalidName();
    }
}

/* Team size validator  
 * @return the team size*/
int Mtmchkin::checkValidTeamSize(){
    int teamSize = 0;
    while (teamSize < 2 || teamSize > 6){
        // Enter team size message and get input
        printEnterTeamSizeMessage();
        cin >> teamSize;

        // If team size not valid print invalid team size message and get input again
        if (teamSize < 2 || teamSize > 6){
            printInvalidTeamSize();
        }
        
        // Input channel clear;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return teamSize;
}

/* Players name validator  
 * @param playerName - player's name.
 * @return true if the name is valid and false if not*/
bool Mtmchkin::checkValidName(string &playerName){
    int nameLength = 0;

    // Content validation
    for (char c : playerName){
        nameLength++;
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')){
            return false;
        }
    }

    // Length validation
    if (nameLength > 15){
        return false;
    }

    return true;
}

/* Players job validator  
 * @param playerJob - player's job.
 * @return true if the job is valid and false if not*/
bool Mtmchkin::checkValidJob(string &playerJob){
    if (playerJob == "Ninja" || playerJob == "Warrior" || playerJob == "Healer"){
        return true;
    }
    return false;
}

/* Player factory
 * @param playerName - the Player's Name.
 * @param playerType - the Player's type.
 * @return  A new instance of shared_ptr<Name>. */
shared_ptr<Player> Mtmchkin::createPlayer(const std::string &playerName, const std::string &playerType){
    // Create map that connects player name and its constructor
    map<string, function<shared_ptr<Player>(const string)>> playerTypeMap = createPlayerMap();

    // Call given player type constructor
    map<string, function<shared_ptr<Player>(const string)>>::iterator currentype = playerTypeMap.find(playerType);
    if (currentype != playerTypeMap.end()){
        shared_ptr<Player> newPlayer = (currentype->second)(playerName);
        return newPlayer;
    }

    throw(PlayerCreationFailure());
}

/* Player Map Creator
* @return A new instance of map that connects Player type and its constructor */
map<string, function<shared_ptr<Player>(const string)>> Mtmchkin::createPlayerMap(){
    map<string, function<shared_ptr<Player>(const string)>> playerTypeMap;
    playerTypeMap["Ninja"] = [](const string &playerName) {return make_shared<Ninja>(playerName);};
    playerTypeMap["Warrior"] = [](const string &playerName) {return make_shared<Warrior>(playerName);};
    playerTypeMap["Healer"] = [](const string &playerName) {return make_shared<Healer>(playerName);};
    return playerTypeMap;
}

/* Play the next Round of the game - according to the instruction in the exercise document.
 * @return void */
void Mtmchkin::playRound(){
    static int currentCard = 0;
    printRoundStartMessage(getNumberOfRounds() + 1);
    // Draw card for each player which still playing
    for (shared_ptr<Player> currentPlayer : this->m_players){
        // If player is playing
        if (!(currentPlayer.get()->isKnockedOut() || currentPlayer.get()->getLevel() == 10)){
            printTurnStartMessage(currentPlayer.get()->getName());
            this->m_deck.at(currentCard++).get()->applyEncounter(*currentPlayer.get());
            // Check if player died
            if (currentPlayer.get()->isKnockedOut()){
                this->m_rankingLossers.insert(this->m_rankingLossers.begin() ,currentPlayer);
            }
            // Check if player reach level 10
            if (currentPlayer.get()->getLevel() == 10){
                this->m_rankingWinners.push_back(currentPlayer);
            }
            // If got to last card restart deck
            if (currentCard == static_cast<int>(this->m_deck.size())){
                currentCard = 0;
            }
        }
    }
    // If game over
    if (this->isGameOver()){
        printGameEndMessage();
        return;
    }
    this->m_roundsPlayed++;
    return;
}
    
/* Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
* @return void */
void Mtmchkin::printLeaderBoard() const{
    int rank = 1;
    printLeaderBoardStartMessage();
    if (this->isGameOver()){
        for (shared_ptr<Player> currentPlayer : this->m_rankingWinners){
            cout << rank++ << "          " << *currentPlayer.get() << endl;
        }
        for (shared_ptr<Player> currentPlayer : this->m_rankingLossers){
            cout << rank++ << "          " << *currentPlayer.get() << endl;
        }
    }
    else{
        for (shared_ptr<Player> currentPlayer : this->m_players){
            cout << rank++ << "          " << *currentPlayer.get() << endl;
        }
    }
    return;
}
    
/* Checks if the game ended:
* @return True if the game ended, False otherwise */
bool Mtmchkin::isGameOver() const{
    for (shared_ptr<Player> currentPlayer : this->m_players){
        // If player is playing
        if (!(currentPlayer.get()->isKnockedOut() || currentPlayer.get()->getLevel() == 10)){
            return false;
        }
    }

    return true;
}
    
/* Returns the number of rounds played.
* @return int - number of rounds played */
int  Mtmchkin::getNumberOfRounds() const{
    return this->m_roundsPlayed;
}