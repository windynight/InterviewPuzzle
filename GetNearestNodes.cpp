/*
 
 Give a Binary Search Tree, and key, m
 Find m nodes whose data is nearest key. ( minimal abs(node->data - key) )

 Sample Input: 
 10 4
 
 Sample Output:
 10 13 7 16
 
 Hint:
 1. Find the pivot whose value is nearest key (less than, equal, or greater than)
 2. Find m-1 nodes whose value is less than pivot, whose value is ordered ascending
 3. Find m-1 nodes whose value is greater than pivot, whose value is ordered asceding
 4. Print the m nodes
 
 Running time complexity: O(m * logn)
 Extra space complexity: O(m)
 */

#include <iostream>

using namespace std;

typedef struct NodeT {
  int data;
  NodeT *left, *right;
  
  NodeT (int n) : data(n) {}
}Node;

Node * newNode(int n)
{
  Node * node = new Node(n);
  return node;
}

Node * insertNode(Node *root, int n)
{
  if (root == NULL) {
    Node *node = newNode(n);
    return node;
  }
  
  if (n < root->data) {
    root->left = insertNode(root->left, n);
  } else {
    root->right = insertNode(root->right, n);
  }
  
  return root;
}

Node *getPrevious(Node *root, int n)
{
  if (root == NULL || root->data == n) {
    return root;
  }
  
  if (root->data > n) {
    return getPrevious(root->left, n);
  }
  
  Node *right = getPrevious(root->right, n);
  if (right == NULL) {
    return root;
  } else {
    return right;
  }
}

Node *getNext(Node *root, int n)
{
  if (root == NULL || root->data == n) {
    return root;
  }
  
  if (root->data < n) {
    return getNext(root->right, n);
  }
  
  Node *next = getNext(root->left, n);
  if (next == NULL) {
    return root;
  } else {
    return next;
  }
}

Node *getPreviousBeforeNode(Node *root, Node *node)
{
  if (root == NULL || node == NULL) {
    return NULL;
  }
  
  if (root->data < node->data) {
    Node *previous = getPreviousBeforeNode(root->right, node);
    if (previous == NULL) {
      return root;
    } else {
      return previous;
    }
  } else {
    return getPreviousBeforeNode(root->left, node);
  }
}

Node *getNextAfterNode(Node * root, Node *node)
{
  if (root == NULL || node == NULL) {
    return NULL;
  }
  
  if (root->data > node->data) {
    Node *next = getNextAfterNode(root->left, node);
    if (next == NULL) {
      return root;
    } else {
      return next;
    }
  } else {
    return getNextAfterNode(root->right, node);
  }
}

void findNearest(Node *root, int key, int m)
{
  if (m == 0) {
    return;
  }

  int count = 0;
  int arr[2 * m][2];  //arr[i][0] = node->data, arr[i][1] = abs(node->data - key)
  bool isPreviousPivot = true;
  int middle = 0;
  Node *tmpPivot;

  //Pivot is the node whose data is the nearest value of the given key
  Node *pivot = getPrevious(root, key);
  if (pivot == NULL) {
    pivot = getNext(root, key);
    isPreviousPivot = false;
    
    if (pivot == NULL) {
      cout << "None" << endl;
      return;
    }
  } else {
    arr[count][0] = pivot->data;
    arr[count][1] = abs(key - pivot->data);
    count ++;
  }
  
  //get m-1 nodes whose value is less than key
  tmpPivot = pivot;
  for (int i = 0; i < m - 1; i ++) {
    tmpPivot = getPreviousBeforeNode(root, tmpPivot);
    if (tmpPivot == NULL) {
      break;
    } 
    
    arr[count][0] = tmpPivot->data;
    arr[count][1] = key - tmpPivot->data;
    count ++;
  }
  
  //0 through middle-1 are less than key
  middle = count;
  
  //get m-1 nodes whose value is greater than key, including the pivot if the pivot is greater than key
  tmpPivot = pivot;
  if (!isPreviousPivot) {
    arr[count][0] = pivot->data;
    arr[count][1] = abs(key - pivot->data);
    count ++;
  }
  
  for (int i = 0; i < m - 1; i ++) {
    tmpPivot = getNextAfterNode(root, tmpPivot);
    if (tmpPivot == NULL) {
      break;
    } 
    
    arr[count][0] = tmpPivot->data;
    arr[count][1] = tmpPivot->data - key;
    count ++;
  }
  
  
  if (count <= m) {
    for (int i = 0; i < count; i ++) {
      cout << arr[i][0] << ' ';
    }
  } else {
    //0 through middle-1 is sorted in ascending order, the same with middle through count
    //So, just using two point to print nearest m nodes one by one.
    int h1 = 0, h2 = middle;
    while (m) {
      if (h2 >= count || (h1 < middle && arr[h1][1] < arr[h2][1]) ) {
        cout << arr[h1][0] << ' ';
        h1 ++;
      } else {
        cout << arr[h2][0] << ' ';
        h2 ++;
      }
      
      m --;
    }
  }
  
  cout << endl;
}

int main()
{
  Node *root = NULL;
  
  int len = 1000;
  for (int i = len / 2 + 1; i < len; i += 3) {
    root = insertNode(root, i);
    root = insertNode(root, len - i);
  }
  
  int key, m;
  while (cin >> key >> m) {
    findNearest(root, key, m);
  }
  
  return 0;
}