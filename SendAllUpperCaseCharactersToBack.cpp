
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

int main()
{
  string a = "aasasdfaSAsfvsaDFASASDasfsaAS";
  
  while (1) {
    sendAllUpperCaseCharactersToBack(a);
    cout << a << endl;
    cin >> a;
  }
  return 0;
}


