#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {

public:
    TicTacToe();                     // Constructor to initialize the game
    void playGame();                 // Function to start and play the game

private:
    void setColor(int color);        // Set text color in console
    void resetColor();               // Reset text color to default
    void printHeader();              // Print the game title/header
    bool checkWinner();              // Check if there's a winner
    void printBoard();               // Print the current game board
    bool playerMove(char player, char& input, char symbol); // Handle player's move
    void gameEnd();                  // End the game and display result

    std::vector<char> board;         // Vector to store the game board
    bool winner;                     // Flag to indicate if there's a winner
    bool wrongInput;                 // Flag to track incorrect input
    bool playerOne;                  // Flag for player one's turn
    bool playerTwo;                  // Flag for player two's turn
    int count;                       // Count of remaining moves
};

#endif // TICTACTOE_H
