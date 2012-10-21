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
 
 
 对于每一段从b到e的子序列arr，取中间下标mid = (b + e) / 2
 都可以将这个数组分成三段从小到大排好序的子序列：A,B,C
 如果target == arr[mid]，mid为所求
 如果，当arr[b] > arr[mid]时：mid左边的数组为AB，右边为C，其中A>C>B (C的所有元素都大于B的元素，而小于A的元素。)
      比如：15 16 17 18 1 2 3 4 5 6 7 8
 如果，当arr[b] < arr[mid]时：mid左边为数组A，右边为B和C，其中A>B>C  (B的所有元素都大于C的元素，而小于A的元素。)
      比如：15 16 17 18 19 20 1 2 3
 
 这样，target != arr[mid]时，关键在于找到target属于ABC中哪一段来确定下一次查找的范围。
 如果，当arr[b] > arr[mid]时：mid左边的数组为AB，右边为C，其中A>C>B
 1. 首先，当前仅当target < arr[mid]时，能唯一确定target肯定在数组B内，那么下次的查找范围是：[b, mid - 1]，（相反arr[mid] < target，无法确定，因为target可以在A中，也可以在C中）
 2. 如果target > arr[mid](不可能等于target，那样会在之前return mid)时，只需要判断target是在A还是在C中。由于A>C，只需要A的第一个元素不大于target，那么A的所有元素都不大于target并且C的所有元素都小于target。因此得出，
    a) target时 <= arr[b]，下一次查找范围为[b, mid - 1];
    b) target > arr[b]时，下一次查找范围为[mid + 1, e];
 
 同理可得，当arr[b] < arr[mid]时，mid左边为数组A，右边为B和C，其中A>B>C
 1. target > arr[mid]时，target在B中，下一次查找[mid + 1, e]
 2. target < arr[mid]时候，
    a) target >= arr[b]时，下次查找[b, mid - 1];
    b) target < arr[b]时，下次查找[mid + 1, e];
 
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
    
    //In situation a[b] < a[mid]: 15 16 17 18 19 20 1 2 3
    if (a[b] < a[mid]) {
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