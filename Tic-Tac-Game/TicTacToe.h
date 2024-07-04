/*
* Name:		Leen Aboukhalil
* Purpose:	Implementation of a Tic Tac Toe game with console interface and player interaction.
* Date:		26/JUNE/2024
*/


#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <windows.h>

class TicTacToe {

public:
    TicTacToe();                     //constructor to initialize the game
    void playGame();                 //function to start and play the game

private:
    void setColor(int color);        //set text color in console
    void resetColor();               //reset text color to default
    void printHeader();              //print the game title/header
    bool isOnePlayerOrTwo();         //determine if the game will be one-player or two-player
    void printBoard();               //print the current game board
    bool checkWinner();              //check if there's a winner
    bool computerGame();             //execute the computer's move in a single-player
    bool playerMove(char player, char& input, char symbol); // Handle player's move
    void gameEnd();                  //end the game and display result
    bool makeMove(std::vector<char>& board, char x, char o);        //make a move for the computer against the player
    bool makeRandomMove(std::vector<char>& board, char x, char o);  //make a random move for the computer against the player

    //constant and static variables 
    static const char PLAYER_X = 'X';
    static const char PLAYER_O = 'O';
    static const int BLUE_COLOR = 1;
    static const int GREEN_COLOR = 2;
    static const int RED_COLOR = 4;
    static const int WHITE_COLOR = 7;
    static const int GRAY_COLOR = 8;
    static const int SPACE_SIZE = 9;
    static const int LAST_MOVE = 0; 

    std::vector<char> board;         //vector to store the game board
    bool winner;         
    bool validMove;                  //flag to indicate if there's a winner
    bool wrongInput;                 //flag to track incorrect input
    bool playerOne;                  //flag for player one's turn
    bool playerTwo;                  //flag for player two's turn
    bool computerGameSwitch;         //flag for computer player
    bool playersGame;                //flag for two players 
    bool computerTurn;               //flag for computer turn
    char firstUser;                  //flag for the firstUser turn
    char secondUser;                 //flag for the secondUser turn
    char players;                    //flag to take the char of the player if it is x or o  
    char input;                      //flag to take the input of the player and replace it with x or o 
    char symbol;                     //flag for the symbol if it is x or o 
    int userGame;                    //determine if the game is for two players or players against the computer  
    int count;                       //count of remaining moves
};


#endif
