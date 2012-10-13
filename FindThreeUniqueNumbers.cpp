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
void sortArray(int &len, int begin[], int end[], int bit)
{
  int cmp = 1 << bit;
  len = end - begin;
  
  for (int i = 0; i < len; ) {
    int tmp = *(begin + i);
    
    if (*(begin + i) & cmp) {
      *(begin + i) = *(begin + len - 1);
      *(begin + len - 1) = tmp;
      len --;
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
  int len = end - begin;

  while (!(s & 1)) {
    cmp ++;
    s >>= 1;
  }
  
  cmp = 1 << cmp;
  
  for (int i = 0; i < len; ) {
    if (*(begin + i)  & cmp) {
      swap(*(begin + i), *(begin + len - 1));
      len --;
    } else {
      i ++;
    }
  }
  
  findOneUnique(begin, begin + len, singles[0]);
  findOneUnique(begin + len, end, singles[1]);
}

void findThreeUnique(int begin[], int end[], int singles[])
{  
  for (int bit = 0; bit < 32; bit ++) {
    int len;
    sortArray(len, begin, end, bit);
    
    int s1 = sumOfElements(begin, begin + len);
    int s2 = sumOfElements(begin + len, end);
    
    int count = s1 ? 1 : 0;
    count = s2 ? count + 1 : count;
    
    if (count == 1) {
      if (s1) {
        return findThreeUnique(begin, begin + len, singles);
      } else if (s2) {
        return findThreeUnique(begin, end - len, singles);
      }
      
    } else {
      if (!hasEvenNumbers(len)) {
        singles[0] = s1;
        return findTwoUnique(begin + len, end, s2, singles + 1);
      } else {
        singles[0] = s2;
        return findTwoUnique(begin, begin + len, s1, singles + 1);
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

