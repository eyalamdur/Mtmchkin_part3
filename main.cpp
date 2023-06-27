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
    catch(exception &e){
        std::cout << e.what() << std::endl;
    };
    return 0;
}