#include<iostream>
#include<queue>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define MAXN 2020
#define MAXM 3030
using namespace std;
struct edge
{
  int to,nxt,w;
}e[MAXM<<1];
int cnt[MAXN],dis[MAXN],vis[MAXN],hd[MAXN],t=0,ec=0,n=0,m=0;
void input();
bool spfa();
void addedge(int,int,int);
int main()
{
  //freopen("P3385#1.in","r",stdin);
  //ios::sync_with_stdio(false);cin.tie(0);
  srand(time(NULL));
  cin>>t;
  for(;t--;)
  {
    input();
    if(spfa())
    {
      cout<<"YE5"<<endl;
    }
    else
    {
      cout<<"N0"<<endl;
    }
  }
  return 0;
}
bool spfa()
{
  int x=0,v=0,i=0;
  deque<int>q;
  q.push_back(1);
  vis[1]=1;dis[1]=0;
  for(;q.size();)
  {
    x=q.front();q.pop_front();vis[x]=0;
    //cout<<"pulling:"<<x<<endl;
    if(++cnt[x]==n)
    {
      return true;
    }
    for(i=hd[x];i;i=e[i].nxt)
    {
      v=e[i].to;
      if(dis[v]>dis[x]+e[i].w)
      {
        dis[v]=dis[x]+e[i].w;
        if(!vis[v])
        {
          if(rand()%2)
          {
            q.push_back(v);
          }
          else
          {
            q.push_front(v);
          }
          vis[v]=1;
        }
      }
    }
  }
  return false;
}
void addedge(int u,int v,int w)
{
  e[++ec].to=v;
  e[ec].nxt=hd[u];
  e[ec].w=w;
  hd[u]=ec;
  if(w<0)
  {
    return;
  }
  e[++ec].to=u;
  e[ec].nxt=hd[v];
  e[ec].w=w;
  hd[v]=ec;
  return;
}
void input()
{
  int u=0,v=0,w=0;
  memset(e,0,sizeof(e));
  memset(hd,0,sizeof(hd));
  memset(dis,0x3f,sizeof(dis));
  memset(vis,0,sizeof(vis));
  memset(cnt,0,sizeof(cnt));
  ec=0;
  cin>>n>>m;
  for(;m--;)
  {
    cin>>u>>v>>w;
    addedge(u,v,w);
  }
  return;
}