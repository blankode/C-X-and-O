#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void displayTable(char table[][3]) {
  cout << "________________\n";
  cout << "x/y| 0 | 1 | 2 |\n";
  for (int i = 0; i < 3; ++i) {
    cout << " " << i << " | ";
    for (int j = 0; j < 3; ++j) {
      cout << table[i][j] << " | ";
    }
    cout << "\n";
  }
}

int main() {
  char table[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      table[i][j] = ' ';
    }
  }
  int maxMoves = 0, c[2];
  char currentPlayer;
  bool winnerFound = false;
  while (maxMoves != 9 && winnerFound == false) {
    system("CLS");
    if (maxMoves % 2 == 0) {
      currentPlayer = 'X';
    } else {
      currentPlayer = 'O';
    }
    displayTable(table);
    cout << "Now it's " << currentPlayer << "'s turn, state your coordinates:\n";
    cout << "Row and Column in this format > x y > ";
    cin >> c[0] >> c[1];;
    if (table[c[0]][c[1]] == ' ') {
      table[c[0]][c[1]] = currentPlayer;
    } else {
      --maxMoves;
    }
    if (maxMoves > 2) {
      //check rows
      char player;
      for (int l = 0, c = 0; l < 3; ++l) {
        player = table[l][c];
        if ((table[l][c + 1] == player && table[l][c + 2] == player) && player != ' ') {
          system("CLS");
          cout << flush;
          displayTable(table);
          cout << player << " WON!";
          winnerFound = true;
          break;
        }
      }
      //check columns
      for (int l = 0, c = 0; c < 3 && winnerFound == false; ++c) {
        player = table[l][c];
        if ((table[l + 1][c] == player && table[l + 2][c] == player) && player != ' ') {
          system("CLS");
          cout << flush;
          displayTable(table);
          cout << player << " WON!";
          winnerFound = true;
          break;
        }
      }
      //check diagonals
      if (winnerFound == false) {
        player = table[0][0];
        if ((table[1][1] == player && table[2][2] == player) && player != ' ') {
          system("CLS");
          cout << flush;
          displayTable(table);
          cout << player << " WON!";
          winnerFound = true;
        }
        player = table[2][0];
        if ((table[1][1] == player && table[0][2] == player) && player != ' ') {
          system("CLS");
          cout << flush;
          displayTable(table);
          cout << player << " WON!";
          winnerFound = true;
        }
      }

    }
    if (winnerFound == true) {
      break;
    }
    ++maxMoves;
  }
  if (maxMoves == 9 && winnerFound == false) {
    system("CLS");
    cout << flush;
    displayTable(table);
    cout << "It's a draw!";
  }
  return 0;
}
