#include "gameBoard.h"

gameBoard::gameBoard()
{
    x =  0;
    y = 0;
    turn = 1;
    wincon = 0;
    initGame();

}

gameBoard::~gameBoard()
{
    //dtor
}

void gameBoard::initGame()
{
    for (unsigned int x = 0; x < 3; x++) {
        for (unsigned int  y = 0; y < 3; y++) {
            gameGrid[x][y] = ' ';
        }
    }
}

void gameBoard::printGrid() const
{
    cout << "3  " << gameGrid[0][2] << "||" << gameGrid[1][2] << "||" << gameGrid[2][2] << endl;
    cout << "   -||-||-" << endl;
    cout << "2  " << gameGrid[0][1] << "||"  << gameGrid[1][1] << "||" << gameGrid[2][1] << endl;
    cout << "   -||-||-" << endl;
    cout << "1  " << gameGrid[0][0] << "||"  << gameGrid[1][0] << "||" << gameGrid[2][0] << endl;
    cout << "   1  2  3"  << endl;
}

char gameBoard::getPlayerTurn()
{
    if (turn) {
        return 'X';
    } else {
        return 'O';
    }
}

void gameBoard::getCoords()
{
    char player = getPlayerTurn();
    cout << "Player " << player << ", enter the square you want to fill (eg, 2 1) with the bottom coordinate first." << endl;
    cin  >> x >> y;
    cout << endl;
    if (check_in_grid() && check_grid_empty()){
        fillSquare(player);
        printGrid();
        changeTurn();
    }
}

bool gameBoard::check_in_grid()
{
    if (x < 0 || x > 3 || y < 0 || y > 3) {
        cout << "The numbers must align with the grid." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

bool gameBoard::check_grid_empty()
{
    if (gameGrid[x-1][y-1] != ' ') {
        cout << "That grid is already taken, pick another." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

void  gameBoard::fillSquare(char player)
{
    gameGrid[x-1][y-1] =  player;
}

void gameBoard::changeTurn()
{
    if (turn) {
        turn  =  0;
    } else {
        turn =  1;
    }
}

bool gameBoard::run_wincon_checks()
{
    if (check_for_D_diag_win()) {
        return true;
    }
    if (check_for_U_diag_win()) {
        return true;
    }
    if (check_for_horiz_win()) {
        return true;
    }
    if (check_for_vert_win()) {
        return true;
    }
    return false;
}

bool gameBoard::check_for_D_diag_win()
{
    if ((gameGrid[0][2] != ' ' && gameGrid[0][2] == gameGrid[1][1] && gameGrid[0][2] == gameGrid[2][0])) {
        cout << "Congratulations player " << gameGrid[0][2] << ", you won diagonally!" << endl;
        return true;
    } else {return false;}
}

bool gameBoard::check_for_U_diag_win()
{   if ((gameGrid[0][0] != ' ' && gameGrid[0][0] == gameGrid[1][1] && gameGrid[0][0] == gameGrid[2][2])) {
        cout << "Congratulations player " << gameGrid[0][0] << ", you won diagonally!" << endl;
        return true;
    } else {return false;}
}

bool gameBoard::check_for_vert_win()
{
    if (gameGrid[0][0] != ' ' && gameGrid[0][0] == gameGrid[0][1] && gameGrid[0][0] == gameGrid[0][2]) {
        cout << "Congratulations player "  << gameGrid[0][0] << ", you won vertically in column 1!"  << endl;
        return true;
    } else if (gameGrid[1][0] != ' ' && gameGrid[1][0] == gameGrid[1][1] && gameGrid[1][0] == gameGrid[1][2]) {
        cout << "Congratulations player "  << gameGrid[1][0] << ", you won vertically in column 2!"  << endl;
        return true;
    }   else if (gameGrid[2][0] != ' ' && gameGrid[2][0] == gameGrid[2][1] && gameGrid[2][0] == gameGrid[2][2]) {
        cout << "Congratulations player "  << gameGrid[2][0] << ", you won vertically in column 3!"  << endl;
        return true;
    } else {return false;}
}

bool gameBoard::check_for_horiz_win() {
        if (gameGrid[0][0] != ' ' && gameGrid[0][0] == gameGrid[1][0] && gameGrid[0][0] == gameGrid[2][0]) {
        cout << "Congratulations player "  << gameGrid[0][0] << ", you won horizontally in row 1!"  << endl;
        return true;
    } else if (gameGrid[0][1] != ' ' && gameGrid[0][1] == gameGrid[1][1] && gameGrid[0][1] == gameGrid[2][1]) {
        cout << "Congratulations player "  << gameGrid[1][0] << ", you won horizontally in row 2!"  << endl;
        return true;
    }   else if (gameGrid[0][2] != ' ' && gameGrid[0][2] == gameGrid[1][2] && gameGrid[0][2] == gameGrid[2][2]) {
        cout << "Congratulations player "  << gameGrid[2][0] << ", you won horizontally in row 3!"  << endl;
        return true;
    } else {return false;}
}
