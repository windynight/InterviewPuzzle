/*
 
 Given an array with 2n + 3 integer elements, in which there are n numbers appeared twice,
 and 3 numbers appeared just once.
 
 Using O(n) algorithm to find out the three elements.
 
 Hints:
 Using bit algorithm.
 
 */

#include <iostream>

using namespace std;


/*
 sort the array into three piles,
 pile 1: the bit is 0, len l1
 pile 2: the bit is 1, len l2
 */
void sortArray(int &l1, int a[], int begin, int length, int bit)
{
  int cmp = 1 << bit;
  l1 = length;
  
  for (int i = begin; i < begin + l1; ) {
    int tmp = a[i];
    
    if (a[i] & cmp) {
      a[i] = a[l1 - 1];
      a[l1 - 1] = tmp;
      l1 --;
    } else {
      i ++;
    }
  }
  
}

bool hasEvenNumbers(int length)
{
  return length % 2 == 0;
}

int sumOfElements(int begin[], int end[])
{
  int s = 0;
  for (; begin != end; begin ++) {
    s = s ^ *begin;
  }
  
  return s;
}

void findOneUnique(int a[], int begin, int length, int &result)
{  
  result = 0;
  for (int i = begin; i < begin + length; i ++) {
    result = result ^ a[i];
  }
}

void findTwoUnique(int a[], int begin, int length, int s, int singles [])
{
  int cmp = 0;
  while (s) {
    if (s & 1) {
      break;
    }
    
    cmp ++;
    s >>= 1;
  }
  
  cmp = 1 << cmp;
  
  int l1 = length;
  for (int i = begin; i < l1; ) {
    if (a[i] & cmp) {
      swap(a[i], a[l1 - 1]);
      l1 --;
    } else {
      i ++;
    }
  }
  
  findOneUnique(a, 0, l1, singles[0]);
  findOneUnique(a, l1, length - l1, singles[1]);
}

void findThreeUnique(int a[], int begin, int length, int singles[])
{  
  for (int bit = 0; bit < 32; bit ++) {
    int l1;
    sortArray(l1, a, begin, length, bit);
    
    int result1 = sumOfElements(a, a + l1);
    int result2 = sumOfElements(a + l1, a + length - l1);
    
    int count = result1 ? 1 : 0;
    count = result2 ? count + 1 : count;
    
    if (count == 1) {
      if (result1) {
        return findThreeUnique(a, 0, l1, singles);
      } else if (result2) {
        return findThreeUnique(a, l1, length - l1, singles);
      }
      
    } else {
      if (!hasEvenNumbers(l1)) {
        singles[0] = result1;
        return findTwoUnique(a, l1, length - l1, result2, singles + 1);
      } else {
        singles[0] = result2;
        return findTwoUnique(a, 0, l1, result1, singles + 1);
      }
      
    }
    
  }
}

int main()
{
  int a[9] = {10, 9, 8, 7, 6, 5, 5, 6, 7};
  
  int singles[3];
  findThreeUnique(a, 0, 9, singles);
  
  for (int i = 0; i < 3; i ++) {
    cout << singles[i] << ' ';
  }
  cout << endl;
    
  return 0;
}

