#include<cstdio>
#include<queue>
#include "memory.h"
#define MAXM 200020
#define MAXN 100010
using namespace std;
struct edge
{
  int to,w,next;
}e[MAXM];
int vis[MAXN],d[MAXN],head[MAXN],t=0,n=0,m=0,k=0,H=0,cnt=0,ans=0;
priority_queue<pair<int,int> >q;
inline void read(int&);
void write(const int&);
inline void init();
inline void addedge(const int&,const int&,const int&);
void dfs(const int&,const int&);
int main()
{
  register int i=0,u=0,v=0,w=0;
  freopen("park.in","r",stdin);freopen("park.out","w",stdout);
  read(t);
  for(;t--;)
  {
    init();
    read(n);read(m);read(k);read(H);
    for(i=1;i<=m;++i)
    {
      read(u);read(v);read(w);
      addedge(u,v,w);
    }
    for(q.push(make_pair(0,1)),d[1]=0;q.size();)
    {
      u=q.top().second;
      q.pop();
      if(vis[u])
      {
      	continue;
	  }
	  vis[u]=true;
      for(i=head[u];i;i=e[i].next)
      {
      	v=e[i].to;
      	if(d[u]+e[i].w<d[v])
      	{
      	  d[v]=d[u]+e[i].w;
      	  q.push(make_pair(-d[v],v));
		}
	  }
	}
	dfs(1,d[n]+k);
	write(ans);
	putchar('\n');
  }
  return 0;
}
void dfs(const int &x,const int &dis)
{
  if(x==n)
  {
  	++ans;
  	if(ans==H)
  	{
  	  ans=0;
	}
  }
  register int i=0;
  for(i=head[x];i;i=e[i].next)
  {
  	if(dis>=e[i].w)
  	{
  	  dfs(e[i].to,dis-e[i].w);
	}
  }
  return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++cnt].to=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
  return;
}
inline void init()
{
  memset(head,0,sizeof(head));
  memset(e,0,sizeof(e));
  memset(d,0x3f,sizeof(d));
  memset(vis,0,sizeof(vis));
  cnt=ans=0;
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
  register char c=getchar();
  for(x=0; c<'0'|c>'9'; c=getchar());
  for(; c>='0'&c<='9'; c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
