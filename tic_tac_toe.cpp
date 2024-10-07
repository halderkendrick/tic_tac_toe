#include <iostream>
#include <vector>

char currentPlayer;
std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

void printBoard() {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << ' ';
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << '|';
        }
        std::cout << '\n';
        if (i < 2) std::cout << "  -----\n";
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // Empty cell found
        }
    }
    return true; // No empty cells, it's a draw
}

int main() {
    currentPlayer = 'X';
    int row, col;
    bool gameEnded = false;

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameEnded) {
        printBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        // Check for win or draw
        if (checkWin()) {
            printBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameEnded = true;
        } else if (checkDraw()) {
            printBoard();
            std::cout << "It's a draw!\n";
            gameEnded = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
