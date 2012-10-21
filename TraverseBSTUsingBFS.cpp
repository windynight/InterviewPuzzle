#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node () {}
  Node (int d) : data(d) {}
};

Node *newNode(int data)
{
  return new Node(data);
}

Node *insertNode(Node *root, int data)
{
  if (root == NULL) {
    return newNode(data);
  }
  
  if (data <= root->data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }
  
  return root;
}

void bfs(Node *root)
{
  queue<Node*> q;
  q.push(root);
  Node *end = q.back();
  
  while (!q.empty()) {
    Node *node = q.front();
    
    if (node->left) {
      q.push(node->left);
    }
    if (node->right) {
      q.push(node->right);
    }
    
    cout << node->data << ' ';
    
    if (node == end) {
      cout << endl;
      end = q.back();
    }
    
    q.pop();
  }
}

int main()
{
  Node *root = NULL;
  root = insertNode(root, 5);
  root = insertNode(root, 6);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 2);
  root = insertNode(root, 3);
  root = insertNode(root, 1);
  root = insertNode(root, 8);
  root = insertNode(root, 9);
  
  bfs(root);

  return 0;
}