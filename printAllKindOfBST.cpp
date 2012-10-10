#include <iostream>

using namespace std;

struct Node {
  Node * left;
  Node * right;
  int value;
};

void printTree(Node * root)
{  
  cout << root->value << ' ';
  
  if (root->left) {
    cout << ' ' << root->left -> value;
  } else {
    cout << " NULL";
  }
  
  if (root->right) {
    cout << ' ' << root->right -> value;
  } else {
    cout << " NULL";
  }
  
  cout << endl;
  
  if (root->left) {
    printTree(root->left);
  }

  if (root->right) {
    printTree(root->right);
  }
}

int nodeNumbers(Node *node)
{
  if (!node) {
    return 0;
  }
  
  return 1 + nodeNumbers(node->left) + nodeNumbers(node->right);
}

bool isTreeCompleted(Node *node, int length)
{
  int count = nodeNumbers(node);
  
  return count == length;
}

bool createTree(int subRoot, int left, int right, Node * array, int length, int & treeCount, int root)
{
  Node * subRootNode = &array[subRoot];
  subRootNode->left = subRootNode->right = NULL;

  if (left == right && isTreeCompleted(&array[root], length)) {
    treeCount ++;
    
    cout << "Tree " << treeCount << ':' << endl;
    printTree(&array[root]);
    cout << endl;
    
    return true;
  }
  
  
  //when left sub tree is NULL
  if (left == subRoot) {
    bool flag = false;
    
    //create right sub tree
    for (int i = subRoot + 1; i <= right; i ++) {
      subRootNode->right = &array[i];    
      if(createTree(i, subRoot + 1, right, array, length, treeCount, root)) {
        flag = true;
      }
    }
    
    if (flag) {
      subRootNode->right = NULL;
    }
    return false;
  }
  
  //when right sub tree is NULL
  if (subRoot == right) {
    bool flag = false;
    
    //create right sub tree
    for (int i = left; i < subRoot; i ++) {
      subRootNode->left = &array[i];    
      if(createTree(i, left, subRoot - 1, array, length, treeCount, root)) {
        flag = true;
      }
    }
    
    if (flag) {
      subRootNode->left = NULL;
    }
    return false;
  }
  
  //create left sub tree
  for (int i = left; i < subRoot; i ++) {
    bool flag = false;
    
    subRootNode->left = &array[i];
    
    //create right sub tree
    for (int j = subRoot + 1; j <= right; j ++) {
      
      subRootNode->right = &array[j]; 
      if (createTree(i, left, subRoot - 1, array, length, treeCount, root)) {
        flag = true;
      }
      
      if (flag) {
        subRootNode->left = NULL;
      }
      
      if(createTree(j, subRoot + 1, right, array, length, treeCount, root)) {
        flag = true;
      }
      
      if (flag) {
        subRootNode->left = NULL;
        subRootNode->right = NULL;
      }
    }
    
//    if (flag) {
//      subRootNode->left = NULL;
//      subRootNode->right = NULL;
//    }
  }

  return false;
}

void clearTree(Node * array, int length)
{
  for (int i = 0; i <= length; i ++) {
    array[i].left = array[i].right = NULL;
  }
}

void printAllKindsOfBST(int n)
{
  Node array[n + 1];
  
  for (int i = 1; i <= n; i ++) {
    array[i] = Node();
    array[i].value = i;
    array[i].left = array[i].right = NULL;
  }
  
  int treeCount = 0;
  for (int i = 1; i <= n; i ++) {
    clearTree(array, n);
    createTree(i, 1, n, array, n, treeCount, i);
  }
}

int main ()
{
  int n;
  while (cin >> n && n) {
    printAllKindsOfBST(n);
  }
}