/*
 To find if there is a route from start to destination.
 
 Sample Input:
 4 6 1 3
 0 1
 0 2
 1 2
 2 0
 2 3
 3 3
 
 4 6 3 1
 0 1
 0 2
 1 2
 2 0
 2 3
 3 3
 
 Sample Output:
 There is a path from 1 to 3
 There is no path from 3 to 1
 
 */

#include<iostream>
#include <list>

using namespace std;

class Graph
{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isReachable(int s, int d);
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

bool Graph::isReachable(int s, int d)
{
  if (s == d) {
    return true;
  }
  
  bool *visited = new bool[V];
  for (int i = 0; i < V; i ++) {
    visited[i] = false;
  }
  
  list<int> q;
  visited[s] = true;
  q.push_back(s);
  
  list<int>::iterator i;
  
  while (!q.empty()) {
    s = q.front();
    
    for (i = adj[s].begin(); i != adj[s].end(); i ++) {
      if (*i == d) {
        return true;
      }
      
      if (!visited[*i]) {
        visited[*i] = true;
        q.push_back(*i);
      }
    }
    
    q.pop_front();
  }

  return false;
}

int main()
{
  int n, m, u, v;
  
  while (cin >> n >> m >> u >> v && n) {
    Graph g(n);
    int s, d;
    for (int i = 0; i < m; i ++) {
      cin >> s >> d;
      g.addEdge(s, d);
    }
    
    if(g.isReachable(u, v))
      cout<< "\n There is a path from " << u << " to " << v;
    else
      cout<< "\n There is no path from " << u << " to " << v;

  }

  return 0;
}
