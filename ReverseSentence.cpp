/*
 
 Reverse Sentence
 
 Sample Input:
 Hello World
 
 Sample Output:
 World Hello
 
 */
#include <iostream>
#include <string>

using namespace std;

void swap(char & a, char & b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void reverseString(string & s, int b, int e)
{
  while (b < e) {
    swap(s[b ++], s[e --]);
  }
}

void reverseSentence(string & s) 
{
  reverseString(s, 0, s.length() - 1);
  cout << s << endl;
  int head = 0, tail = 0;
  
  while (head < s.length()) {
    while (head < s.length() && s[head] == ' ') {
      head ++;
    }
    
    if (head >= s.length()) return;
    
    tail = head;
    while (tail < s.length() && s[tail] != ' ') {
      tail ++;
    }
    
    reverseString(s, head, tail - 1);
    head = tail + 1;
  }
}

int main()
{
  string s = "";
  while (getline(cin, s)) {
    reverseSentence(s);
    cout << s << endl;
  }
  return 0;
}