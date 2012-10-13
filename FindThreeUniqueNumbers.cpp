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
 pile 3: the length of bits is less than bit
 */
void sortArray(int &l1, int &l2, int a[], int length, int bit)
{
  int cmp = 1 << bit;
  l1 = length;
  l2 = 0;
  
  for (int i = 0; i < l1;) {
    int tmp = a[i];
    
    if (a[i] < cmp) {
      a[i] = a[l1 - 1];
      a[l1 - 1] = tmp;
            
      tmp = a[l1 - 1];
      a[l1 - 1] = a[l1 + l2 - 1];
      a[l1 + l2 - 1] = a[l1 - 1];
      l1 --;
    } else if (a[i] & cmp) {
      a[i] = a[l1 - 1];
      a[l1 - 1] = tmp;
      l2 ++;
      l1 --;
    } else {
      i ++;
    }
  }
  
  for (int i = 0; i < length; i ++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

bool hasEvenNumbers(int length)
{
  return length % 2 == 0;
}

int sumOfElements(int a[], int begin, int len)
{
  int s = 0;
  
  for (int i = begin; i < begin + len; i ++) {
    s = s ^ a[i];
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

void findTwoUnique(int a[], int begin, int length, int s, int & single1, int & single2)
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
  
  for (int i = begin; i < begin + length; i ++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  
  findOneUnique(a, 0, l1, single1);
  findOneUnique(a, l1, length - l1, single2);
}

void findThreeUnique(int a[], int begin, int length, int singles[])
{  
  for (int bit = 0; bit < 32; bit ++) {
    int l1, l2;
    sortArray(l1, l2, a, length, bit);
    
    int result1 = sumOfElements(a, 0, l1);
    int result2 = sumOfElements(a, l1, l2);
    int result3 = sumOfElements(a, l1 + l2, length - l1 - l2);
    
    int count = result1 ? 1 : 0;
    count = result2 ? count + 1 : count;
    count = result3 ? count + 1 : count;
    
    if (count == 1) {
      if (result1) {
        length = l1;
      } else if (result2) {
        for (int i = 0; i < l2; i ++) {
          swap(a[i], a[l1 + i]);
        }
        length = l2;
      } else if (result3) {
        for (int i = 0; i < length - l1 - l2; i ++) {
          swap(a[i], a[l1 + l2 + i]);
        }
        length = length - l1 - l2;
      }
      
      return findThreeUnique(a, 0, length, singles);
    }
    
    
    int nextPileBegin = 0;
    int nextPileLength = 0;
    int nextPileSum = 0;
    
    if (count == 2) {
      if (!result1) {
        for (int i = 0; i < length - l1; i ++) {
          swap(a[i], a[l1 + i]);
        }
        length = length - l1;
        
        if (!hasEvenNumbers(l2)) {
          singles[0] = result2;
          nextPileBegin = l2;
          nextPileLength = length - l2;
          nextPileSum = result3;
        } else {
          singles[0] = result3;
          nextPileBegin = 0;
          nextPileLength = l2;
          nextPileSum = result2;
        }
        
      } else if (!result2) {
        for (int i = l1; i < l1 + l2; i ++) {
          swap(a[i], a[l1 + l2 + i]);
        }
        length = length - l2;
        
        if (!hasEvenNumbers(l1)) {
          singles[0] = result1;
          nextPileBegin = l1;
          nextPileLength = length - l1;
          nextPileSum = result3;
        } else {
          singles[0] = result3;
          nextPileBegin = 0;
          nextPileLength = l1;
          nextPileSum = result1;
        }
        
      } else if (!result3) {
        length = l1 + l2;
        
        if (!hasEvenNumbers(l1)) {
          singles[0] = result1;
          nextPileBegin = l1;
          nextPileLength = l2;
          nextPileSum = result2;
        } else {
          singles[0] = result2;
          nextPileBegin = 0;
          nextPileLength = l1;
          nextPileSum = result1;
        }
      }
      
      return findTwoUnique(a, nextPileBegin, nextPileLength, nextPileSum, singles[1], singles[2]);
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

