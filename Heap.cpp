
/*
 Heap:
 http://acm.cs.ecnu.edu.cn/problem.php?problemid=2149
 */

#include<iostream>
using namespace std;
struct heapnode{int posi,v;}heap[100010];
int size;
void switch_up(int position)
{
	int p=position,f=p>>1;
	heapnode tmp=heap[p];
	while(f>0)
	{
		if(tmp.v<heap[f].v)  heap[p]=heap[f]; else break;
		p=f;f=f>>1;
	}
	heap[p]=tmp;
	return;
}	

void add(heapnode a)
{
	heap[++size]=a;
	switch_up(size);
}

void switch_down(int position)
{
	int c,p=position;   c=p<<1;
	heapnode tmp=heap[p];
	while(c<=size)
	{
		if(c<size&&heap[c+1].v<heap[c].v)  c++;
		if(heap[c].v<tmp.v)  heap[p]=heap[c];  else break;
		p=c;c=c<<1;
	}
	heap[p]=tmp;
	return;
}

void pop()
{
	heap[1]=heap[size--];
	switch_down(1);
	return;
}

bool flag[100010];
int que[100010];
int 
main()
{
	int head,tail,i,j,n,m,k,num;
	char op[10];
	heapnode temp;
	while(scanf("%d",&num)==1)
	{
		n=0;head=tail=0;
		memset(flag,1,sizeof(flag));
		while(num--)
		{
			scanf("%s",op);
			switch(op[0])
			{
        case 'i':  
          n++;
          scanf("%d",&temp.v);
          que[tail]=temp.v;
          temp.posi=tail++;
          add(temp);
          printf("%d\n",n);
          break;
        case 'd':
          n--;
          while(flag[head]==false)  head++;
          flag[head]=false;
          printf("%d\n",que[head++]);
          break;
        case 'M':
          n--;
          while(flag[heap[1].posi]==false)  pop();
          flag[heap[1].posi]=false;
          printf("%d\n",heap[1].v);
          pop();
          break;
			}
		}
	}
	return 0;
}
