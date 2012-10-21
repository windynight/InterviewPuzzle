/*
 
 Given a sorted array of n integers that has been rotated an unknown number of times,giveanO(logn)algorithmthatfindsanelementinthearray Youmayassume that the array was originally sorted in increasing order
 EXAMPLE:
 Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 Output: 8 (the index of 5 in the array)
 
 Sample Input: 
 12 5
 15 16 19 20 25 1 3 4 5 7 10 14
 12 5
 15 16 19 20 25 1 3 4 5 7 10 14
 Sample Output: 
 8
 
 */

#include <iostream>

using namespace std;

int binarySearch(int a[], int b, int e, int target)
{
  while (b <= e) {
    int mid = (b + e) / 2;
    if (target == a[mid]) {
      return mid;
    }
    
    //In situation a[b] <= a[mid]: 15 16 17 18 19 20 1 2 3
    if (a[b] <= a[mid]) {
      if (target > a[mid]) { //if target > a[mid], could ensure target in [mid + 1, e]
        b = mid + 1;
      } else if (target >= a[b]) {
        e = mid - 1;
      } else {
        b = mid + 1;
      }
    } else {    //In situation a[b] > a[mid]: 15 16 17 18 1 2 3 4 5 6 7 8
      if (target < a[mid]) {   //if target < a[mid], could ensure target in [b, mid - 1]
        e = mid - 1;
      } else if (target <= a[e]) {
        b = mid + 1;
      } else {
        e = mid - 1;
      }
    }
  }
  
  return -1;
}

int main()
{
  int n, target;
  while (cin >> n >> target && n) {
    int a[n];
    for (int i = 0; i < n; i ++) {
      cin >> a[i];
    }
    
    cout << binarySearch(a, 0, n - 1, target) << endl;
  }
  
  return 0;
}