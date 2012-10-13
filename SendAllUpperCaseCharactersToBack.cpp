
/*
 
 Send all upper case characters to back, something like a bubble sort
 
 */

#include <iostream>
#include <string>

using namespace std;

bool isUpperCase(char a)
{
  return a < 97;
}

void sendAllUpperCaseCharactersToBack(string & a)
{
  int last = a.length() - 1;
    
  for (int i = last; i >= 0; i --) {
    if (i >= 0 && isUpperCase(a[i]) ) {
      if (i != last) {
        swap(a[i], a[last]);
      }
      last --;
    }
  }
}

void sortString(string &a)
{
  string up = "";
  string low = "";
  
  for (int i = 0; i < a.length(); i ++) {
    if (isUpperCase(a[i])) {
      up += a[i];
    } else {
      low += a[i];
    }
  }
  
  a = low + up;
}

int main()
{
  string a = "aasasdfaSAsfvsaDFASASDasfsaAS";
  
  while (1) {
    sortString(a);
    cout << a << endl;
    cin >> a;
  }
  return 0;
}


