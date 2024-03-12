#include <iostream>
#include <vector>

using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

enum class Player {
    NONE,
    X,
    O
};

// Function to draw the tic-tac-toe board
void drawBoard(const vector<vector<Player>>& board) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            switch (board[i][j]) {
                case Player::X:
                    cout << " X ";
                    break;
                case Player::O:
                    cout << " O ";
                    break;
                default:
                    cout << "   ";
                    break;
            }
            if (j < MAX_COLS - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < MAX_ROWS - 1) {
            cout << "---+---+---" << endl;
        }
    }
}

// Function to check if the game is over
bool isGameOver(const vector<vector<Player>>& board) {
    // Check rows
    for (int i = 0; i < MAX_ROWS; ++i) {
        if (board[i][0] != Player::NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < MAX_COLS; ++j) {
        if (board[0][j] != Player::NONE && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] != Player::NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != Player::NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

int main() {
    vector<vector<Player>> board(MAX_ROWS, vector<Player>(MAX_COLS, Player::NONE));
    Player currentPlayer = Player::X;

    int row, col;
    bool isDraw = false;

    // Game loop
    while (!isGameOver(board)) {
        drawBoard(board);
        cout << "Player " << (currentPlayer == Player::X ? "X" : "O") << "'s turn. Enter row and column: ";
        cin >> row >> col;

        // Check if the chosen position is valid and empty
        if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS || board[row][col] != Player::NONE) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Set the chosen position with the current player's symbol
        board[row][col] = currentPlayer;

        // Switch to the next player
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;

        // Check for a draw
        isDraw = true;
        for (int i = 0; i < MAX_ROWS; ++i) {
            for (int j = 0; j < MAX_COLS; ++j) {
                if (board[i][j] == Player::NONE) {
                    isDraw = false;
                    break;
                }
            }
            if (!isDraw) {
                break;
            }
        }
    }

    drawBoard(board);

    // Print the result
    if (isDraw) {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << (currentPlayer == Player::X ? "O" : "X") << " wins!" << endl;
    }

    return 0;
}
