#include<cstdio>
#include<vector>
#include "memory.h"
#define MAXN 16
#define MAXM 1010
using namespace std;
struct edge
{
  int u,v,w;
}e[MAXM<<1];
int dep[MAXN],vis[MAXN],n=0,m=0,ans=0x7fffffff,cnt=0;
inline void init();
inline void prim();
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&,const int&);
int main()
{
  register int i=0,j=0,u=0,v=0,w=0;
  freopen("treasure.in","r",stdin);freopen("treasure.out","w",stdout);
  read(n);read(m);
  for(i=1;i<=m;++i)
  {
  	read(u);read(v);read(w);
  	addedge(u,v,w);
  	//e[u].push_back(make_pair(v,w));
  	//e[v].push_back(make_pair(u,w));
  }
  for(i=1;i<=n;++i)
  {
  	init();
  	dep[i]=vis[i]=1;
  	prim();
  }
  write(ans);
  return 0;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++cnt].u=u;
  e[cnt].v=v;
  e[cnt].w=w;
  e[++cnt].u=v;
  e[cnt].v=u;
  e[cnt].w=w;
  return;
}
inline void prim()
{
  int i=0,j=0,sum=0,id=0,w=0;
  for(i=1;i<n;++i)
  {
  	for(j=1,w=0x3f3f3f3f;j<=cnt;++j)
  	{
  	  if(vis[e[j].u]&&!vis[e[j].v]&&w>e[j].w*dep[e[j].u])
  	  {
  	    w=e[j].w*dep[e[j].u];
  	    id=j;
	  }
	}
	dep[e[id].v]=dep[e[id].u]+1;
	vis[e[id].v]=1;
	sum+=w;
  }
  if(ans>sum)
  {
  	ans=sum;
  }
  return;
}
inline void init()
{
  memset(vis,0,sizeof(vis));
  memset(dep,0,sizeof(dep));
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
  register char c=getchar(),f=0;
  for(x=0;c<'0'|c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  f=1;
	}
  }
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  if(f)
  {
  	++(x=~x);
  }
  return;
}
