/*
 CareerCup Amazon Interview:
 http://www.careercup.com/question?id=14801886
 
 How to sort a single linked list with out using an additional node?
 Hint: Do not allow using additional node, but is it allowed to use additional node values?
 */

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct NodeT {
  int data;
  NodeT *right;
}Node;


void swapNode(Node *l, Node *r)
{
  int tmp = l->data;
  l->data = r->data;
  r->data = tmp;
}

Node * newNode(int num)
{
  Node * node = new Node();
  node->data = num;
  node->right = NULL;
  return node;
}

Node * appendNode(Node *root, int data)
{
  if (root == NULL) {
    return newNode(data);
  }
  
  Node *node = newNode(data);
  
  root->right = node;
  
  return node;
}

Node * sortList(Node *head, int n)
{
  if (head == NULL || head->right == NULL || n <= 1) {
    return head;
  }

  int randIndex = rand() % n;
  
  Node *target = head;
  
  for (int i = 0; i < randIndex; i ++) {
    if (target) {
      target = target->right;
    }
  }
  
  swapNode(head, target);
  
  int i = 1, count = 0;
  Node *tail = head;
  for (Node *iter = head->right; i < n && iter; i ++, iter = iter->right) {
    if (iter->data < head->data) {
      count ++;
      tail = tail->right;
      swapNode(tail, iter);
    }
  }
  
  swapNode(head, tail);
  
  head = sortList(head, count);
  tail->right = sortList(tail->right, n - count - 1);
  
  return head;
}

void printList(Node *head, int n)
{  
  if (!head) {
    return;
  }
  
  for (int i = 0; i < n && head; i ++) {
    cout << head->data << " ";
    head = head->right;
  }
  
  cout << endl;
}

void cleanList(Node *root)
{
  if (root == NULL) {
    return;
  }
  
  cleanList(root->right);
  
  root->right = NULL;
  root->data = 0;
  
  delete root;
}

int main()
{
  int a[1000];
  int n = 100;
  while (cin >> n && n != 0) {
    if (n > 1000) {
      break;
    }
    
    for (int i = 0; i < n; i ++) {
      a[i] = i;
    }
    
    for (int i = 0; i < n; i ++) {
      int r = rand() % n;
      int tmp = a[i];
      a[i] = a[r];
      a[r] = tmp;
    }
    
    Node *head = NULL;
    head = appendNode(head, a[0]);
    Node *last = head;
    
    for (int i = 1; i < n; i ++) {
      last = appendNode(last, a[i]);
    }
  
    head = sortList(head, n);
    printList(head, n);    
    cleanList(head);
  }
  
  return 0;
}