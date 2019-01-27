#include<cstdio>
#define MAXN 5050
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct edge
{
  int to,nxt;
}e[MAXN<<1];
int hd[MAXN],dep[MAXN],fa[MAXN],qt[MAXN],qet[MAXN],ans[MAXN],ec=0,rt=0,n=0,m=0;
bool f[MAXN],a[MAXN];
inline void read(int&);
inline void read(bool&);
void write(const int&);
inline void addedge(const int&,const int&);
inline void work(const int&,const int&);
void dfs(const int&);
int main()
{
  register int i=0,j=0,u=0,v=0;
  freopen("bracket.in","r",stdin);freopen("bracket.out","w",stdout);
  read(n);
  for(i=1;i<n;++i)
  {
    read(u);read(v);
    addedge(u,v);
  }
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  read(m);
  for(i=1;i<=m;++i)
  {
    read(qt[i]);
    if(qt[i]<=n)
    {
      qet[qt[i]]=i;
    }
  }
  rt=min(37,n);
  dep[rt]=1;
  dfs(rt);
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=n;++j)
    {
      work(i,j);
    }
  }
  for(i=1;i<=m;++i)
  {
    write(ans[i]);
    putchar('\n');
  }
  return 0;
}
inline void dfs(const int &x)
{
  register int i=0,v=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if((v=e[i].to)!=fa[x])
    {
      fa[v]=x;
      dep[v]=dep[x]+1;
      dfs(v);
    }
  }
  return;
}
inline void work(const int &x,const int &y)
{
  register int i=0,u=x,v=y,len=0,cnt=0,ret=0;
  if(dep[u]>dep[v])
  {
    u^=v^=u^=v;
  }
  len=dep[v]-dep[u];
  for(i=1;i<=len;++i,v=fa[v]);
  for(;u!=v;len+=2,u=fa[u],v=fa[v]);
  for(i=1,u=x;u!=v;f[i]=a[u],++i,u=fa[u]);
  f[i]=a[u];
  for(i=++len,u=y;u!=v;f[i]=a[u],--i,u=fa[u]);
  for(i=1;i<=len;++i)
  {
    if(f[i])
    {
      if(!cnt)
      {
        ret=0;
        break;
      }
      if(!--cnt)
      {
        ++ret;
      }
    }
    else
    {
      ++cnt;
    }
  }
  if(cnt)
  {
    ret=0;
  }
  //printf("%d,%d:%d\n",x,y,ret);
  if(qet[ret])
  {
    ++ans[qet[ret]];
  }
  return;
}
inline void read(bool &x)
{
  register char c=getchar();
  for(;c!='('&c!=')';c=getchar());
  x=(c==')');
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