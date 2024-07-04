Tic Tac Toe Game
**Overview**
This is a console-based implementation of the classic Tic Tac Toe game developed in C++. The game supports single-player and two-player modes, allowing players to play against each other or against the computer.

**Features**
**Console Interface:** A simple, easy-to-use console interface for gameplay.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/056399ff-967a-4158-9f28-fd0048faa511)
**Two-Player Mode:** Play against another human player.
**Single-Player Mode:** Play against a computer opponent.
**Visual Feedback:** The console displays the game board with colors indicating player moves.
**Input Validation:** Ensures players enter valid moves and prompts them to re-enter if necessary.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/b90f0610-667d-44d0-a5b5-3b0bdee994fd)
**Win Detection:** The game checks for a winner after each move and declares the winner or a draw.

**How to Play**
**Two-Player Mode**
1. Choose the two-player mode at the start.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/a2e73e9c-6760-4aef-8b98-3cfbfe148844)
2. Player 1 will use 'X' and Player 2 will use 'O'.
3. Players take turns to enter a number corresponding to the cell where they want to place their symbol.
4. The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins the game.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/a5f199fa-b11f-40ea-957d-44ef39a6ea33)
5. If all cells are filled and no player has three in a row, the game ends in a draw.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/4a23f77e-1b71-4898-8d6e-d2137736681e)

**Single-Player Mode**
1. Choose the single-player mode at the start.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/6a76e11d-cb81-417c-9582-ba2fc0152796)
2. The player will use 'X' and the computer will use 'O'.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/9eaf5e6e-26c5-4437-9176-5dd7437d4d2b)
3. The player takes the first turn, followed by the computer.
4. The game follows the same winning and draw conditions as the two-player mode.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/21112128-e857-4d91-b52c-535d588a8853)


**Compilation and Execution**
**Prerequisites**
A C++ compiler (e.g., g++, Visual Studio, etc.)
Windows operating system (for the console color functionality)

**Code Structure**
**TicTacToe.h:** Header file containing the TicTacToe class definition and function declarations.
**TicTacToe.cpp:** Implementation of the TicTacToe class methods.
**main.cpp:** Contains the main function that initializes and starts the game.

**Class Details**
**TicTacToe**
- Public Methods
TicTacToe(): Constructor that initializes the game board and flags.
void playGame(): Manages the turn-based flow of the game.

- Private Methods
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

**Dependencies**
**Windows Console:** The game uses Windows-specific functions to change text color and clear the screen. It is designed to run on Windows systems.

**Author**
Leen Aboukhalil


Windows Console: The game uses Windows-specific functions to change text color and clear the screen. It is designed to run on Windows systems.
