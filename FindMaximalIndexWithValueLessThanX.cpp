/*
 
 Give an arr[n] sorted ascending, and number x
 Find the number who is less than x but whose index is maximal
 If not found, print "None"
 
 Sample Input:
 10 7
 1 2 3 4 5 6 7 8 9 10
 
 Sample Output:
 index 5 : 6
 
 Hint:
 Give a algorithm with O(logn) time complexity and O(1) extra space complexity.
 
 Test Case 0:
 
 1 0
 8
 1 8
 3
 2 5
 4 5
 2 4
 4 5
 3 7
 6 7 8
 3 7
 6 8 9
 10 7
 1 2 3 4 5 6 7 8 9 10
 9 7
 1 2 3 4 5 6 8 9 10
 10 11
 1 2 3 4 5 6 7 8 9 10
 10 0
 1 2 3 4 5 6 7 8 9 10
 
 Output:
 None
 Index 0 : 3
 Index 0 : 4
 None
 Index 0 : 6
 Index 0 : 6
 Index 5 : 6
 Index 5 : 6
 Index 9 : 10
 None
 */

#include <iostream>

using namespace std;

void findMaximalIndexLessThanX(int a[], int n, int x)
{
  int l = 0, r = n - 1, mid = 0;
  
  //Binary Search, the loop ends with l > r, a[l] >= x
  while (l <= r) {
    mid = (l + r) >> 1;
    
    if (a[mid] >= x) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
    
  if (l == 0) {
    cout << "None" << endl;
  } else {
    cout << "Index " << l - 1 << " : " << a[l - 1] << endl;
  }
}

int main()
{
  int n, x;
  while (cin >> n >> x) {
    int a[n];
    for (int i = 0; i < n; i ++) {
      cin >> a[i];
    }
    
    findMaximalIndexLessThanX(a, n, x);
  }
  
  return 0;
}