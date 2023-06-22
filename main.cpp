#include "utilities.h"
#include "Mtmchkin.h"

int main(){
    Ninja player1("Itay");
    Warrior player2("Efrat");
    Healer player3("Jimmy");
    Gremlin gremlin;
    Witch witch;
    Dragon dragon;
    Mana mana;
    Well well;
    Treasure treasure;
    Barfight barfight;
    Merchant merchant;
    Player &p1 = player1, &p2 = player2, &p3 = player3;
    std::cout << player1 << std::endl << player2 << std::endl << player3 << std::endl;
    std::cout << gremlin  << witch <<  dragon ;
    std::cout << treasure << merchant;
    mana.applyEncounter(p2);
    mana.applyEncounter(p3);
    std::cout << barfight;
    barfight.applyEncounter(p1);
    barfight.applyEncounter(p2);
    std::cout << well;
    well.applyEncounter(p1);
    well.applyEncounter(p3);
    gremlin.applyEncounter(p1);
    witch.applyEncounter(p2);
    dragon.applyEncounter(p3);
    Mtmchkin game("deck.txt");
    while(!game.isGameOver()){
        game.playRound();
    }
    game.printLeaderBoard();
    return 0;
}