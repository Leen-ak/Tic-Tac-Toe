/*
* Name:		Leen Aboukhalil
* Purpose:	Implementation of a Tic Tac Toe game with console interface and player interaction.
* Date:		26/JUNE/2024
*/


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

   static const char PLAYER_X = 'X';
   static const char PLAYER_O = 'O';
   static const int BLUE_COLOR = 1;
   static const int GREEN_COLOR = 2;
   static const int RED_COLOR = 4;
   static const int WHITE_COLOR = 7;
   static const int GRAY_COLOR = 8;
    std::vector<char> board;         // Vector to store the game board
    bool winner;                     // Flag to indicate if there's a winner
    bool wrongInput;                 // Flag to track incorrect input
    bool playerOne;                  // Flag for player one's turn
    bool playerTwo;                  // Flag for player two's turn
    int count;                       // Count of remaining moves
};

#endif // TICTACTOE_H
