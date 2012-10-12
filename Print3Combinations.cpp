/*
 
 give an array of n elements and an int sum,
 print all combinations of three elements from the array,
 whose sumup is key.
 
Input:
 [5, 3, 2, 8, 9, 7, 0]  10
 
Output:
 
 5 3 2
 2 8 0
 3 7 0
 
 */

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void print3Combinations(int arr [], int size, int sum)
{
  // sort before searching to optimize the algorithm
  sort(arr, arr + size);
  
  if (sum < arr[0]) {
    cout << "NONE" << endl;
    return;
  }
  
  for (int i = 0; i < size; i ++) {
    if (arr[i] > sum) {
      break;
    }
    
    for (int j = i + 1; j < size; j ++) {
      int sumOfTwo = arr[i] + arr[j];
      if (sumOfTwo > sum) {
        break;
      }
      
      for (int k = j + 1; k < size; k ++) {
        int sumOfThree = sumOfTwo + arr[k];
        if (sumOfThree > sum) {
          break;
        } else if (sumOfThree == sum) {
          cout << i << ' ' << j << ' ' << k << endl;
        }
      }
    }
  }
  
}

int main()
{
  int a[100];
  int n = 100;
  for (int i = 0; i < n; i ++) {
    a[i] = i;
  }
  
  int sum = 0;
  cin >> sum;
  
  while (sum) {
    print3Combinations(a, n, sum);
    cin >> sum;
  }
  
  return 0;
}