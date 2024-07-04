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

//constructor initializes the game board and flags
TicTacToe::TicTacToe()
    : board{ '1', '2', '3', '4', '5', '6', '7', '8', '9' }, winner(false), wrongInput(false), playerOne(false), playerTwo(false),
    computerGameSwitch(false), computerTurn(false), playersGame(false), validMove(false), firstUser('x'), secondUser('x'),
    players('x'), input('0'), symbol('x'), userGame(0), count(9) {}

/*
fn:		  setColor
brief:	  Set console text color
param:    int
return:   void
*/
void TicTacToe::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/*
fn:		  resetColor
brief:	  Reset console text color to default
param:    nothing
return:   void
*/
void TicTacToe::resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

/*
fn:		  printHeader
brief:	  Print game title/header
param:    nothing
return:   void
*/
void TicTacToe::printHeader() {
    setColor(GRAY_COLOR);                   //set color for header text
    std::cout << "\n=== Welcome to Tic Tac Toe Game";
    setColor(BLUE_COLOR);                   //set color for 'X'
    std::cout << " (X)";
    setColor(GREEN_COLOR);                  //set color for 'O'
    std::cout << "(O)";
    setColor(GRAY_COLOR);                   //reset color to default
    std::cout << " ===" << std::endl;
    resetColor();                           //reset color after printing
}

