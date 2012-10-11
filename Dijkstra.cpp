
/*
http://acm.cs.ecnu.edu.cn/problem.php?problemid=1887
*/

#include<stdio.h>
 
const int inf = 2000000000;
#define maxm 152000
#define maxn  31000
 
int n ,m, num, len, next[maxm], ev[maxm], ew[maxm];
int value[maxn], mk[maxn], nbs[maxn], ps[maxn], heap[maxn];
 
void update(int r)
{
    int q = ps[r], p = q>>1;
    while(p && value[heap[p]]>value[r])
    {
    	ps[heap[p]] = q;
    	heap[q] = heap[p];
    	q = p; p = q>>1;
    }
    heap[q] = r;
    ps[r] = q;
}
 
int getmin()
{
    int ret=heap[1], p=1, q=2, r=heap[len--];
    while(q<=len)
    {
    	if(q<len && value[heap[q+1]]<value[heap[q]] ) ++q;
		if(value[heap[q]]<value[r])
		{
			ps[heap[q]] = p;
			heap[p] = heap[q];
			p = q;
			q = p<<1;
		}
		else break;
	}
	heap[p] = r;
	ps[r] = p;
	return ret;
}
 
void dijkstra(int src , int dst)
{ 
	int i, j, u, v;
	for( i=1; i<=n ; i++) { value[i]= inf; mk[i]=ps[i]=0 ; } ;
	value[src]=0 ; heap [len=1]=src; ps[src]=1;
	while(!mk[dst])
	{
		if(len==0) return ;
 
		u = getmin(); mk[u]=1;
 
		for(j=nbs[u]; j ;j=next[j])
		{ 
			v = ev[j]; 
			if(!mk[v] && value[u]+ew[j]<value[v]) 
			{
				if(ps[v]==0)
				{ 
					heap[++len] = v; 
					ps[v] = len;
				}
				value[v]=value[u] + ew[j];
				update(v) ;
			}
		}
	}
}
 
void readdata( )
{
	int i , u , v ,w;
    while(scanf("%d%d", &n, &m)!=EOF)
	{
		num=0;
		for ( i=1; i<=n ; i++) nbs [i]=0;
		while(m--)
		{
			scanf("%d%d%d", &u,&v,&w);
			next[++num]=nbs[u];nbs[u]=num;
			ev[num]=v ; ew[num]=w;
		}
		dijkstra(1, n) ; // Minimum Dis tance saved at value [ 1 . . n ]
		printf("%d\n",value[n]);
	}
}
 
int main()
{
	readdata();
	return 0;
}