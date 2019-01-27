#include<cstdio>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct edge
{
  int to,w,nxt;
}e[MAXN<<1];
struct st
{
  int l,r,mid,val;
  st *son,*daughter;
  int build(const int&,const int&);
  int change(const int&,const int&);
  int query(const int&,const int&);
}mmp[MAXN<<2],*mtp=mmp,*head;
int id[MAXN],top[MAXN],dep[MAXN],siz[MAXN],son[MAXN],fa[MAXN],hd[MAXN],w[MAXN],a[MAXN],ec=0,dc=0,n=0;
inline void read(int&);
void write(const int&);
inline void addedge();
void dfs(const int&);
void dfs(const int&,const int&);
inline int reads();
inline int query(int,int);
inline int max(const int&,const int&);
int main()
{
  register int i=0,x=0,y=0;
  read(n);
  fill(siz+1,siz+n+1,1);
  head=++mtp;
  for(i=1;i<n;++i)
  {
    addedge();
  }
  dep[1]=1;
  dfs(1);
  dfs(1,1);
  head->build(0,n);
  for(;i=reads();)
  {
    read(x);read(y);
    if(i==1)
    {
      if(dep[e[x<<1].to]<dep[e[(x<<1)-1].to])
      {
        head->change(id[e[(x<<1)-1].to],y);
      }
      else
      {
        head->change(id[e[x<<1].to],y);
      }
    }
    else
    {
      write(query(x,y));
      putchar('\n');
    }
  }
  return 0;
}
inline int query(int u,int v)
{
  register int ans=0;
  for(;top[u]!=top[v];)
  {
    if(dep[top[u]]<dep[top[v]])
    {
      ans=max(ans,head->query(id[top[v]]-1,id[v]));
      v=fa[top[v]];
    }
    else
    {
      ans=max(ans,head->query(id[top[u]]-1,id[u]));
      u=fa[top[u]];
    }
  }
  if(u==v)
  {
    return ans;
  }
  if(dep[u]<dep[v])
  {
    ans=max(ans,head->query(id[u],id[v]));
  }
  else
  {
    ans=max(ans,head->query(id[v],id[u]));
  }
  return ans;
}
void dfs(const int &x,const int &itp)
{
  top[x]=itp;
  w[id[x]=++dc]=a[x];
  if(son[x])
  {
    dfs(son[x],itp);
  }
  else
  {
    return;
  }
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(e[i].to!=fa[x]&&e[i].to!=son[x])
    {
      dfs(e[i].to,e[i].to);
    }
  }
  return;
}
void dfs(const int &x)
{
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(e[i].to!=fa[x])
    {
      fa[e[i].to]=x;
      a[e[i].to]=e[i].w;
      dep[e[i].to]=dep[x]+1;
      dfs(e[i].to);
      siz[x]+=siz[e[i].to];
      if(siz[e[i].to]>siz[son[x]])
      {
        son[x]=e[i].to;
      }
    }
  }
  return;
}
inline int max(const int &x,const int &y)
{
  return x<y?y:x;
}
int st::query(const int &il,const int &ir)
{
  if(il==l&&ir==r)
  {
    return val;
  }
  if(ir<=mid)
  {
    return son->query(il,ir);
  }
  if(il>=mid)
  {
    return daughter->query(il,ir);
  }
  return max(son->query(il,mid),daughter->query(mid,ir));
}
int st::change(const int &x,const int &k)
{
  if(son)
  {
    if(mid<x)
    {
      return val=max(son->val,daughter->change(x,k));
    }
    else
    {
      return val=max(son->change(x,k),daughter->val);
    }
  }
  else
  {
    return val=k;
  }
}
int st::build(const int &il,const int &ir)
{
  l=il;r=ir;mid=l+r+1>>1;son=daughter=NULL;
  if(l+1==r)
  {
    return val=w[r];
  }
  son=++mtp;daughter=++mtp;
  return val=max(son->build(l,mid),daughter->build(mid,r));
}
inline int reads()
{
  register char c=getchar();
  for(;c<'A'|c>'Z';c=getchar());
  if(c=='D')
  {
    return 0;
  }
  else
  {
    return 1+(c=='Q');
  }
}
inline void addedge()
{
  register int u=0,v=0,w=0;
  read(u);read(v);read(w);
  e[++ec].to=v;e[ec].w=w;e[ec].nxt=hd[u];hd[u]=ec;
  e[++ec].to=u;e[ec].w=w;e[ec].nxt=hd[v];hd[v]=ec;
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