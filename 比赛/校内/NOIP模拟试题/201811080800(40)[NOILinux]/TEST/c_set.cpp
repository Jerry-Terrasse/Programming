#include<cstdio>
#include<set>
#include "memory.h"
#define MAXN 100010
#define MAXG 3030
using namespace std;
struct node
{
  int to,next;
}e[MAXN];
int head[MAXN],a[MAXN],d[MAXN],g[MAXN],cnt=0,n=0,m=0;
set<int>st[MAXN];
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
void dfs(const int&);
int main()
{
  register int i=0,j=0;
  memset(head,-1,sizeof(head));
  read(n);read(m);
  for(i=1;i<n;++i)
  {
    read(a[i]);
    addedge(a[i],i);
  }
  for(i=1;i<=m;++i)
  {
    read(g[i]);read(d[i]);
    st[g[i]].insert(d[i]);
  }
  dfs(0);
  for(i=0;i<n;++i)
  {
    write(st[i].size());
    putchar('\n');
  }
  return 0;
}
void dfs(const int &x)
{
  register int i=0;
  for(i=head[x];i!=-1;i=e[i].next)
  {
    dfs(e[i].to);
    st[x].insert(st[e[i].to].begin(),st[e[i].to].end());
  }
  return;
}
inline void addedge(const int &u,const int &v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
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
