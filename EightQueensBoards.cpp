/*
 
 Write an algorithm to print all ways of arranging eight queens on a chess board so that none of them share the same row, column or diagonal
 
 Solution:
 Use backtracking algorithm, for each row, the column where we want to put the queen
 is based on checking that it does not violate the required conditions.
 */

#include <iostream>

using namespace std;

void printBoard(int rowOfQueens[])
{
  for (int i = 1; i <= 8; i ++) {
    for (int j = 1; j <= 8; j ++) {
      if (rowOfQueens[j] == i) {
        cout << " *";
      } else {
        cout << " o";
      }
    }
    cout << endl;
  }
}

bool isInvalid(int currentQueen, int row, int rowOfQueens[])
{
  for (int i = 1; i < currentQueen; i ++) {
    if (rowOfQueens[i] == row
        || abs(rowOfQueens[i] - row) == abs(i - currentQueen)) {
      return true;
    }
  }
  
  return false;
}

void eightQueens(int currentQueen, int rowOfQueens[], int & count)
{
  if (currentQueen > 8) {
    cout << ++count << ":" << endl;
    printBoard(rowOfQueens);
    cout << endl;
    return;
  }
  
  for (int row = 1; row <= 8; row ++) {
    bool flag = false;
    for (int i = 1; i < currentQueen; i ++) {
      if (isInvalid(currentQueen, row, rowOfQueens)) {
        flag = true; // the current row is used already
        break;
      }
    }
    
    if (!flag) {
      rowOfQueens[currentQueen] = row;
      eightQueens(currentQueen + 1, rowOfQueens, count);
      rowOfQueens[currentQueen] = 0;
    }
  }
}

int main()
{
  int rowOfQueens[9];
  int count = 0;
  memset(rowOfQueens, 0, sizeof(rowOfQueens));
  eightQueens(1, rowOfQueens, count);
  
  return 0;
}