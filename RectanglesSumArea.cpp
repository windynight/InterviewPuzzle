/* 
 http://poj.org/problem?id=1151
 
 Hint: Discretization  http://en.wikipedia.org/wiki/Discretization
 */ 

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define N 100

typedef struct PointT {
  double data;
  int index;
  PointT () {}
  PointT (int d, int i) : data(d), index(i) {};
}Point;

int cmp(const Point a, const Point b) 
{   
  return a.data <= b.data;
}

void solve(int n, int kase) 
{
  double ans = 0;
  Point px[2 * N], py[2 * N];
 
  for (int i = 0; i < n; i ++) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) {
      swap(a, c);
    }
    if (b > d) {
      swap(b, d);
    }
    
    px[2 * i] = Point(a, 2 * i);
    px[2 * i + 1] = Point(c, 2 * i + 1);
    py[2 * i] = Point(b, 2 * i);
    py[2 * i + 1] = Point(d, 2 * i + 1);
  }
  
  sort(px, px + 2 * n, cmp);
  sort(py, py + 2 * n, cmp);
  
  int hashx[2 * N], hashy[2 * N];
  memset(hashx, 0, sizeof(hashx));
  memset(hashy, 0, sizeof(hashy));
  
  for (int i = 0; i < 2 * n; i ++) {
    hashx[px[i].index] = i;
    hashy[py[i].index] = i;
  }
  
  bool mp[2 * N][2 * N];
  memset(mp, 0, sizeof(mp));
  
  for (int i = 0; i < n; i ++) {
    for (int x = hashx[2 * i]; x < hashx[2 * i + 1]; x ++) {
      for (int y = hashy[2 * i]; y < hashy[2 * i + 1]; y ++) {
        mp[x][y] = true;
      }
    }
  }
  
  ans = 0.0f;
  
  for (int i = 0; i < 2 * n - 1; i ++) {
    for (int j = 0; j < 2 * n - 1; j ++) {
      if (mp[i][j]) {
        ans += (px[i + 1].data - px[i].data) * (py[j + 1].data - py[j].data);
      }
    }
  }
  
  cout << "Test case #" << kase << endl;
  cout << "Total explored area: " << fixed << setprecision(2) << ans << endl << endl;
}

int main() 
{
  int kase = 0, n; 
  while(cin >> n && n) { 
    solve(n, ++ kase); 
  } 
  return 0;
}