//P3381 【模板】最小费用最大流
//EK
#include<iostream>
#include<queue>
#include "memory.h"
#define MAXN 5050
#define MAXM 50050
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
  int frm,to,nxt,w,c;
}e[MAXM<<1];
int hd[MAXN],pre[MAXN],dis[MAXN],uvs[MAXN],ec=1,n=0,m=0,s=0,t=0,ans=0,cst=0;
queue<int>q;
inline void addedge(const int&,const int&,const int&,const int&);
inline void ek();
inline void init();
int main()
{
  register int i=0,u=0,v=0,w=0,c=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>s>>t;
  for(i=1;i<=m;++i)
  {
    cin>>u>>v>>w>>c;
    addedge(u,v,w,c);
  }
  ek();
  cout<<ans<<' '<<cst<<endl;
  return 0;
}
inline void init()
{
  memset(uvs,0xff,sizeof(uvs));
  memset(dis,0x3f,sizeof(dis));
  q.push(s);
  dis[s]=0;
  uvs[s]=0;
  return;
}
inline bool spfa()
{
  register int i=0,u=0,v=0;
  for(init();q.size();)
  {
    u=q.front();q.pop();uvs[u]=-1;
    for(i=hd[u];i;i=e[i].nxt)
    {
      v=e[i].to;
      if(e[i].w&&dis[v]>dis[u]+e[i].c)
      {
        dis[v]=dis[u]+e[i].c;
        pre[v]=i;
        if(uvs[v])
        {
          q.push(v);
          uvs[v]=0;
        }
      }
    }
  }
  return dis[t]!=INF;
}
inline void ek()
{
  register int i=0,dlt=0;
  for(;spfa();ans+=dlt,cst+=dlt*dis[t])
  {
    for(i=pre[t],dlt=INF;i;i=pre[e[i].frm])
    {
      if(dlt>e[i].w)
      {
        dlt=e[i].w;
      }
    }
    for(i=pre[t];i;i=pre[e[i].frm])
    {
      e[i].w-=dlt;
      e[i^1].w+=dlt;
    }
  }
  return;
}
inline void addedge(const int &u,const int &v,const int &w,const int &c)
{
  e[++ec].to=v;
  e[ec].frm=u;
  e[ec].nxt=hd[u];
  e[ec].w=w;
  e[ec].c=c;
  hd[u]=ec;
  e[++ec].to=u;
  e[ec].frm=v;
  e[ec].nxt=hd[v];
  e[ec].w=0;
  e[ec].c=-c;
  hd[v]=ec;
  return;
}