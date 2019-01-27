//Day2_two.cpp
#include<cstdio>
#include<bitset>
#include "memory.h"
#define MAXN 1010
//#define MAXN 200020
using namespace std;
struct edge
{
  int to,nxt;
}e[2][MAXN<<1];
int hd[2][MAXN],fa[2][MAXN],ext[2][MAXN],a[2][MAXN],st[2][MAXN],sc[2],n=0;
bitset<MAXN>son[2][MAXN];
inline void read(int&);
void write(const int&);
inline void addedge(const bool&,const int&,const int&);
void dfs(const bool&,const int&);
inline void work();
int main()
{
  register int i=0,j=0;
  freopen("two.in","r",stdin);freopen("two.out","w",stdout);
  memset(ext,-1,sizeof(ext));
  read(n);
  for(i=0;i<2;++i)
  {
    for(j=1;j<n;++j)
    {
      read(a[i][j]);
      addedge(i,j,a[i][j]);
    }
  }
  read(*sc);
  dfs(0,1);
  dfs(1,1);
  work();
  return 0;
}
inline void work()
{
  register int i=0,j=0,u=0,v=0;
  register bool o=0,p=1,bo=false;
  st[0][1]=*sc;ext[0][*sc]=0;*sc=1;
  for(;sc[o];p=o,o^=1)
  {
    if(o)
    {
      puts("Red");
    }
    else
    {
      puts("Blue");
    }
    for(i=1;i<=sc[o];++i)
    {
      register int &buf=st[o][i];
      write(buf);
      if(fa[o][a[o][buf]]==buf+1)
      {
        buf=a[o][buf];
      }
      else
      {
        ++buf;
      }
      putchar(' ');
    }
    putchar('\n');
    for(i=1,sc[p]=0;i<n;++i)
    {
      if(ext[p][i])
      {
        for(u=i+1,v=a[p][i],bo=false,j=1;j<=sc[o];++j)
        {
          if(son[o][st[o][j]][u]^son[o][st[o][j]][v])
          {
            bo=true;
            break;
          }
        }
        if(bo)
        {
          st[p][++sc[p]]=i;
          ext[p][i]=0;
        }
      }
    }
  }
  return;
}
inline void dfs(const bool &o,const int &x)
{
  register int i=0,v=0;
  son[o][x][x]=1;
  for(i=hd[o][x];i;i=e[o][i].nxt)
  {
    if((v=e[o][i].to)!=fa[o][x])
    {
      //dep[o][e[o][i].to]=dep[o][x]+1;
      fa[o][v]=x;
      dfs(o,v);
      son[o][x]|=son[o][v];
    }
  }
  return;
}
inline void addedge(const bool &o,const int &u,const int &v)
{
  e[o][(u<<1)-1].to=v;
  e[o][(u<<1)-1].nxt=hd[o][u+1];
  hd[o][u+1]=(u<<1)-1;
  e[o][u<<1].to=u+1;
  e[o][u<<1].nxt=hd[o][v];
  hd[o][v]=u<<1;
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