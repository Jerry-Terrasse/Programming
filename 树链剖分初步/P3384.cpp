#include<iostream>
#define MAXN 100010
using namespace std;
struct node
{
  int val,l,r,mid,lazy;
  node *son,*daughter;
  int build(int,int);
  int add(int,int,int);
  int sum(int,int);
  inline void pushdown();
}mmp[MAXN<<2],*head,*mmtop=mmp;
struct ed
{
  int to,nxt;
}e[MAXN<<1];
int son[MAXN],id[MAXN],top[MAXN],dep[MAXN],fa[MAXN],siz[MAXN],hd[MAXN],w[MAXN],a[MAXN],cnt=0,n=0,m=0,r=0,H=0;
inline void added(const int&,const int&);
inline void add(int,int,const int&);
inline int sum(int,int);
void dfs1(const int&,const int&);
void dfs2(const int&,const int&);
int main()
{
  int i=0,j=0,u=0,v=0,o=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>r>>H;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  for(i=1;i<n;++i)
  {
    cin>>u>>v;
    added(u,v);
  }
  cnt=0;
  dfs1(r,0);
  dfs2(r,r);
  head=++mmtop;
  head->build(1,n+1);
  for(;m--;)
  {
    cin>>o>>i;
    switch(o)
    {
      case 1:
        cin>>j>>o;
        add(i,j,o%H);
        break;
      case 2:
        cin>>j;
        cout<<sum(i,j)<<endl;
        break;
      case 3:
        cin>>o;
        head->add(id[i],id[i]+siz[i],o%H);
        break;
      case 4:
        cout<<head->sum(id[i],id[i]+siz[i])<<endl;
        break;
    }
  }
  return 0;
}
inline void add(int u,int v,const int &k)
{
  for(;top[u]!=top[v];)
  {
    if(dep[top[u]]<dep[top[v]])
    {
      head->add(id[top[v]],id[v]+1,k);
      v=fa[top[v]];
    }
    else
    {
      head->add(id[top[u]],id[u]+1,k);
      u=fa[top[u]];
    }
  }
  if(id[u]<id[v])
  {
  	head->add(id[u],id[v]+1,k);
  }
  else
  {
  	head->add(id[v],id[u]+1,k);
  }
  return;
}
inline int sum(int u,int v)
{
  register int ans=0;
  for(;top[u]!=top[v];)
  {
    if(dep[top[u]]<dep[top[v]])
    {
      (ans+=head->sum(id[top[v]],id[v]+1))%=H;
      v=fa[top[v]];
    }
    else
    {
      (ans+=head->sum(id[top[u]],id[u]+1))%=H;
      u=fa[top[u]];
    }
  }
  if(id[u]<id[v])
  {
    (ans+=head->sum(id[u],id[v]+1))%=H;
  }
  else
  {
    (ans+=head->sum(id[v],id[u]+1))%=H;
  }
  return ans;
}
inline void node::pushdown()
{
  (son->lazy+=lazy)%=H;
  (son->val+=(mid-l)*lazy)%=H;
  (daughter->lazy+=lazy)%=H;
  (daughter->val+=(r-mid)*lazy)%=H;
  lazy=0;
  return;
}
int node::sum(int il,int ir)
{
  if(il==l&&ir==r)
  {
    return val%H;
  }
  if(lazy)
  {
    pushdown();
  }
  if(ir<=mid)
  {
    return son->sum(il,ir)%H;
  }
  if(mid<=il)
  {
    return daughter->sum(il,ir)%H;
  }
  return (son->sum(il,mid)+daughter->sum(mid,ir))%H;
}
int node::add(int il,int ir,int ik)
{
  if(il==l&&ir==r)
  {
    lazy+=ik;
    return (val+=(r-l)*ik)%=H;
  }
  if(lazy)
  {
    pushdown();
  }
  if(ir<=mid)
  {
    return (val=son->add(il,ir,ik)+daughter->val)%=H;
  }
  if(mid<=il)
  {
    return (val=son->val+daughter->add(il,ir,ik))%=H;
  }
  return (val=son->add(il,mid,ik)+daughter->add(mid,ir,ik))%=H;
}
int node::build(int il,int ir)
{
  l=il;r=ir;mid=l+r+1>>1;lazy=0;son=daughter=NULL;
  if(l+1==r)
  {
    return (val=w[l])%=H;
  }
  son=++mmtop;daughter=++mmtop;
  return (val=son->build(il,mid)+daughter->build(mid,ir))%=H;
}
void dfs2(const int &x,const int &tp)
{
  id[x]=++cnt;
  w[cnt]=a[x];
  top[x]=tp;
  if(son[x])
  {
    dfs2(son[x],tp);
  }
  register int i=0,v=0;
  for(i=hd[x];i;i=e[i].nxt)
  {
    v=e[i].to;
    if(v!=fa[x]&v!=son[x])
    {
      dfs2(v,v);
    }
  }
  return;
}
void dfs1(const int &x,const int &father)
{
  register int i=0;
  fa[x]=father;
  dep[x]=dep[father]+1;
  siz[x]=1;
  for(i=hd[x];i;i=e[i].nxt)
  {
    if(e[i].to!=father)
    {
      dfs1(e[i].to,x);
      siz[x]+=siz[e[i].to];
      if(siz[e[i].to]>siz[son[x]])
      {
        son[x]=e[i].to;
      }
    }
  }
  return;
}
inline void added(const int &u,const int &v)
{
  e[++cnt].to=v;
  e[cnt].nxt=hd[u];
  hd[u]=cnt;
  e[++cnt].to=u;
  e[cnt].nxt=hd[v];
  hd[v]=cnt;
  return;
}
