#include <iostream>
using namespace std;

// Board setup
char board[3][3] = {{'1', '2', '3'}, 
                    {'4', '5', '6'}, 
                    {'7', '8', '9'}};

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if there's a winner
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

// Function to check if the board is full (tie)
bool isTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Main game function
void playGame() {
    int player = 1;
    char mark;
    int choice;
    bool gameWon = false;

    while (!gameWon && !isTie()) {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        cout << "Player " << player << ", enter your choice: ";
        cin >> choice;

        // Validate the choice and update the board
        bool validMove = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == (choice + '0')) {
                    board[i][j] = mark;
                    validMove = true;
                    break;
                }
            }
            if (validMove) break;
        }

        if (!validMove) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        gameWon = checkWin();
        if (!gameWon) player++;
    }

    displayBoard();

    if (gameWon) {
        cout << "Congratulations! Player " << player << " wins!\n";
    } else {
        cout << "It's a tie!\n";
    }
}

// Main function
int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playGame();
    return 0;
}
