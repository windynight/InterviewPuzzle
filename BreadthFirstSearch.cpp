/*
http://acm.cs.ecnu.edu.cn/problem.php?problemid=1839
*/

#include<iostream>
#include<string>
using namespace std;
struct q{int x,y,d,f;} que[40805];
bool map[202][202],visit[202][202];
int n,m,head,tail;
int sx,sy,ex,ey,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char s[202];
void print(int head)
{
	if(head) print(que[head].f);
	printf("%d %d\n",que[head].x,que[head].y);
}

void BFS(int sx,int sy)
{
	int tempx,tempy,i;
	head=0;tail=1;
	memset(visit,false,sizeof(visit));
	que[0].x=sx,que[0].y=sy;
	while(head<tail)
	{
		if(que[head].x==ex&&que[head].y==ey)
		{
			printf("%d\n",que[head].d);
			print(head);
			return;
		}
		else
		{
			for(i=0;i<4;i++)
			{
				tempx=que[head].x+dx[i];
				tempy=que[head].y+dy[i];
				if(tempx>=0&&tempx<n&&tempy>=0&&tempy<m&&!visit[tempx][tempy]&&!map[tempx][tempy])
				{
					visit[tempx][tempy]=1;
					que[tail].x=tempx;
					que[tail].y=tempy;
					que[tail].d=que[head].d+1;
					que[tail].f=head;
					tail++;
				}
			}
		}
		head++;
	}
	printf("-1\n");
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)  
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<m;j++)
			{
				if(s[j]=='S') {sx=i;sy=j;map[i][j]=0;}
				else if(s[j]=='E') {ex=i;ey=j;map[i][j]=0;}
				else if(s[j]=='*') map[i][j]=1;
				else if(s[j]=='.') map[i][j]=0;
			}
		}
		BFS(sx,sy);
	}
	return 0;
}
