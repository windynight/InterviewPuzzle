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

int sumOfElements(int begin[], int end[])
{
  int s = 0;
  for (; begin != end; begin ++) {
    s = s ^ *begin;
  }
  
  return s;
}

void findThreeUnique(int begin[], int end[], int singles[])
{  
  
  for (int bit = 0; bit < 32; bit ++) {
    int len;
    int length = end - begin;
    sortArray(len, begin, end, bit);
    
    int s1 = sumOfElements(begin, begin + len);
    int s2 = sumOfElements(begin + len, end);
    
    if (len % 2 == 1 && (length - len) % 2 == 0) {
      if (s2 > 0) {
        singles[0] = s1;
      }
      begin += len;
    } else if (len % 2 == 0 && (length - len) % 2 == 1) {
      if (s1 > 0) {
        singles[0] = s2;
      }
      end = begin + len;
    } else if (len % 2 == 1 && (length - len) % 2 == 1) {
      singles[1] = s1;
      singles[2] = s2;
      return;
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

