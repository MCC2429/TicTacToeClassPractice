#include <iostream>
#include "gameBoard.h"

using namespace std;

int main()
{
    gameBoard game;
    game.printGrid();
    while (!game.run_wincon_checks()){
        game.getCoords();
    }
    return 0;
}
