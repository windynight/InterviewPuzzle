/*
 
 Print the Binary Tree:
 
    A 
   / \
  B   C
 /   / \
D   E   F
   / \
  G   H
 
 A
 B C
 D E F
 G H
 
 */            

#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

Node *q[10000];

Node *newNode(int data)
{
  Node *node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  
  return node;
}

Node *insertNode(Node *root, int data)
{
  if (!root) {
    return newNode(data);
  }
  
  if (root->data >= data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }
  
  return root;
}

void printTreeBreadthFirst(Node *root)
{
  int head = 0, tail = 1;
  q[0] = root;
  
  while (head < tail) {
    int i = head;
    for (; i < tail; i ++) {
      cout << q[i]->data << ' ';
    }
    cout << endl;
    
    i = head;
    int end = tail;
    head = tail;
    
    for (; i < end; i ++) {
      if (q[i]->left) {
        q[tail ++] = q[i]->left;
      }
      if (q[i]->right) {
        q[tail ++] = q[i]->right;
      }
    }
  }
}


int main(){
  Node *head;
  for (int i = 0; i < 20; i ++) {
    int r = rand() % 10 + 1;
    head = insertNode(head, r);
  }
  
  printTreeBreadthFirst(head);
  
  return 0;
}
