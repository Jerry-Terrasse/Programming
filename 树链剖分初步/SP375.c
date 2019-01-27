#include "stdio.h"
#include "memory.h"
#define MAXN 10010
#define register signed
struct edge
{
  int to,w,nxt;
}e[MAXN<<1];
struct st
{
  int l,r,mid,val;
  struct st *son,*daughter;
}mmp[MAXN<<2],*mtp=mmp,*head;
int id[MAXN],top[MAXN],dep[MAXN],siz[MAXN],son[MAXN],fa[MAXN],hd[MAXN],w[MAXN],a[MAXN],ec=0,dc=0,n=0,t=0,tc=0;
char cmd[7];
// void read(int&);
void write(int);
 void addedge();
void dfs1(int);
void dfs2(int,int);
 int reads();
 int Query(int,int);
 int max(int,int);
  int build(struct st*,int,int);
  int change(struct st*,int,int);
  int query(struct st*,int,int);
int main()
{
  register int i=0,x=0,y=0;
  if(tc==0)
  {
    scanf("%d",&t);
  }
  else
  {
    memset(mmp,0,sizeof(mmp));
    memset(e,0,sizeof(e));
    memset(hd,0,sizeof(hd));
    memset(id,0,sizeof(id));
    memset(top,0,sizeof(top));
    memset(dep,0,sizeof(dep));
    memset(siz,0,sizeof(siz));
    memset(son,0,sizeof(son));
    memset(fa,0,sizeof(fa));
    memset(w,0,sizeof(w));
    memset(a,0,sizeof(a));
    mtp=mmp;head=NULL;
    ec=dc=n=0;
  }
  ++tc;
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  {
    siz[i]=1;
  }
  head=++mtp;
  for(i=1;i<n;++i)
  {
    addedge();
  }
  dep[1]=1;
  dfs1(1);
  dfs2(1,1);
  build(head,0,n);
  for(;;)
  {
    scanf("%s",cmd);
    if(cmd[0]=='D')
    {
      break;
    }
    if(cmd[0]=='Q')
    {
      i=2;
    }
    else
    {
      i=1;
    }
    scanf("%d%d",&x,&y);
    if(i==1)
    {
      if(dep[e[x<<1].to]<dep[e[(x<<1)-1].to])
      {
        change(head,id[e[(x<<1)-1].to],y);
      }
      else
      {
        change(head,id[e[x<<1].to],y);
      }
    }
    else
    {
      write(Query(x,y));
      putchar('\n');
    }
  }
  if(tc==t)
  {
    return 0;
  }
  main();
}
 int Query(int u,int v)
{
  register int ans=0;
  for(;top[u]!=top[v];)
  {
    if(dep[top[u]]<dep[top[v]])
    {
      ans=max(ans,query(head,id[top[v]]-1,id[v]));
      v=fa[top[v]];
    }
    else
    {
      ans=max(ans,query(head,id[top[u]]-1,id[u]));
      u=fa[top[u]];
    }
  }
  if(u==v)
  {
    return ans;
  }
  if(dep[u]<dep[v])
  {
    ans=max(ans,query(head,id[u],id[v]));
  }
  else
  {
    ans=max(ans,query(head,id[v],id[u]));
  }
  return ans;
}
void dfs2(int x,int itp)
{
  top[x]=itp;
  w[id[x]=++dc]=a[x];
  if(son[x])
  {
    dfs2(son[x],itp);
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
      dfs2(e[i].to,e[i].to);
    }
  }
  return;
}
void dfs1(int x)
{
  register int i=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(e[i].to!=fa[x])
    {
      fa[e[i].to]=x;
      a[e[i].to]=e[i].w;
      dep[e[i].to]=dep[x]+1;
      dfs1(e[i].to);
      siz[x]+=siz[e[i].to];
      if(siz[e[i].to]>siz[son[x]])
      {
        son[x]=e[i].to;
      }
    }
  }
  return;
}
 int max(int x,int y)
{
  return x<y?y:x;
}
int query(struct st *ts,int il,int ir)
{
  if(il==ts->l&&ir==ts->r)
  {
    return ts->val;
  }
  if(ir<=ts->mid)
  {
    return query(ts->son,il,ir);
  }
  if(il>=ts->mid)
  {
    return query(ts->daughter,il,ir);
  }
  return max(query(ts->son,il,ts->mid),query(ts->daughter,ts->mid,ir));
}
int change(struct st *ts,int x,int k)
{
  if(ts->son)
  {
    if(ts->mid<x)
    {
      return ts->val=max(ts->son->val,change(ts->daughter,x,k));
    }
    else
    {
      return ts->val=max(change(ts->son,x,k),ts->daughter->val);
    }
  }
  else
  {
    return ts->val=k;
  }
}
int build(struct st *ts,int il,int ir)
{
  ts->l=il;ts->r=ir;ts->mid=il+ir+1>>1;ts->son=ts->daughter=NULL;
  if(il+1==ir)
  {
    return ts->val=w[ir];
  }
  ts->son=++mtp;ts->daughter=++mtp;
  return ts->val=max(build(ts->son,ts->l,ts->mid),build(ts->daughter,ts->mid,ts->r));
}
 int reads()
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
 void addedge()
{
  register int u=0,v=0,w=0;
  scanf("%d%d%d",&u,&v,&w);
  e[++ec].to=v;e[ec].w=w;e[ec].nxt=hd[u];hd[u]=ec;
  e[++ec].to=u;e[ec].w=w;e[ec].nxt=hd[v];hd[v]=ec;
  return;
}
void write(int x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
/* void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}*/