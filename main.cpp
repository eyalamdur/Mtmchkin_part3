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


int main(){
    Ninja player1("Itay");
    Warrior player2("Efrat");
    Healer player3("Jimmy");
    std::cout << player1 << std::endl << player2 << std::endl << player3 << std::endl;
    std::cout << "Yassss" << std::endl;
    return 0;
}