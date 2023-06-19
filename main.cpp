#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "utilities.h"
#include "Exception.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"


int main(){
    Ninja player1("Itay");
    Warrior player2("Efrat");
    Healer player3("Jimmy");
    Gremlin gremlin;
    Witch witch;
    Dragon dragon;
    std::cout << player1 << std::endl << player2 << std::endl << player3 << std::endl;
    std::cout << gremlin << std::endl << witch << std::endl << dragon << std::endl;
    return 0;
}