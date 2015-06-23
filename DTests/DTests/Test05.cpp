#include "DTests.h"

/* Question 05
- An array [3][3] represent a tic tac toe board
- 0 represents empty square
- Otherwise we don't know which symbol (X and O) is represented by which value
Write a function to check which player wins, or the game is a draw
Assumption:There can be at most only one winner on the board
*/

//return a char that is represents a winner; return 0 if there's no winner
//Algorithm O(n^2) with n being the side of the board
// In a true game, it can be improve by checking only the row / col on which the latest move is made
char getWinner(int boardSize, char** board) {

  //check for rows
  for (int i = 0; i < boardSize; i++) {
    char value = board[i][0];
    if (value != 0) {
      for (int j = 1; j < boardSize; j++) {
        if (board[i][j] != value) {
          goto getWinner_break_row; //necessary evil
        }
      }
      return value; //return at first encounter
    }
    getWinner_break_row: true; //dummy code, doing nothing
  }

  //check for cols
  for (int i = 0; i < boardSize; i++) {
    char value = board[0][i];
    if (value != 0) {
      for (int j = 1; j < boardSize; j++) {
        if (board[j][i] != value) {
          goto getWinner_break_col;
        }
      }
      return value;
    }
    getWinner_break_col: true;
  }

  //check left diagonal row
  char value = board[0][0];
  if (value != 0) {
    for (int i = 1; i < boardSize; i++) {
      if (board[i][i] != value) {
        goto getWinner_break_diagonal_1; //necessary evil
      }
    }
    return value;
  }
  getWinner_break_diagonal_1: true;

  //check right diagonal row
  value = board[0][boardSize - 1];
  if (value != 0) {
    for (int i = 1; i < boardSize; i++) {
      if (board[i][boardSize - 1 - i] != value) {
        goto getWinner_break_diagonal_2; //necessary evil
      }
    }
    return value;
  }
  getWinner_break_diagonal_2: true;

  return 0;
}
