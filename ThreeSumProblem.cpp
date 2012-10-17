/*
 
 3SUM problem:
 Find three number from the given array, whose sum is the given key.
 Print all the possible result
 
 Solution:
 Time complexity is O(n*n), extra space complexity is O(n)
 1. hash all the value of each num in the array
 2. for each node a[i], check if there are some pair of numbers whose sum is key - a[i]
 
 Sample Input:
 5 3
 -1 -2 1 2 3
 
 Sample Output:
 -1 1 2
 -2 2 3
 
 */

#include <iostream>
#include <map>

using namespace std;

void print3Sum(int a[], int n, int key, int &count)
{
  map<int, int> m;
  
  for (int i = 1; i <= n; i ++) {
    m[a[i]] = i;
  }
  
  for (int i = 1; i <= n; i ++) {
    int sum = key - a[i];
    
    for (int j = i + 1; j < n; j ++) {
      int tmpSum = sum - a[j];
      if (m[tmpSum] && m[tmpSum] != i && m[tmpSum] != j) {
        cout << ++ count << ": " << a[i] << ' ' << a[j] << ' ' << tmpSum << endl;
      }
    }
  }
}

int main()
{
  int n, key, count;
  
  while (cin >> n >> key && n > 0) {
    int a[n + 1];
    
    for (int i = 1; i <= n; i ++) {
      cin >> a[i];
    }
    print3Sum(a, n, key, count);
  }
  
  return 0;
}