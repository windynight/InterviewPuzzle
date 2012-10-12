/*
 
 Google interview puzzle:
 
 Give a string x = "abcbscsc"
 Find the largest subString length making the different kind number of characters is exactly 3
 
 acbdabcdabcddd
 5
 abcd
 3
 abcdddddd
 8
 abcdababababa
 10
 abcbscsc
 7
 
 */

#include <iostream>
#include <string>

using namespace std;

void findLongestSubString(int n, string x)
{
  int flag[27];
  memset(flag, 0, sizeof(flag));
  
  int head = 0;
  int tail = 1;
  
  flag[x[head] - 'a'] = 1;
  
  int count = 1;
  int maxLength = 1;
  string subString = x.substr(0, 1);
  
  while (tail < x.length()) {
    if (head == tail) {
      tail ++;
      continue;
    }
    
    if (count > n) {
      flag[x[head] - 'a'] --;
      if (flag[x[head] - 'a'] == 0) {
        count --;
      }
      head ++;
      
      continue;
    }    

    if (flag[x[tail] - 'a'] == 0) {
      count ++;
    }
    
    flag[x[tail ++] - 'a'] ++;
    
    if (count <= n) {
      if (maxLength < tail - head) {
        maxLength = maxLength > tail - head ? maxLength : tail - head;
        subString = x.substr(head, maxLength);
      }
    }
  }
  
  cout << maxLength << ' ' << subString << endl;
}

int main()
{
  string x = "aabbbbbsssscddsssaaaaffxxx";
  
  int n = 3;
  
  while (cin >> x) {
    findLongestSubString(n, x);
  }
  
  return 0;
}