#include <iostream>
#include "gameBoard.h"

using namespace std;

int main()
{
    gameBoard game;
    game.print_grid();
    while (!game.run_wincon_checks()){
        game.get_coords();
    }
    return 0;
}
