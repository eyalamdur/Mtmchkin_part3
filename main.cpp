#include "utilities.h"
#include "Mtmchkin.h"

int main(){
    try{
        Mtmchkin game("deck.txt");
        while(!game.isGameOver()){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(...){};
    return 0;
}