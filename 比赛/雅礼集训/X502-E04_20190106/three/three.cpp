#include<cstdio>
#include "memory.h"
#define MAXN 5050
using namespace std;
struct edge
{
  int to,nxt;
}e[MAXN<<1];
int f[MAXN][MAXN],fa[MAXN],dep[MAXN],hd[MAXN],ec=0,n=0,ans=0;
inline void read(int&);
void write(const int&);
inline void init();
inline void addedge(const int&,const int&);
void dfs(const int&);
inline int work(int,int);
int main()
{
  register int i=0,j=0,k=0,u=0,v=0;
  freopen("three.in","r",stdin);freopen("three.out","w",stdout);
  for(;read(n),n;)
  {
    init();
    for(i=1;i<n;++i)
    {
      read(u);read(v);
      addedge(u,v);
    }
    dep[1]=1;
    dfs(1);
    for(i=1;i<=n;++i)
    {
      for(j=i+1;j<=n;++j)
      {
        f[j][i]=f[i][j]=work(i,j);
      }
    }
    for(i=1;i<=n;++i)
    {
      for(j=i+1;j<=n;++j)
      {
        for(k=j+1;k<=n;++k)
        {
          if(f[i][j]==f[i][k]&&f[i][j]==f[j][k])
          {
            ++ans;
          }
        }
      }
    }
    write(ans);
    putchar('\n');
  }
  return 0;
}
inline int work(int u,int v)
{
  register int i=0,ret=0;
  if(dep[u]>dep[v])
  {
    u^=v^=u^=v;
  }
  ret=dep[v]-dep[u];
  for(i=1;i<=ret;v=fa[v],++i);
  for(;u!=v;ret+=2,u=fa[u],v=fa[v]);
  return ret;
}
void dfs(const int &x)
{
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(dep[e[i].to])
    {
      continue;
    }
    dep[e[i].to]=dep[x]+1;
    fa[e[i].to]=x;
    dfs(e[i].to);
  }
  return;
}
inline void addedge(const int &u,const int &v)
{
  e[++ec].to=v;
  e[ec].nxt=hd[u];
  hd[u]=ec;
  e[++ec].to=u;
  e[ec].nxt=hd[v];
  hd[v]=ec;
  return;
}
inline void init()
{
  ec=ans=0;
  memset(hd,0,sizeof(hd));
  memset(dep,0,sizeof(dep));
  memset(fa,0,sizeof(fa));
  memset(e,0,sizeof(e));
  memset(f,0,sizeof(f));
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}