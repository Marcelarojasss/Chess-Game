#include <iostream>
#include <string>
#include <vector>
#include <cctype>

const int BOARD_SIZE = 8;

// Function to initialize the chessboard
void initializeBoard(std::vector<std::vector<char>>& board) {
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[1][i] = 'P'; // White pawns
        board[6][i] = 'p'; // Black pawns
    }

    // Initialize the rest of the pieces
    board[0][0] = board[0][7] = 'R';
    board[0][1] = board[0][6] = 'N';
    board[0][2] = board[0][5] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';

    board[7][0] = board[7][7] = 'r';
    board[7][1] = board[7][6] = 'n';
    board[7][2] = board[7][5] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';

    // Initialize empty squares
    for (int i = 2; i <= 5; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '.';
        }
    }
}

// Function to print the chessboard
void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  a b c d e f g h\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << 8 - i << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << 8 - i << std::endl;
    }
    std::cout << "  a b c d e f g h\n";
}

// Convert file (column) from char to int index
int fileToIndex(char file) {
    return tolower(file) - 'a';
}

// Convert rank (row) from char to int index
int rankToIndex(char rank) {
    return '8' - rank;
}

// Function to move a piece
void movePiece(std::vector<std::vector<char>>& board, const std::string& move) {
    int fromFile = fileToIndex(move[0]);
    int fromRank = rankToIndex(move[1]);
    int toFile = fileToIndex(move[3]);
    int toRank = rankToIndex(move[4]);

    char piece = board[fromRank][fromFile];
    board[fromRank][fromFile] = '.';
    board[toRank][toFile] = piece;
}

// Main function to run the chess game
int main() {
    std::vector<std::vector<char>> chessBoard(BOARD_SIZE, std::vector<char>(BOARD_SIZE));
    initializeBoard(chessBoard);

    std::string move;
    while (true) {
        printBoard(chessBoard);

        std::cout << "Enter your move (e.g., e2 e4): ";
        std::getline(std::cin, move);

        if (move.length() == 5 && move[2] == ' ') {
            movePiece(chessBoard, move);
        } else {
            std::cout << "Invalid input format. Try again." << std::endl;
            continue;
        }

        // Add checks for game end conditions here (not implemented in this example)
    }

    return 0;
}