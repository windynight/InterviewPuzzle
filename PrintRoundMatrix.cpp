
/*
 
 Print round n * n Matrix with given n:
 
 Sample Input:
 6
 
 Sample Output:
 1	2	3	4	5	6
 20	21	22	23	24	7
 19	32	33	34	25	8
 18	31	36	35	26	9
 17	30	29	28	27	10
 16	15	14	13	12	11
 
 Hint: 
 There are three ways to solve the problem
 1. Modeling path for the count from 1 through n*n, set the count value to the point it arrives each time
 2. Given index i and j, calculate the value of matrix[i][j]
 3. Given a number from 1 through n * n, calculate the position i and j for number in matrix[n][n]
 
 */

#include <iostream>
#include <string>

using namespace std;


void printMatrix(int ** matrix, int n)
{
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cout << '\t' << matrix[i][j];
    }
    cout << endl;
  }
  
  cout << endl;
}

void printRoundMatrix1(int n)
{
  int **matrix = new int * [n];
  for (int i = 0; i < n; i ++) {
    matrix[i] = new int[n];
  }
  
  int count = 0;
  for (int i = 0; i <= n / 2; i ++) {
    for (int j = i; j < n - i; j ++) {
      matrix[i][j] = ++count;
    }
    
    for (int j = i + 1; j < n - i; j ++) {
      matrix[j][n - i - 1] = ++count;
    }
    
    for (int j = n - i - 2; j >= i; j --) {
      matrix[n - i - 1][j] = ++ count;
    }
    
    for (int j = n - i - 2; j > i; j --) {
      matrix[j][i] = ++ count;
    }
  }
  
  printMatrix(matrix, n);
}

int value(int i, int j, int n)
{
  int x = n;
  if (i >= n / 2) {
    x = min(x, n - i - 1);
  } else {
    x = min(x, i);
  }
  
  if (j >= n / 2) {
    x = min(x, n - j - 1);
  } else {
    x = min(x, j);
  }
  
  int num = (n - x) * x * 4;
  
  if (i == x) {
    return num + j - x + 1;
  } 
  
  if (j == n - x - 1) {
    return num + n + i - 3 * x;
  }
  
  if (i == n - x - 1 ) {
    return num + 3 * n - 5 * x - j - 2;
  }
  
  if (j == x) {
    return num + 4 * n - 7 * x - i - 3;
  }
 
  return -1;
}

void printRoundMatrix2(int n)
{
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cout << '\t' << value(i, j, n) << ' ';
    }
    cout << endl;
  }
  
  cout << endl;
}

void cal(int & i, int & j, int num, int n)
{
  int x = 0;
  while (num > 1) {
    int tmp = num - 4 * (n - 2 * x - 1);
    if (tmp > 0) {
      x ++;
      num = tmp;
    } else {
      break;
    }
  }
  
  n -= 2 * x;
  if (num <= n) {
    i = x;
    j = x + num - 1;
    return;
  }
  
  if (num <= 2 * n - 1) {
    j = x + n - 1;
    i = num - n + x;
    return;
  }
  
  if (num <= 3 * n - 2) {
    i = x + n - 1;
    j = 3 * n - 2 - num + x;
    return;
  }
  
  j = x;
  i = 4 * n - 4 - num + x + 1;
}

void printRoundMatrix3(int n)
{
  int **matrix = new int * [n];
  for (int i = 0; i < n; i ++) {
    matrix[i] = new int[n];
  }
  
  for (int num = 1; num <= n * n; num ++) {
    int i = 0, j = 0;
    cal(i, j, num, n);
    if (i >= 0 && i < n && j >= 0 && j < n) {
      matrix[i][j] = num;
    }
  }
  
  printMatrix(matrix, n);
}

int main()
{
  int n;
  while (cin >> n && n) {
    printRoundMatrix1(n);
    printRoundMatrix2(n);
    printRoundMatrix3(n);
  }
  return 0;
}


