#include<cstdio>
#define MAXN 100010
using namespace std;
struct edge
{
  int to,nxt,w;
}e[MAXN<<1];
struct trie
{
  //int cnt;
  trie *son[2];
  inline trie();
}mmp[MAXN<<5],*mtp=mmp,*rt=mmp;
int hd[MAXN],d[MAXN],a[MAXN],n=0,ec=0,ans=0;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&,const int&);
void dfs(const int&,const int&);
inline void build(const int &x);
inline void work(const int &x);
int main()
{
  register int i=0,u=0,v=0,w=0;
  read(n);
  for(i=1;i<n;++i)
  {
    read(u);read(v);read(w);
    addedge(u,v,w);
  }
  dfs(1,0);
  build(0);
  for(i=2;i<=n;++i)
  {
    work(d[i]);
    build(d[i]);
  }
  write(ans);
  return 0;
}
inline void work(const int &x)
{
  register int i=0,ret=0;
  register trie *p=rt;
  for(i=32;i--;)
  {
    ret<<=1;
    if(p->son[x>>i&1^1])
    {
      p=p->son[x>>i&1^1];
      ret|=1;
    }
    else
    {
      p=p->son[x>>i&1];
    }
  }
  if(ans<ret)
  {
    ans=ret;
  }
  return;
}
inline void build(const int &x)
{
  register trie *p=rt;
  register int i=0;
  for(i=32;i--;)
  {
    if(p->son[x>>i&1])
    {
      p=p->son[x>>i&1];
    }
    else
    {
      p=p->son[x>>i&1]=++mtp;
    }
  }
  //++p->cnt;
  return;
}
inline trie::trie()
{
  son[0]=son[1]=NULL;
  //cnt=0;
  return;
}
void dfs(const int &x,const int &fa)
{
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(e[i].to!=fa)
    {
      d[e[i].to]=d[x]^e[i].w;
      dfs(e[i].to,x);
    }
  }
  return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++ec].to=v;
  e[ec].w=w;
  e[ec].nxt=hd[u];
  hd[u]=ec;
  e[++ec].to=u;
  e[ec].w=w;
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