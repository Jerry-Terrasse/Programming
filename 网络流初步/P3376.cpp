//P3376 【模板】网络最大流
//Edmonds-Karp
#include<iostream>
#include<queue>
#include "memory.h"
#define MAXN 100010
#define INF 0x7fffffff
#define register signed
using namespace std;
struct edge
{
  int frm,to,nxt,w;
}e[MAXN<<1];
int hd[MAXN],f[MAXN],uvs[MAXN],pre[MAXN],ec=1,n=0,m=0,s=0,t=0,ans=0;
queue<int>q;
inline void addedge(const int&,const int&,const int&);
inline void ek();
inline int bfs();
inline void init();
int main()
{
  register int i=0,u=0,v=0,w=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>s>>t;
  for(i=1;i<=m;++i)
  {
    cin>>u>>v>>w;
    addedge(u,v,w);
  }
  ek();
  cout<<ans<<endl;
  return 0;
}
inline void init()
{
  for(;q.size();q.pop());
  memset(uvs,-1,sizeof(uvs));
  f[s]=INF;
  q.push(s);
  uvs[s]=0;
  return;
}
inline int bfs()
{
  register int u=0,v=0,i=0;
  init();
  for(;q.size();q.pop())
  {
    u=q.front();
    for(i=hd[u];i;i=e[i].nxt)
    {
      v=e[i].to;
      if(uvs[v]&&e[i].w)
      {
        uvs[v]=0;
        f[v]=min(f[u],e[i].w);
        pre[v]=i;
        if(v==t)
        {
          return f[t];
        }
        q.push(v);
      }
    }
  }
  return 0;
}
inline void ek()
{
  register int i=0,dlt=0;
  for(;dlt=bfs();ans+=dlt)
  {
    for(i=pre[t];i;i=pre[e[i].frm])
    {
      e[i].w-=dlt;
      e[i^1].w+=dlt;
    }
  }
  return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++ec].frm=u;
  e[ec].to=v;
  e[ec].nxt=hd[u];
  e[ec].w=w;
  hd[u]=ec;
  e[++ec].frm=v;
  e[ec].to=u;
  e[ec].nxt=hd[v];
  e[ec].w=0;
  hd[v]=ec;
  return;
}