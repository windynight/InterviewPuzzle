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
  for (int row = 1; row <= 8; row ++) {
    for (int col = 1; col <= 8; col ++) {
      // col is also the queen's index
      if (rowOfQueens[col] == row) {
        cout << " *";
      } else {
        cout << " o";
      }
    }
    cout << endl;
  }
}

// Check if the current row is used already or not valid for the placed queens
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

void placeQueen(int currentQueen, int rowOfQueens[], int & count)
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
        flag = true; 
        break;
      }
    }
    
    if (!flag) {
      rowOfQueens[currentQueen] = row;
      placeQueen(currentQueen + 1, rowOfQueens, count);
    }
  }
}

int main()
{
  int rowOfQueens[9];
  int count = 0;
  memset(rowOfQueens, 0, sizeof(rowOfQueens));
  placeQueen(1, rowOfQueens, count);
  
  return 0;
}