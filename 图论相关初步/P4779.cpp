#include<cstdio>
#include<queue>
#include "memory.h"
#define MAXN 400010
#define MAXM 800020
using namespace std;
struct edge
{
	int to,next,w;
} e[MAXM];
int head[MAXN],dis[MAXN],vis[MAXN],n=0,m=0,s=0,cnt=0;
char c='\0';
priority_queue<pair<int,int> >q;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&,const int&);
int main()
{
	register int i=0,u=0,v=0,w=0;
	memset(dis,0x3f,sizeof(dis));
	read(n);
	read(m);
	read(s);
	for(i=1; i<=m; ++i)
	{
		read(u);
		read(v);
		read(w);
		addedge(u,v,w);
	}
	for(q.push(make_pair(0,s)),dis[s]=0; q.size();)
	{
		u=q.top().second;
		 q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(i=head[u]; i; i=e[i].next)
		{
			if(dis[e[i].to]>dis[u]+e[i].w)
			{
				dis[e[i].to]=dis[u]+e[i].w;
				q.push(make_pair(-dis[e[i].to],e[i].to));
			}
		}
	}
	for(i=1; i<=n; ++i)
	{
		write(dis[i]);
		putchar(' ');
	}
	putchar('\n');
	return 0;
}
inline void addedge(const int &u,const int &v,const int &w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
	return;
}
void write(const int &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10^48);
	return;
}
inline void read(int &x)
{
	for(x=0; c<'0'|c>'9'; c=getchar());
	for(; c>='0'&c<='9'; c=getchar())
	{
		x=(x<<1)+(x<<3)+(c^48);
	}
	return;
}
