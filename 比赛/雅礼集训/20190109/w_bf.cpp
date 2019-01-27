#include<cstdio>
#include "memory.h"
#define MAXN 550
using namespace std;
struct edge
{
  int to,nxt;
}e[2][MAXN<<1];
int hd[2][MAXN],fa[2][MAXN],liv[2][MAXN],lim[2][MAXN],a[MAXN],f[MAXN],rt[2],ec[2],n=0,m=0,ans=0;
inline void read(int&);
void write(const int&);
void dfs1(const int&,const int&);
inline void addedge(const int&,const int&,const int&);
inline void work1();
bool judge(const int&,const int&);
int main()
{
  register int o=0,i=0,u=0,v=0;
  freopen("w.in","r",stdin);freopen("w.out","w",stdout);
  memset(lim,-1,sizeof(lim));
  read(n);read(rt[0]);read(rt[1]);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(o=0;o<2;++o)
  {
    for(i=1;i<n;++i)
    {
      read(u);read(v);
      addedge(o,u,v);
    }
  }
  for(o=0;o<2;++o)
  {
    read(m);
    for(;m--;)
    {
      read(i);read(lim[o][i]);
    }
  }
  for(o=0;o<2;++o)
  {
    dfs1(o,rt[o]);
  }
  //if(n<=18)
  {
    work1();
    write(ans);
    return 0;
  }
  return 0;
}
bool judge(const int &o,const int &x)
{
  register int i=0,v=0;
  liv[o][x]=f[x];
  for(i=hd[o][x];i;i=e[o][i].nxt)
  {
    v=e[o][i].to;
    if(v!=fa[o][x])
    {
      if(!judge(o,v))
      {
        return false;
      }
      liv[o][x]+=liv[o][v];
    }
  }
  if(lim[o][x]!=-1&&liv[o][x]!=lim[o][x])
  {
    return false;
  }
  else
  {
    return true;
  }
}
inline void work1()
{
  register int i=0,now=0,ret=0;
  for(now=0;now<(1<<n);++now)
  {
    memset(f,0,sizeof(f));
    ret=0;
    for(i=0;i<n;++i)
    {
      if(now>>i&1)
      {
        f[i+1]=1;
        ret+=a[i+1];
      }
    }
    if(ret>ans&&judge(0,rt[0])&&judge(1,rt[1]))
    {
      ans=ret;
    }
  }
  return;
}
void dfs1(const int &o,const int &x)
{
  register int i=0,v=0;
  for(i=hd[o][x];i;i=e[o][i].nxt)
  {
    v=e[o][i].to;
    if(v!=fa[o][x])
    {
      fa[o][v]=x;
      dfs1(o,v);
    }
  }
  return;
}
inline void addedge(const int &o,const int &u,const int &v)
{
  e[o][++ec[o]].to=v;
  e[o][ec[o]].nxt=hd[o][u];
  hd[o][u]=ec[o];
  e[o][++ec[o]].to=u;
  e[o][ec[o]].nxt=hd[o][v];
  hd[o][v]=ec[o];
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