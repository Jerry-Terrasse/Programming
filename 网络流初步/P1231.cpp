#include<cstdio>
#include<queue>
#include "memory.h"
#define MAXN 40040
#define MAXM 20020
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct edge
{
  int to,nxt,w;
}e[MAXM<<3];
int hd[MAXN],dep[MAXN],ec=1,n1=-0,n2=0,n3=0,m1=0,m2=0,s=0,t=0,ans=0;
queue<int>q;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
inline void dinic();
inline bool bfs();
int dfs(const int&,int);
inline void init();
int main()
{
  register int i=0,u=0,v=0;
  read(n1);read(n2);read(n3);
  s=n2+2*n1+n3+1;t=s+1;
  for(i=1;i<=n2;++i)
  {
    addedge(s,i);
  }
  for(i=1;i<=n1;++i)
  {
    addedge(n2+i,n2+n1+i);
  }
  for(i=1;i<=n3;++i)
  {
    addedge(n2+2*n1+i,t);
  }
  for(read(m1),i=1;i<=m1;++i)
  {
    read(u);read(v);
    addedge(v,n2+u);
  }
  for(read(m2),i=1;i<=m2;++i)
  {
    read(u);read(v);
    addedge(n2+n1+u,n2+2*n1+v);
  }
  dinic();
  write(ans);
  return 0;
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
int dfs(const int &u,int flw)
{
  register int i=0,v=0,rst=flw,dlt=0;
  for(i=hd[u];i&&rst;i=e[i].nxt)
  {
    if(e[i].w&&dep[v=e[i].to]==dep[u]+1)
    {
      if(v==t)
      {
        dlt=min(flw,e[i].w);
      }
      else
      {
        dlt=dfs(v,min(flw,e[i].w));
      }
      if(dlt)
      {        
        e[i].w-=dlt;
        e[i^1].w+=dlt;
        rst-=dlt;
      }
      else
      {
        dep[v]=0;
      }
    }
  }
  return flw-rst;
}
inline void init()
{
  for(;q.size();q.pop());
  memset(dep,0,sizeof(dep));
  dep[s]=1;
  q.push(s);
  return;
}
inline bool bfs()
{
  register int i=0,u=0,v=0;
  init();
  for(;q.size();)
  {
    u=q.front();q.pop();
    for(i=hd[u];i;i=e[i].nxt)
    {
      if(e[i].w&&!dep[v=e[i].to])
      {
        dep[v]=dep[u]+1;
        if(v==t)
        {
          return true;
        }
        q.push(v);
      }
    }
  }
  return false;
}
inline void dinic()
{
  register int flw=0;
  for(;bfs();)
  {
    for(;flw=dfs(s,INF);ans+=flw);
  }
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