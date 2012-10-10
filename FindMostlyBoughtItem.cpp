/*
 •	Question:
 We have an array representing customer’s shopping records.
 For example, it’s an array like this:
 custA, item1,
 custB, item1,
 custA, item2,
 custB, item3,
 custC, item1,
 custC, item3,
 custD, item2,
 This array indicates that customer A bought item 1, customer B bought item 1, customer A bought item 2, customer B bought item 3, etc..
 For a given item X and shopping records array, write code to find out what else (item Y) was bought mostly by the customers who bought item X.
 For example, in above example, if X is item 1 then Y should be item 3.
 Rules:
 •	One customer can only buy one item once.
 •	The mostly brought item should not be item X.
 •	If no customer brought item X, then return “None”
 •	If all the customers who brought item X only brought item X, then return “None”
 •	The first line of input is the item X. The second line of input is the shopping record array, this shopping record array is split by space.
 •	If there are many other mostly brought items which have equally brought times, then return any one of those items.
 Examples:
 Input1:
 item1
 custA item1 custB item1 custA item2 custB item3 custC item1 custC item3 custD item2
 Output1:
 item3
 Input2:
 item2
 custA item1 custB item1 custC item1 custA item2 custB item3 custA item3
 Output2:
 item1 
 (The output2 can be item3 too)
 */


 
 /* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

char* findMostlyBroughtItem(char* shippingRecordArray[], int length, char* givenItem);

inline bool isSpace(char x){
  return x == ' ' || x == '\r' || x == '\n' || x == '\f' || x == '\b' || x == '\t';
}

char * rightTrim(char *str){
  int len = strlen(str);
  while(--len>=0){
    if(isSpace(str[len])){
      str[len] = '\0';
    }else{
      break;
    }
  }
  return str;
}

char * getInputLine(char *buffer, int length){
  if(fgets(buffer,length, stdin)==NULL){
    return NULL;
  }
  rightTrim(buffer);
  if(strlen(buffer)<=0){
    return NULL;
  }
  return buffer;
}

int splitAndConvert(char* strings,char* array[]){
  char*tokenPtr = strtok(strings," ");
  int i=0;
  while(tokenPtr!=NULL){
    array[i] = tokenPtr;
    i++;
    tokenPtr=strtok(NULL," ");
  }
  return i;
}

int main()
{
  char givenItem[1000] = {0} ;
  while(getInputLine(givenItem, 1000)){
    char line[1000];
    getInputLine(line, 1000);
    
    char* shoppingRecordArray[1000] = {0};
		
    int length = splitAndConvert(line,shoppingRecordArray);
    if(length==0){
      break;
    }
    
    char * item = findMostlyBroughtItem(shoppingRecordArray, length, givenItem);
    cout<<item<<endl;
  }
  return 0; 
}

//your code is here
bool compare (string str, char *cStr) 
{
  int length = strlen(cStr);
  if (length != str.length()) {
    return false;
  }
  
  for (int i = 0; i < length; i ++) {
    if (str[i] != cStr[i]) {
      return false;
    }
  }
  
  return true;
}

char* findMostlyBroughtItem(char* shippingRecordArray[], int length, char* givenItem)
{
//item1
//custA item1 custB item1 custA item2 custB item3 custC item1 custC item3 custD item2
  
  char* stack[length];
  int count = 0;
  
  for (int i = 0; i < length; i += 2) {
    if (strcmp(shippingRecordArray[i+1], givenItem) == 0) {
      stack[count ++] = shippingRecordArray[i];
    }
  }
  
  map<string, int> myMap;
  
  
  for (int i = 0; i < length; i += 2) {
    for (int j = 0; j < count; j ++) {
      if (strcmp(stack[j], shippingRecordArray[i]) == 0) {
        string key= shippingRecordArray[i + 1];
        myMap[key] ++;
        break;
      }
    }
  }
  
  string result;
  int maxNumber = 0;
  
  std::map<string,int>::iterator iter = myMap.begin();
  std::map<string,int>::iterator endIter = myMap.end();
  for(; iter != endIter; ++iter)
  {
    string key = iter->first;
    int value = iter->second;
    
    if (!compare(key, givenItem)) {
      if (maxNumber < value) {
        maxNumber = value;
        result = key;
      } 
    }
  }
  
  myMap.clear();
  myMap.empty();
  
  if (maxNumber == 0) {
    result = "None";
  }
  
  char* cResult = new char[result.length()+1];
  strcpy(cResult, result.c_str());
  return cResult;
}


