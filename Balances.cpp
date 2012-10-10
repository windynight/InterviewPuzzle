

//
//  Blances.cpp
//  Facebook Interview Puzzle
//
//  Created by Charlene Jiang on 10/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


struct Balance 
{
  int leftWeight;
  int rightWeight;
  vector<int> leftBalances;
  vector<int> rightBalances;
  int result;
  int sum;
  bool finished;
};

Balance balance[110];
int n;

int calc(int index)
{
  if (index < 0 || index >= n)
  {
    return 0;
  }
  
  if (balance[index].finished)
  {
    return balance[index].sum;
  }
  
  int leftSum = balance[index].leftWeight;
  for (int i = 0; i < balance[index].leftBalances.size(); i ++)
  {
    leftSum += calc(balance[index].leftBalances[i]);
  }
  
  
  int rightSum = balance[index].rightWeight;
  for (int i = 0; i < balance[index].rightBalances.size(); i ++)
  {
    rightSum += calc(balance[index].rightBalances[i]);
  }
  
  balance[index].result = leftSum - rightSum;
  balance[index].finished = true;
  
  balance[index].sum = leftSum >= rightSum ? 2 * leftSum : 2 * rightSum;
  balance[index].sum += 10;
  
//  cout << index << "------" << balance[index].sum << endl;
  return balance[index].sum;
}



int main()
{
  
  cin >> n;
  
  string s;
  istringstream instream;
  int num = 0;
  
  getchar();
  
  for (int i = 0; i < n; i ++)
  {
    //left
    getline(cin, s);
    
    instream.clear();
    instream.str(s);
    instream >> balance[i].leftWeight;
    
    while (instream >> num)
    {
      balance[i].leftBalances.push_back(num);
    }
    
    //right
    getline(cin, s);
    
    instream.clear();
    instream.str(s);
    instream >> balance[i].rightWeight;
    
    while (instream >> num)
    {
      balance[i].rightBalances.push_back(num);
    }
   
    balance[i].result = 0;
    balance[i].finished = false;
    balance[i].sum = 0;
  }
  
  for (int i = 0; i < n; i ++)
  {
    calc(i);
  }
  
  for (int i = 0; i < n; i ++)
  {
    cout << i << ": ";
    
    if (balance[i].result < 0)
    {
      cout << balance[i].result << " 0" << endl;
    }
    else 
    {
      cout << "0 " << -balance[i].result << endl;
    }
  }
  
//  for (int i = 0; i < n; i ++) 
//  {
//    cout << balance[i].leftBalances.size() << ' ' << balance[i].rightBalances.size() << endl;
//  }

  return 0;
}
