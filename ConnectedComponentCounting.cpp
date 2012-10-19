/*
 Count the Connected component: (graph theory)
 
 http://en.wikipedia.org/wiki/Connected_component_%28graph_theory%29
 
 Sample Input:
 5 5   (5 rows, 5 columns)
 1 1 0 0 0
 0 1 0 0 1
 1 0 0 1 1
 0 0 0 0 0
 1 0 1 0 1
 
 Sample Output:
 6
 
 */

#include<algorithm>
#include<iostream>
using namespace std;

#define COL 100
#define ROW 100



void dfs(int ** matrix, int r, int c, bool ** visited, int n, int m)
{
  if (r < 0 || r >= n || c < 0 || c >= m || matrix[r][c] == 0 || visited[r][c]) {
    return;
  }
  
  visited[r][c] = true;
  
  static int x[4] = {1, -1, 0, 0};
  static int y[4] = {0, 0, 1, -1};
  
  for (int i = 0; i < 4; i ++) {
    int idx_x = r + x[i];
    int idx_y = c + y[i];
  
    dfs(matrix, idx_x, idx_y, visited, n, m);
  }
}

int main()
{
  int n, m;
  
  while (cin >> n >> m && n > 0 && n < ROW && m > 0 && m < COL) {
    int ** matrix = new int * [n];
    bool ** visited = new bool * [n];
    
    for (int i = 0; i < n; i ++) {
      matrix[i] = new int[m];
      visited[i] = new bool[m];
    }
    
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        cin >> matrix[i][j];
      }
    }
    
    int count = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (!visited[i][j] && matrix[i][j] == 1) {
          dfs(matrix, i, j, visited, n, m);
          count ++;
        } 
      }
    }
    
    cout << count << endl;

    for (int i = 0; i < n; i ++) {
      delete matrix[i];
      delete visited[i];
    }
    
    delete matrix;
    delete visited;
  }
  
    
  return 0;
}

