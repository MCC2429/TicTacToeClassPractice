#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>

using namespace std;

class gameBoard
{
    public:
        gameBoard();
        virtual ~gameBoard();
        void print_grid() const;
        void get_coords();
        bool run_wincon_checks();

    protected:

    private:
        char gameGrid[3][3], player;
        bool wincon = false;
        void init_game();
        char get_player_turn();
        void change_turn();
        void fill_square(int& x, int& y, char& player);
        bool check_in_grid(int& x, int& y);
        bool check_grid_empty(int& x, int& y);
        bool check_for_full_grid();
        bool check_for_D_diag_win();
        bool check_for_U_diag_win();
        bool check_for_vert_win();
        bool check_for_horiz_win();

};

#endif // GAMEBOARD_H
