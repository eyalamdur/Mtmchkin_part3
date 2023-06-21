#include "Mtmchkin.h"

/* C'tor of Mtmchkin class
 * @param filename - a file which contains the cards of the deck.
 * @return  A new instance of Mtmchkin. */
Mtmchkin::Mtmchkin(const string &fileName){
    createDeck(fileName);
    createPlayersVector();
    return;
}

/* Deck Creator
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createDeck(const string &fileName){
    // Open File
    ifstream cards(fileName);
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
            catch(CardNotFound()){
                throw(DeckFileFormatError(currentLine));
            }
        }
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
    cardTypeMap["Barfight\r"] = []() {return unique_ptr<Card> (new Barfight);};
    cardTypeMap["Mana\r"] = []() {return unique_ptr<Card> (new Mana);};
    cardTypeMap["Well\r"] = []() {return unique_ptr<Card> (new Well);};
    cardTypeMap["Treasure\r"] = []() {return unique_ptr<Card> (new Treasure);};
    cardTypeMap["Merchant\r"] = []() {return unique_ptr<Card> (new Merchant);};
    cardTypeMap["Dragon\r"] = []() {return unique_ptr<Card> (new Dragon);};
    cardTypeMap["Witch\r"] = []() {return unique_ptr<Card> (new Witch);};
    cardTypeMap["Gremlin\r"] = []() {return unique_ptr<Card> (new Gremlin);};
    return cardTypeMap;
}

/* Players vector Creator  
 * @param filename - a file which contains the cards of the deck.
 * @return void*/
void Mtmchkin::createPlayersVector(){
    // Team size input untill valid one
    int teamSize = checkValidTeamSize();

    // Players input untill all valid
    string playerNameAndJob, name, job;
    while (teamSize != 0){
        printInsertPlayerMessage();
        getline(cin,playerNameAndJob);
        istringstream line(playerNameAndJob);
        line >> name;
        if(checkValidName(name)){
            line >> job;
            if(checkValidJob(job)){
                cout << "Valid Player" << endl;
                teamSize--;
                //createPlayer();
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
        printEnterTeamSizeMessage();
        cin >> teamSize;
        if (teamSize < 2 || teamSize > 6){
            printInvalidTeamSize();
        }
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

/* Player Map Creator
* @return A new instance of map that connects Player type and its constructor */
map<string, function<unique_ptr<Player>()>> Mtmchkin::createPlayerMap(){
    map<string, function<unique_ptr<Player>()>> playerTypeMap;
    //playerTypeMap["Ninja"] = []() {return unique_ptr<Player> (new Ninja);};
    //playerTypeMap["Warrior"] = []() {return unique_ptr<Player> (new Warrior);};
    //playerTypeMap["Healer"] = []() {return unique_ptr<Player> (new Healer);};
    return playerTypeMap;
}

/* Play the next Round of the game - according to the instruction in the exercise document.
 * @return void */
void Mtmchkin::playRound(){
    return;
}
    
/* Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
* @return void */
void Mtmchkin::printLeaderBoard() const{
    return;
}
    
/* Checks if the game ended:
* @return True if the game ended, False otherwise */
bool Mtmchkin::isGameOver() const{
    return true;
}
    
/* Returns the number of rounds played.
* @return int - number of rounds played */
int  Mtmchkin::getNumberOfRounds() const{
    return 1;
}