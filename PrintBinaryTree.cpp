#include <iostream>
using namespace std;

typedef struct NodeT {
  int data;
  NodeT *left;
  NodeT *right;
  NodeT(int d) : data(d) {}
}TreeNode;

void searchAndPrint(int currentLine, int line, TreeNode* root)
{
  if (root == NULL) {
    return;
  }
  
  if (line == currentLine) {
    cout << root->data << ' ';
  }
  
  if (root->left) {
    searchAndPrint(currentLine + 1, line, root->left);
  }
  
  if (root->right) {
    searchAndPrint(currentLine + 1, line, root->right);
  }
}

int searchAndGetLines(TreeNode* root, int currentLine)
{
  if (root == NULL) {
    return currentLine;
  }
  
  int leftCount = searchAndGetLines(root->left, currentLine + 1);
  int rightCount = searchAndGetLines(root->right, currentLine + 1);
  
  return leftCount > rightCount ? leftCount : rightCount;
}

int linesOfTree(TreeNode root)
{
  return searchAndGetLines(&root, 0);
} 

void printTree(TreeNode root)
{
  int count = linesOfTree(root);
  
  for (int i = 0; i < count; i ++) {
    searchAndPrint(0, i, &root);
    cout << endl;
  }
}

void bfs(TreeNode *root)
{
  if (root == NULL) {
    return;
  }
  
  TreeNode *queue[1000];
  int head = 0;
  int tail = 1;
  queue[0] = root;
  TreeNode *last = queue[head];
  
  while (head < tail) {
    TreeNode *current = queue[head];
    
    if (current->left) {
      queue[tail ++] = current->left;
    }
    if (current->right) {
      queue[tail ++] = current->right;
    }
    
    if (current == last) {
      cout << current->data << endl;
      last = queue[tail - 1];
    } else {
      cout << current->data << ' ';
    }
    
    head ++;
  }
}


int main ()
{
  //  0 
  //  1 2 
  //  3 4 5 
  //  6  
  
  TreeNode *root = new TreeNode(0);
  TreeNode *node1 = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(3);
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(5);
  TreeNode *node6 = new TreeNode(6);
  
  root->left = node1;
  root->right = node2;
  
  node1->left = node3;
  node1->right = node4;
  
  node2->left = node5;
  node5->right = node6;
  
  cout << "DFS: " << endl;
  printTree(*root);
  
  cout << "BFS: " << endl;
  bfs(root);
  
  return 0;
}













