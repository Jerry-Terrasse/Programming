//P3386 【模板】二分图匹配
//Dinic
#include<cstdio>
#include<queue>
#include "memory.h"
#define MAXN 1010
#define MAXE 1000010
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct edge
{
  int to,nxt,w;
}e[MAXE<<1];
int hd[MAXN<<1],dep[MAXN<<1],ec=1,n=0,m=0,s=0,t=0,ans=0;
queue<int>q;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
inline void dinic();
inline bool bfs();
inline int dfs(const int&,int);
int main()
{
  register int i=0,u=0,v=0,w=0;
  read(n);read(m);read(w);m+=n;
  s=m+1;t=m+2;
  for(i=1;i<=w;++i)
  {
    read(u);read(v);
    if(u<=n&&v<=m)
    {
      addedge(u,n+v);
    }
  }
  for(i=1;i<=n;++i)
  {
    addedge(s,i);
  }
  for(i=n+1;i<=m;++i)
  {
    addedge(i,t);
  }
  dinic();
  write(ans);
  putchar('\n');
  return 0;
}
int dfs(const int &u,int flw)
{
  if(u==t)
  {
    return flw;
  }
  register int rst=flw,i=0,v=0,k=0;
  for(i=hd[u];i;i=e[i].nxt)
  {
    v=e[i].to;
    if(e[i].w&&dep[v]==dep[u]+1)
    {
      k=dfs(v,min(rst,e[i].w));
      e[i].w-=k;
      e[i^1].w+=k;
      rst-=k;
    }
  }
  if(flw==rst)
  {
    dep[u]=0;
  }
  return flw-rst;
}
inline bool bfs()
{
  register int i=0,u=0,v=0;
  for(;q.size();q.pop());
  memset(dep,0,sizeof(dep));
  dep[s]=1;
  q.push(s);
  for(;q.size();)
  {
    u=q.front();q.pop();
    for(i=hd[u];i;i=e[i].nxt)
    {
      v=e[i].to;
      if(e[i].w&&!dep[v])
      {
        dep[v]=dep[u]+1;
        q.push(v);
        if(v==t)
        {
          return true;
        }
      }
    }
  }
  return false;
}
inline void dinic()
{
  register int ret=0;
  for(;bfs();)
  {
    for(;ret=dfs(s,INF);ans+=ret);
  }
  return;
}
inline void addedge(const int &u,const int &v)
{
  e[++ec].to=v;
  e[ec].nxt=hd[u];
  e[ec].w=1;
  hd[u]=ec;
  e[++ec].to=u;
  e[ec].nxt=hd[v];
  hd[v]=ec;
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}