/*
fn:		  printBoard
brief:	  Print the current game board
param:    nothing
return:   void
*/
void TicTacToe::printBoard() {
    printHeader();                              //print the game title/header
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "                 " << (char)179 << "                 " << (char)179 << "                 " << std::endl;
        for (int j = 0; j < 3; ++j) {
            int index = i * 3 + j;              //to store the position of j in te=he variable index and then use it to change the color
            if (board[index] == 'X') {
                setColor(BLUE_COLOR);           //set color for 'X'
            }
            else if (board[index] == 'O') {
                setColor(GREEN_COLOR);          //set color for 'O'
            }

            std::cout << std::setw(SPACE_SIZE) << board[index];
            resetColor();                       //reset color after printing each character

            if (j < 2) {                        //it j less than 2 that's mean print this '│' ASCII characters
                std::cout << std::setw(SPACE_SIZE) << (char)179;
            }
        }
        std::cout << std::setw(SPACE_SIZE) << std::endl;
        std::cout << "                 " << (char)179 << "                 " << (char)179 << "                 " << std::endl;

        if (i < 2) {                          //if i less than 2 that's mean print this ASCII characters '─' 
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 17; ++l) {
                    std::cout << (char)196;   //print horizontal line
                }
                if (k < 2) {
                    std::cout << (char)197;  //print intersection character
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

/*
fn:		  checkWinner
brief:	  Check if there's a winner based on the current board state
param:    nothing
return:   bool
*/
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

/*
fn:		  playerMove
brief:	  Handle player's move
param:    char, char, char
return:   bool
*/
bool TicTacToe::playerMove(char player, char& input, char symbol) {
    validMove = false;
    while (!validMove) {
        wrongInput = false;                                            //set wrongInput to false to make sure if there is a wrong input it will enter the if statement  
        if (wrongInput)                                                //if wrongInput was true that means there is an error appears so it will set the color to gray 
            setColor(GRAY_COLOR);

        std::cout << "Player " << player << " -> '" << symbol << "', Enter a number: ";
        std::cin >> input;

        auto it = std::find(board.begin(), board.end(), input);       //search for the input of the user if it exists in the board vector 
        for (int i = 0; i < board.size(); ++i) {
            if (it != board.end()) {                                  //if the iterator doesn't reach the end of the vector that means the input of the user exists in the board vector
                if (board[i] == *it && board[i] != symbol) {
                    count--;                                          //count from 9 to zero to end the game 
                    board[i] = symbol;                                //assigning the input to the board vector
                    system("cls");                                    //clear screen (Windows specific)
                    TicTacToe::printBoard();                          //print the board again after assigning x or o to the board to print it on the screen 
                    validMove = true;                                 //make the switch to true to exit from the while loop 
                    break;                                            //exit from the while loop 
                }
            }
        }

        //if did not enter the while loop that means the validMove still false which means there is an error with the input of the user 
        if (!validMove && !wrongInput) {
            setColor(GRAY_COLOR);                                     //set color for error message
            std::cout << "Choose a number between (1 - 9). Error: <" << input << ">" << std::endl;
            wrongInput = true;                                        //set wrongInput to true to exit from the if statement and check again if the input is correct with the while loop
        }
    }

    winner = checkWinner();                                           // Check if there's a winner after each move

    if (winner)                                                       //if winner is true there is a winner if it is not there is no winner 
        return true;
    return false;
}

/*
fn:		  gameEnd
brief:	  End the game and display result
param:    nothing
return:   void
*/
void TicTacToe::gameEnd() {
    setColor(RED_COLOR); //set color for game end message
    if (playerOne)
        std::cout << "Congratulations Player 1 has won the game." << std::endl;
    else if (playerTwo)
        std::cout << "Congratulations Player 2 has won the game." << std::endl;
    else if (computerTurn)
        std::cout << "Game Over! The computer has won. Better luck next time!" << std::endl;
    else
        std::cout << "GAME OVER! It's a draw" << std::endl; 
    resetColor(); //reset color to default after printing
}

/*
fn:		  playGame
brief:	  Start and control the flow of the game
param:    nothing
return:   void
*/
void TicTacToe::playGame() {
    printHeader();                                              //print header
    isOnePlayerOrTwo();                                         //check if it is one player or two     
    system("cls");                                              //clear the console
    printBoard();                                               //print initial game board

    while (!winner && count > LAST_MOVE) {                              //while winner switch is false and count greater than zero the game will continue 
        setColor(BLUE_COLOR);                                   //set color for player one's turn

        if (playersGame) {                                      //playerGame is true which means the game has two players
            playerOne = playerMove('1', firstUser, PLAYER_X);   //store the return of the function in playerOne to check later for the winner player
            if (playerOne || count == LAST_MOVE) break;                 //if the count is zero that means the players play 9 times so if playerOnes is still false that means playerOne has lost and if it is true means playerOne has won

            setColor(GREEN_COLOR);                              //set color for player two's turn
            playerTwo = playerMove('2', secondUser, PLAYER_O);  //checking the state of playerTwo
            if (playerTwo || count == LAST_MOVE) break;
            resetColor();                                       //reset color after each move
        }
        else if (computerGameSwitch){                           //if computerGameSwitch is true, it means the game is between one player and the computer 
            playerOne = playerMove('1' ,firstUser, PLAYER_X);
            if (playerOne || count == LAST_MOVE) break; 

            setColor(GREEN_COLOR);
            computerTurn = computerGame();                      //calling computerGame and store the return of the function in computerTurn to check later for the winner player
            if (computerTurn || count == LAST_MOVE) break;
            resetColor();
        }
    }
    gameEnd();                                                  //display game end message
}

/*
fn:		  computerGame
brief:	  function allows the computer to make a move in the Tic Tac Toe game
param:    nothing
return:   bool
*/
bool TicTacToe::computerGame() {
    validMove = false; 

    while (!validMove) {
        if (makeMove(board, PLAYER_X, PLAYER_O) || makeRandomMove(board, PLAYER_X, PLAYER_O))   //if makeMove or makeRandomMove retrun true the game will continue
            validMove = true; 
        count--;
        system("cls");  
        printBoard();
        break; 
    }

    winner = checkWinner();                                                                     //check if there is a winner

    if (winner)
        return true;
    else
        return false;
        
}

/*
fn:		  isOnePlayerOrTwo
brief:	  Determine if the game will be played by one player against the computer or tow players against each other
param:    nothing
return:   bool
*/
bool TicTacToe::isOnePlayerOrTwo() {
    setColor(GRAY_COLOR);
    std::cout << "\n\nWould you like to play a (2 player) game or (1 player) game against the computer?\nPlease enter '2' for a (2 player) game or '1' for a (1 player) game\n";
    std::cin >> userGame;

    //check the user answer to determine if it is a two-player game or a player against the computer 
    if (userGame == 1)
        return computerGameSwitch = true;
    else if (userGame == 2)
        return playersGame = true;
    else
        return false; 
}

/*
fn:		  makeMove
brief:	  Attempt to make a strategic move for the computer player (PLAYER_O) by checking for winning or blocking opportunities.
          If a valid move is found and made, the function returns true. If no such move can be made, it returns false.
param:    vector<char>, char, char, int
return:   bool
*/
bool TicTacToe::makeMove(std::vector<char>& board, char PLAYER_X, char PLAYER_O) {
    //first row 
    if (board[4] == '5')
        board[4] = PLAYER_O;
    else if (board[4] == PLAYER_X && board[0] == '1')
        board[0] = PLAYER_O;
    else if (board[0] == PLAYER_X && board[1] == PLAYER_X && board[2] == '3')
        board[2] = PLAYER_O;
    else if (board[0] == PLAYER_X && board[2] == PLAYER_X && board[1] == '2')
        board[1] = PLAYER_O;
    else if (board[1] == PLAYER_X && board[2] == PLAYER_X && board[0] == '1')
        board[0] = PLAYER_O;
    //second row
    else if (board[3] == PLAYER_X && board[4] == PLAYER_X && board[5] == '6')
        board[5] = PLAYER_O;
    else if (board[3] == PLAYER_X && board[5] == PLAYER_X && board[4] == '5')
        board[4] = PLAYER_O;
    else if (board[4] == PLAYER_X && board[5] == PLAYER_X && board[3] == '4')
        board[3] = PLAYER_O;
    //third row
    else if (board[6] == PLAYER_X && board[7] == PLAYER_X && board[8] == '9')
        board[8] = PLAYER_O;
    else if (board[6] == PLAYER_X && board[8] == PLAYER_X && board[7] == '8')
        board[7] = PLAYER_O;
    else if (board[7] == PLAYER_X && board[8] == PLAYER_X && board[6] == '7')
        board[6] = PLAYER_O;
    //first column
    else if (board[0] == PLAYER_X && board[3] == PLAYER_X && board[6] == '7')
        board[6] = PLAYER_O;
    else if (board[0] == PLAYER_X && board[6] == PLAYER_X && board[3] == '4')
        board[3] = PLAYER_O;
    else if (board[3] == PLAYER_X && board[6] == PLAYER_X && board[0] == '1')
        board[0] = PLAYER_O;
    //second column
    else if (board[1] == PLAYER_X && board[4] == PLAYER_X && board[7] == '8')
        board[7] = PLAYER_O;
    else if (board[1] == PLAYER_X && board[7] == PLAYER_X && board[4] == '5')
        board[4] = PLAYER_O;
    else if (board[4] == PLAYER_X && board[7] == PLAYER_X && board[1] == '2')
        board[1] = PLAYER_O;
    //third column 
    else if (board[2] == PLAYER_X && board[5] == PLAYER_X && board[8] == '9')
        board[8] = PLAYER_O;
    else if (board[2] == PLAYER_X && board[8] == PLAYER_X && board[5] == '6')
        board[5] = PLAYER_O;
    else if (board[5] == PLAYER_X && board[8] == PLAYER_X && board[2] == '3')
        board[2] = PLAYER_O;
    //right to lift angle
    else if (board[2] == PLAYER_X && board[4] == PLAYER_X && board[6] == '7')
        board[6] = PLAYER_O;
    else if (board[2] == PLAYER_X && board[6] == PLAYER_X && board[4] == '5')
        board[4] = PLAYER_O;
    else if (board[4] == PLAYER_X && board[6] == PLAYER_X && board[2] == '3')
        board[2] = PLAYER_O;
    //left to right 
    else if (board[0] == PLAYER_X && board[4] == PLAYER_X && board[8] == '9')
        board[8] = PLAYER_O;
    else if (board[0] == PLAYER_X && board[8] == PLAYER_X && board[4] == '5')
        board[4] = PLAYER_O;
    else if (board[4] == PLAYER_X && board[8] == PLAYER_X && board[0] == '1')
        board[0] = PLAYER_O;
    else
        return false;                   //return false to go and check the other method (makeRandomMove) if none of those if statements are true 
    return true; 
}

/*
fn:		  makeRandomMove
brief:	  make a random move for the computer player (PLAYER_O) by placing PLAYER_O in the first available spot on the board.
param:    vector<char>, char, char, int
return:   bool
*/
bool TicTacToe::makeRandomMove(std::vector<char>& board, char PLAYER_X, char PLAYER_O) {
    //if a move is made, the function returns true. If no available spots are found, it returns false. 
     for (int i = 0; i < board.size(); ++i) {
        if (board[i] != PLAYER_X && board[i] != PLAYER_O) {
             board[i] = PLAYER_O;
             return true;
        }
     }
     return false; 
}
