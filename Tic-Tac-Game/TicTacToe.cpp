/*
* Name:		Leen Aboukhalil
* Purpose:	Implementation of a Tic Tac Toe game with console interface and player interaction.
* Date:		26/JUNE/2024
*/

#include "TicTacToe.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <windows.h>

// Constructor initializes the game board and flags
TicTacToe::TicTacToe()
    : board{ '1', '2', '3', '4', '5', '6', '7', '8', '9' }, winner(false), wrongInput(false), playerOne(false), playerTwo(false), count(9) {}

// Set console text color
void TicTacToe::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Reset console text color to default
void TicTacToe::resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

// Print game title/header
void TicTacToe::printHeader() {
    setColor(8); // Set color for header text
    std::cout << "\n=== Welcome to Tic Tac Toe Game";
    setColor(1); // Set color for 'X'
    std::cout << " (X)";
    setColor(2); // Set color for 'O'
    std::cout << "(O)";
    setColor(8); // Reset color to default
    std::cout << " ===" << std::endl;
    resetColor(); // Reset color after printing
}

// Print the current game board
void TicTacToe::printBoard() {
    printHeader(); // Print the game title/header
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "                 " << (char)179 << "                 " << (char)179 << "                 " << std::endl;
        for (int j = 0; j < 3; ++j) {
            int index = i * 3 + j;
            if (board[index] == 'X') {
                setColor(1); // Set color for 'X'
            }
            else if (board[index] == 'O') {
                setColor(2); // Set color for 'O'
            }

            std::cout << std::setw(9) << board[index];
            resetColor(); // Reset color after printing each character

            if (j < 2) {
                std::cout << std::setw(9) << (char)179;
            }
        }
        std::cout << std::setw(9) << std::endl;
        std::cout << "                 " << (char)179 << "                 " << (char)179 << "                 " << std::endl;

        if (i < 2) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 17; ++l) {
                    std::cout << (char)196; // Print horizontal line
                }
                if (k < 2) {
                    std::cout << (char)197; // Print intersection character
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Check if there's a winner based on the current board state
bool TicTacToe::checkWinner() {
    return board[0] == board[1] && board[1] == board[2]
        || board[3] == board[4] && board[4] == board[5]
        || board[6] == board[7] && board[7] == board[8]
        || board[0] == board[4] && board[4] == board[8]
        || board[2] == board[4] && board[4] == board[6]
        || board[0] == board[3] && board[3] == board[6]
        || board[1] == board[4] && board[4] == board[7]
        || board[2] == board[5] && board[5] == board[8]
        || false;
}

// Handle player's move
bool TicTacToe::playerMove(char player, char& input, char symbol) {
    std::cout << "Player " << player << " -> '" << symbol << "', Enter a number: ";
    std::cin >> input;

    auto it = std::find(board.begin(), board.end(), input);
    for (int i = 0; i < board.size(); ++i) {
        if (it != board.end()) {
            if (board[i] == *it && (board[i] != symbol || board[i] != symbol)) {
                count--;
                board[i] = symbol;
                system("cls"); // Clear screen (Windows specific)
                TicTacToe::printBoard();
                break;
            }
        }
        else {
            if (!wrongInput) {
                setColor(8); // Set color for error message
                std::cout << "Choose a number between (1 - 9). Error: <" << input << ">" << std::endl;
                std::cout << "Player " << player << " -> '" << symbol << "', Enter a number: ";
                std::cin >> input;
                resetColor(); // Reset color to default

                it = board.begin();
                it = std::find(board.begin(), board.end(), input);
                if (it != board.end())
                    wrongInput = true;
                else
                    continue;
            }
        }
    }

    winner = checkWinner(); // Check if there's a winner after each move

    if (winner)
        return true;
    return false;
}

// End the game and display result
void TicTacToe::gameEnd() {
    setColor(4); // Set color for game end message
    if (playerOne)
        std::cout << "Player one has won." << std::endl;
    else if (playerTwo)
        std::cout << "Player two has won." << std::endl;
    else
        std::cout << "GAME OVER" << std::endl;
    resetColor(); // Reset color to default after printing
}

// Start and control the flow of the game
void TicTacToe::playGame() {
    printBoard(); // Print initial game board

    char firstUser;
    char secondUser;
    while (!winner && count > 1) {
        setColor(1); // Set color for player one's turn
        playerOne = playerMove('1', firstUser, 'X');
        if (playerOne || count == 0) break;

        setColor(2); // Set color for player two's turn
        playerTwo = playerMove('2', secondUser, 'O');
        if (playerTwo || count == 0) break;

        resetColor(); // Reset color after each move
    }

    gameEnd(); // Display game end message
}

