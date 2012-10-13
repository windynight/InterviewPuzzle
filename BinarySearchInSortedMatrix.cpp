
/*
 
 Search a key in the n*n sorted Matrix, whose elements are sorted in each row and each column.
 
 Input:
 First Line: n, key
 Following n lines, the matrix.
 
 Sample Input:
 
 7 8 
 1 2 3 4 5 6 7
 2 3 4 5 6 7 80
 3 4 5 6 7 80 9
 4 5 6 7 80 9 10
 5 6 7 80 9 10 11
 6 7 80 9 10 11 12
 7 8 9 10 11 12 13
 
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
  
  return 0;
}


