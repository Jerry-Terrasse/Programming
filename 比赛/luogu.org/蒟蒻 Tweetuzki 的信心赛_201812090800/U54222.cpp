//U54222 Tweetuzki 爱序列
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
#define MAXN 100010
using namespace std;
struct edge
{
  int to,nxt;
}e[MAXN<<1];
int g[MAXN],f[MAXN],deg[MAXN],no[MAXN],hd[MAXN],a[MAXN],n=0,ec=0,ans=0;
queue<int>q;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
inline void topsort();
void dfs(const int&);
signed main()
{
  register int i=0,j=0,v=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  sort(a+1,a+n+1);
  n=unique(a+1,a+n+1)-a-1;
  for(i=1;i<=n;++i)
  {
    v=lower_bound(a+1,a+n+1,a[i]<<1)-a;
    if(a[v]==(a[i]<<1))
    {
      addedge(i,v);
    }
    if(!(a[i]%3))
    {
      v=lower_bound(a+1,a+n+1,a[i]/3)-a;
      if(a[v]==a[i]/3)
      {
        addedge(i,v);
      }
    }
  }
  topsort();
  for(i=1;i<=n;++i)
  {
    if(!f[no[i]])
    {
      dfs(no[i]);
    }
  }
  for(i=1;i<=n;++i)
  {
    if(f[ans]<f[i])
    {
      ans=i;
    }
  }
  write(f[ans]);
  putchar('\n');
  for(i=ans;i;i=g[i])
  {
    write(a[i]);
    putchar(' ');
  }
  return 0;
}
void dfs(const int &x)
{
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(!f[e[i].to])
    {
      dfs(e[i].to);
    }
    if(f[x]<f[e[i].to])
    {
      f[x]=f[e[i].to];
      g[x]=e[i].to;
    }
  }
  ++f[x];
  return;
}
inline void topsort()
{
  register int i=0,x=0;
  ec=0;
  for(i=1;i<=n;++i)
  {
    if(!deg[i])
    {
      q.push(i);
    }
  }
  for(;q.size();q.pop())
  {
    x=q.front();
    no[++ec]=x;
    for(i=hd[x];i;i=e[i].nxt)
    {
      if(!--deg[e[i].to])
      {
        q.push(e[i].to);
      }
    }
  }
  return;
}
inline void addedge(const int &u,const int &v)
{
  e[++ec].to=v;
  e[ec].nxt=hd[u];
  hd[u]=ec;
  ++deg[v];
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