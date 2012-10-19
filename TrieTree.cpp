/*
 Trie Tree Implementation
 */

#include<algorithm>
#include<iostream>
using namespace std;

const int sonnum=26,base='a';
struct Trie
{
  int num;//to remember how many word can reach here,that is to say,prefix
  bool terminal;//If terminal==true, the current point has no following point
  struct Trie *son[sonnum];//the following point
};

Trie *NewTrie()// create a new node
{
  Trie *temp = new Trie;
  temp->num = 1;
  temp->terminal = false;
  for(int i = 0;i < sonnum; i ++) {
    temp->son[i] = NULL;
  }
  return temp;
}

void Insert(Trie *pnt,char *s,int len)// insert a new word to Trie tree
{
  Trie *temp = pnt;
  for(int i = 0; i < len; i ++)
  {
    if(temp->son[s[i]-base] == NULL) {
      temp->son[s[i]-base] = NewTrie();
    } else {
      temp->son[s[i]-base]->num++;
    }
    temp = temp->son[s[i]-base];
  }
  temp->terminal = true;
}
void Delete(Trie *pnt)// delete the whole tree
{
  if(pnt!=NULL)
  {
    for(int i = 0; i < sonnum; i ++) {
      if(pnt->son[i]!=NULL) {
        Delete(pnt->son[i]);
      }
    }
    delete pnt; 
    pnt = NULL;
  }
}
Trie* Find(Trie *pnt,char *s,int len)//trie to find the current word
{
  Trie *temp = pnt;
  for(int i = 0; i < len; i ++) {
    if(temp->son[s[i]-base] != NULL) {
      temp = temp->son[s[i]-base];
    } else {
      return NULL;
    }
  }
    
  return temp;
}