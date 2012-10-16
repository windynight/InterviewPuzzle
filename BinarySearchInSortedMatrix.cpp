
/*
 
 Search a key in the n*n sorted Matrix, whose elements are sorted in each row and each column.
 
 Input:
 First Line: n, key
 Following n lines, the matrix.
 
 Sample Input:
 
 7 65
 1 2 3 4 51 62 78
 2 3 4 5 6 79 81
 3 4 5 6 7 82 94
 4 5 6 7 81 91 100
 5 6 7 79 95 101 110
 6 7 65 98 100 112 120
 7 8 91 101 112 121 131
 
 
 Another Answer:
 Assumptions:
 » Rows are sorted left to right in ascending order Columns are sorted top to bottom in ascending order
 » Matrix is of size MxN
 The start point (0, N-1), each compare can decide the point to move down (row - 1) or move left (col - 1).
 */

#include <iostream>

using namespace std;

bool binarySearchTheMatrix(int ** arr, int l, int r, int t, int b, int key)
{
  //Do Linear Binary Search Vertically
  if (l == r) {
    while (t <= b) {
      int mid = (t + b) / 2;
      if (key == arr[mid][l]) {
        return true;
      } else if (key < arr[mid][l]) {
        b = mid - 1;
      } else {
        t = mid + 1;
      }
    }
    return false;
  }
  
  //Do Linear Binary Search Horinzontally
  if (t == b) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (key == arr[t][mid]) {
        return true;
      } else if (key < arr[t][mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return false;
  }
  
  //Search Matrix
  if (l < r) {
    int mid1 = (l + r) / 2;
    int mid2 = (t + b) / 2;
    if (key < arr[mid2][mid1]) {
      return binarySearchTheMatrix(arr, l, mid1, t, mid2 - 1, key);
    } else if (key == arr[mid2][mid1]) {
      return true;
    } else {
      return binarySearchTheMatrix(arr, mid1, mid1, t, mid2 - 1, key)
      || binarySearchTheMatrix(arr, mid1 + 1, r, mid2, mid2, key)
      || binarySearchTheMatrix(arr, mid1, mid1, mid2 + 1, b, key)
      
      || binarySearchTheMatrix(arr, mid1 + 1, r, t, mid2 - 1, key)
      || binarySearchTheMatrix(arr, mid1 + 1, r, mid2 + 1, b, key)
      || binarySearchTheMatrix(arr, l, mid1 - 1, mid2 + 1, b, key);
    }
  }
  
  return false;
}

/*

 This algorithm works by elimination Every move to the left (--col) eliminates all the elements below the current cell in that column Likewise, every move down eliminates all the elements to the left of the cell in that row
 
 The start point (0, N-1), each compare can decide the point to move down (row - 1) or move left (col - 1)
 
 */
bool findElem(int ** mat, int elem, int M, int N)
{ 
  int row = 0;
  int col = N-1;
  while (row < M && col >= 0) {
    if (mat[row][col] == elem) {
      return true;
    } else if (mat[row][col] > elem) {
      col--;
    } else {
      row++;
    }
  }
  return false; 
}

int main()
{
  int n, m;
  cin >> n >> m;
  int **arr = new int * [n];
  
  for (int i = 0; i < n; i ++) {
    arr[i] = new int[n];
    for (int j = 0; j < n; j ++) {
      cin >> arr[i][j];
    }
  }
  
  cout << (binarySearchTheMatrix(arr, 0, n - 1, 0, n - 1, m) ? "YES" : "NO") << endl;
  cout << (findElem(arr, m, n, n) ? "YES" : "NO") << endl;

  return 0;
}


