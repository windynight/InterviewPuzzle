/*

   Print the Binary Tree:
   
             A 
            / \
            B C
           /  / \
           D  E F
            /  \
            G  H
            
            A
            B C
            D E F
            G H
*/            
             
typedef Node {
  int data;
  Node *left;
  Node *right;
}

void searchAndPrint(int currentLine, int line, Node* root)
{
  if (line == currentLine)
  {
    cout << root->data << ' ';
    return;
  }
  
  if (root == NULL)
  {
    return;
  }
  
  if (root->left) 
  {
    searchAndPrint(currentLine + 1, line, root->left);
  }
  
  if (root->right)
  {
    searchAndPrint(currentLine + 1, line, root->right);
  }
}

int searchAndGetLines(Node* root, int currentLine)
{
  if (root == NULL)
  {
    return currentLine;
  }
  
  int leftCount = searchAndGetLines(root->left, currentLine + 1);
  int rightCount = searchAndGetLines(root->right, currentLine + 1);
  
  return leftCount > rightCount ? leftCount : rightCount;
}

int linesOfTree(Node root)
{
  return searchAndGetLines(&root, 0);
} 

void printTree(Node root)
{
  int count = linesOfTree(root);
  
  for (int i = 0; i < count; i ++) 
  {
    searchAndPrint(0, i, &root);
    cout << endl;
  }
}
