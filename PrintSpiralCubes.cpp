/*
 
 Give an n,
 Print Cubes like:
 
 1 - 2   9 - 10
     |   |   |
 4 - 3   8   11
 |       |   |
 5 - 6 - 7   12
             |
 16- 15- 14- 13
 
 
 */

#include <iostream>

using namespace std;

void printCubes(int n)
{
  int num[n][n];
  int count = 0;
  
  for (int i = 1; i <= n; i ++) {
    if (i % 2 == 0) {
      for (int j = 0; j < i; j ++) {
        num[j][i - 1] = ++count;
      }
      for (int j = i - 2; j >= 0; j --) {
        num[i - 1][j] = ++count;
      }
    } else {
      for (int j = 0; j < i; j ++) {
        num[i - 1][j] = ++count;
      }
      for (int j = i - 2; j >= 0; j --) {
        num[j][i - 1] = ++count;
      }
    }
  }
  
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cout << num[i][j] << '\t';
    }
    cout << endl;
  }
}

int main()
{
  int n;
  while (cin >> n && n) {
    printCubes(n);
  }
    
  return 0;
}

