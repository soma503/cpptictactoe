#include <iostream>
using namespace std;

struct Coord {
    int row, col;
};

// main functions
void printBoard();
Coord getInput(bool player1);
void placeChar(bool player1, Coord input);
bool checkWin();
// helper functions
bool canBePlaced(Coord input);
bool chooseWinner(int checks);

char board[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
};

int main() {
    
    int counter = 0;
    cout << "TIC-TAC-TOE!\n******************" << endl;
    printBoard();
    do {
        Coord input = getInput(counter % 2 == 0);
        placeChar(counter % 2 == 0, input);
        printBoard();
        counter++;
    } while (!checkWin());

    return 0;
}

Coord getInput(bool player1) {
    Coord result; 

    if (player1) cout << "Player 1: ";
    else  cout << "Player 2: ";

    do {
        cout << "Please enter row folowed by a space and col" << endl;
        cin >> result.row;
        cin >> result.col;
    } while (!canBePlaced(result));

    return result;

}

bool canBePlaced(Coord input) {
    //cout << input.row << input.col;
    return ( (input.row >= 0 && input.row < 3) && (input.col >= 0 && input.col < 3) &&
                (board[input.row][input.col] == ' ' ) );
            

}

void placeChar(bool player1, Coord input) {
    char symbol;
    if (player1) symbol = 'X';
    else symbol = 'O';

    board[input.row][input.col] = symbol;

}

bool chooseWinner(int checks) {
    if (checks == 3) {
        cout << "PLAYER1 HAS WON!!!" << endl;
        return true;
    } else if (checks == -3) {
        cout << "PLAYER2 HAS WON!!!" << endl;
        return true;
    }
    return false;
}

bool checkWin() {
    //CHECK HORIZONTALS
    int horizontalChecks;
    for (int row = 0; row < 3; row++) {
        horizontalChecks = 0;
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == 'X') horizontalChecks += 1;
            if (board[row][col] == 'O') horizontalChecks -= 1;
        }
        if (chooseWinner(horizontalChecks)) return true;
    }
    //CHECK VERTICALS
    int verticalChecks;
    for (int col = 0; col < 3; col++) {
        verticalChecks = 0;
        for (int row = 0; row < 3; row++) {
            if (board[row][col] == 'X') verticalChecks += 1;
            if (board[row][col] == 'O') verticalChecks -= 1;
        }
        if (chooseWinner(verticalChecks)) return true;
    }
    //CHECK DIAGONALS
    int dChecks = 0;
    for(int i = 0; i < 3; i++) {
        if (board[i][i] == 'X') dChecks += 1;
        if (board[i][i] == 'O') dChecks -= 1;
    }
    if (chooseWinner(dChecks)) return true;
    dChecks = 0;
    for(int row = 0, col = 2; row < 3; row++, col--) {
        if (board[row][col] == 'X') dChecks += 1;
        if (board[row][col] == 'O') dChecks -= 1;
    }
    if (chooseWinner(dChecks)) return true;
    return false;
}

void printBoard() {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (j == 2) cout << board[i][j] << endl;
            else cout << board[i][j] << " | ";

        }
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}