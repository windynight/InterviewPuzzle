//dijkstra with heap

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Heap
struct dis
{
	int distant;
	int node;	
};

//size and array
int HeapSize;
dis Heap[1000000];

void Heap_Up(int position)
{
	int father=position>>1;
	dis temp=Heap[position];
  
	while (father>0)
	{
		if (temp.distant<Heap[father].distant) Heap[position]=Heap[father]; else break;
		position=father; father= position >>1;
	}
	Heap[position]=temp;
}

void Heap_Add(dis d)
{
	Heap[++HeapSize]=d;
	Heap_Up(HeapSize);
}

void Heap_Down(int position)
{
	int child = position<<1;
	dis temp=Heap[position];
  
	while (child<=HeapSize)
	{
		if (child<HeapSize && Heap[child+1].distant<Heap[child].distant) child++;
		if (Heap[child].distant<temp.distant) Heap[position]=Heap[child]; else break;
		position=child; child=position <<1;
	}
	Heap[position]=temp;
}

dis Heap_Pop()
{
	dis top=Heap[1];
	Heap[1]=Heap[HeapSize--];
	Heap_Down(1);
	return top;
}

// 临接链表
struct list
{
	// 当前边指向的结点
	int targetnode;
	// 边权
	int weight;
	// 下一条边
	int nextID;
};

// 当前生成边的数量
int nowedge;

// 每条边
list edges[300000];

// 每个结点的边开始
int edge[50001];

int distant[50001];
bool visited[50001];

const int MaxDis=2000000000;
int N,M;

void dijkstra()
{
	int i,j,k;
  
	// init
	for (i=1;i<=N;++i) 
	{
		visited[i]=false;
		distant[i]=MaxDis;
	}
  
	// init
	HeapSize=0;
  
	dis temp;
	dis addtemp;
  
	temp.distant=0;
	temp.node=N;
	Heap_Add(temp);
  
	int now;
	bool found;
  
	for (i=1;i<=N;++i)
	{
		if (HeapSize<=0) break;
		found=false;
		while (true)
		{
			if (HeapSize<=0) break;
			temp=Heap_Pop();
			if (!visited[temp.node])
			{
				found=true;
				break;
			}
		}
		if (!found) break;
    
		visited[temp.node]=true;
		distant[temp.node]=temp.distant;
		if (temp.node==1) break;
    
		now=edge[temp.node];
		while (now != 0)
		{
			j=edges[now].targetnode;
			k=edges[now].weight;
      
			if (!visited[j] && distant[temp.node]+k<distant[j])
			{
				distant[j]=distant[temp.node]+k;
				addtemp.distant=distant[j];
				addtemp.node=j;
				Heap_Add(addtemp);
			}
			now=edges[now].nextID;
		}
	}
	cout<<distant[1]<<endl;
}


int main()
{
	int i,j,k,w;
  
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		nowedge=0;
		for (i=1;i<=N;++i) edge[i]=0;
		for (k=1;k<=M;++k)
		{
			scanf("%d%d%d",&i,&j,&w);
      
			nowedge++;
			edges[nowedge].targetnode=i;
			edges[nowedge].weight=w;
			edges[nowedge].nextID=edge[j];
			edge[j]=nowedge;
		}
		dijkstra();
	}
  
	return 0;
}