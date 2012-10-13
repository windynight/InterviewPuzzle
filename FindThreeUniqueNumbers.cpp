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
void sortArray(int &l1, int begin[], int end[], int bit)
{
  int cmp = 1 << bit;
  l1 = end - begin;
  
  for (int i = 0; i < l1; ) {
    int tmp = *(begin + i);
    
    if (*(begin + i) & cmp) {
      *(begin + i) = *(begin + l1 - 1);
      *(begin + l1 - 1) = tmp;
      l1 --;
    } else {
      i ++;
    }
  }
  
  while (begin != end) {
    cout << *begin << ' ';
    begin ++;
  }
  
  cout << endl;
  
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

void findOneUnique(int begin[], int end[], int &result)
{  
  result = 0;
  
  while (begin != end) {
    result = result ^ *begin;
    begin ++;
  }
  
}

void findTwoUnique(int begin[], int end[], int s, int singles [])
{
  int cmp = 0;
  int l1 = end - begin;

  while (!(s & 1)) {
    cmp ++;
    s >>= 1;
  }
  
  cmp = 1 << cmp;
  
  for (int i = 0; i < l1; ) {
    if (*(begin + i)  & cmp) {
      swap(*(begin + i), *(begin + l1 - 1));
      l1 --;
    } else {
      i ++;
    }
  }
  
  findOneUnique(begin, begin + l1, singles[0]);
  findOneUnique(begin + l1, end, singles[1]);
}

void findThreeUnique(int begin[], int end[], int singles[])
{  
  for (int bit = 0; bit < 32; bit ++) {
    int l1;
    sortArray(l1, begin, end, bit);
    
    int result1 = sumOfElements(begin, begin + l1);
    int result2 = sumOfElements(begin + l1, end);
    
    int count = result1 ? 1 : 0;
    count = result2 ? count + 1 : count;
    
    if (count == 1) {
      if (result1) {
        return findThreeUnique(begin, begin + l1, singles);
      } else if (result2) {
        return findThreeUnique(begin, end - l1, singles);
      }
      
    } else {
      if (!hasEvenNumbers(l1)) {
        singles[0] = result1;
        return findTwoUnique(begin + l1, end, result2, singles + 1);
      } else {
        singles[0] = result2;
        return findTwoUnique(begin, begin + l1, result1, singles + 1);
      }
      
    }
    
  }
}

int main()
{
  int a[9] = {10, 9, 8, 7, 6, 5, 5, 6, 7};
  
  int singles[3];
  findThreeUnique(a, a + 9, singles);
  
  for (int i = 0; i < 3; i ++) {
    cout << singles[i] << ' ';
  }
  cout << endl;
    
  return 0;
}

