#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>

using namespace std;

class gameBoard
{
    public:
        gameBoard();
        virtual ~gameBoard();
        void printGrid() const;
        void getCoords();
        bool run_wincon_checks();


    protected:

    private:
        char gameGrid[3][3];
        int  x, y;
        bool turn, wincon = 0;
        void initGame();
        char getPlayerTurn();
        void changeTurn();
        void fillSquare(char player);
        bool check_in_grid();
        bool check_grid_empty();
        bool check_for_D_diag_win();
        bool check_for_U_diag_win();
        bool check_for_vert_win();
        bool check_for_horiz_win();

};

#endif // GAMEBOARD_H
