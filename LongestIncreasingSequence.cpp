/*
 
  POJ 2533: http://poj.org/problem?id=2533
  the longest increasing subsequences (LIS)
 */            

#include <iostream>

using namespace std;


int main()
{
  int n;

  cin >> n;
    
  int q[1010];
  q[0] = -1;
  int top = 0;
  int tmp;
  
  for (int i = 0; i < n; i ++) {
    cin >> tmp;
    
    if (tmp > q[top]) {
      q[++top] = tmp;
    } else {
      int l = 1, r = top;
      
      while (l <= r) {
        int mid = (l + r) / 2;
        
        if (tmp < q[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      
      q[l] = tmp;
    }
  }
  
  cout << top << endl;
  
  return 0;
}