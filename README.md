#Tic Tac Toe
**Description**
This is a simple console-based Tic Tac Toe game implemented in C++. The game allows two players to take turns entering their moves and provides visual feedback through color-coded board updates. The game ends when either player wins or the board is full with no winner.

**Features**
**Turn-Based Play:** Two players (X and O) alternate turns to make their moves.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/1e67e044-496b-451e-a2a3-9cd09862fdfd)
**Visual Feedback:** The console displays the game board with colors indicating player moves.

**Input Validation:** Ensures players enter valid moves and prompts them to re-enter if necessary.
**Win Detection:** The game checks for a winner after each move and declares the winner or a draw.
![image](https://github.com/Leen-ak/Tic-Tac-Toe/assets/109052421/c9a377f8-d2db-475a-86e5-26d09491ddd2)

**Code Structure**
**TicTacToe.h:** Header file containing the TicTacToe class definition.
**TicTacToe.cpp:** Implementation of the TicTacToe class methods.
**main.cpp:** Contains the main function that initializes and starts the game.

**Class Details**
**TicTacToe**
- Public Methods
TicTacToe(): Constructor that initializes the game board and flags.
void playGame(): Manages the turn-based flow of the game.

- Private Methods
void setColor(int color): Changes the text color in the console.
void resetColor(): Resets the console text color to the default.
void printHeader(): Prints the game title.
bool checkWinner(): Checks if there is a winner.
void printBoard(): Prints the current state of the game board.
bool playerMove(char player, char& input, char symbol): Handles a player's move.
void gameEnd(): Prints the game result.

**Dependencies**
**Windows Console:** The game uses Windows-specific functions to change text color and clear the screen. It is designed to run on Windows systems.

**Future Improvements**
Add a single-player mode with AI.

**Author**
Leen Aboukhalil


Windows Console: The game uses Windows-specific functions to change text color and clear the screen. It is designed to run on Windows systems.
