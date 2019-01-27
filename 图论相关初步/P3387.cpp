#include<iostream>
#include<cstdio>
#include<stack>
#include "memory.h"
#define MAXM 100010
#define MAXN 10010
//#define register signed
using namespace std;
struct edge
{
  int to,next;
}e[MAXM];
int u[MAXM],v[MAXM],head[MAXN],use[MAXN],low[MAXN],dfn[MAXN],f[MAXN],clr[MAXN],sum[MAXN],a[MAXN],n=0,m=0,cnt=0,tot=0,ans=0;
stack<int>st;
void tarjan(int);
inline void addedge(const int&,const int&);
inline void init();
void dfs(const int&);
int main()
{
  register int i=0;
  //freopen("P3387#2.in","r",stdin);
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=m;++i)
  {
  	cin>>u[i]>>v[i];
  	addedge(u[i],v[i]);
  }
  for(i=1,cnt=0;i<=n;++i)
  {
  	if(!dfn[i])
  	{
  	  tarjan(i);
	}
  }
  init();
  for(i=1;i<=m;++i)
  {
  	if(clr[u[i]]!=clr[v[i]])
  	{
  	  addedge(clr[u[i]],clr[v[i]]);
	}
  }
  for(i=1;i<=tot;++i)
  {
  	if(!f[i])dfs(i);
  	ans=max(ans,f[i]);
  }
  cout<<ans<<endl;
  return 0;
}
void dfs(const int &x)
{
  if(f[x])
  {
  	return;
  }
  register int i=0;
  f[x]=0;
  for(i=head[x];i;i=e[i].next)
  {
  	if(!f[e[i].to])dfs(e[i].to);
    f[x]=max(f[x],f[e[i].to]);
  }
  f[x]+=sum[x];
  return;
}
inline void init()
{
  cnt=0;
  memset(head,0,sizeof(head));
  memset(e,0,sizeof(e));
  //memset(use,0,sizeof(use));
  return;
}
void tarjan(int u)
{
  register int i=0;
  dfn[u]=low[u]=++cnt;
  use[u]=1;
  st.push(u);
  for(i=head[u];i;i=e[i].next)
  {
  	if(dfn[e[i].to])
  	{
  	  if(use[e[i].to])
  	  {
  	    low[u]=min(low[u],dfn[e[i].to]);
	  }
	}
	else
	{
	  tarjan(e[i].to);
	  low[u]=min(low[u],low[e[i].to]);
	}
  }
  if(low[u]==dfn[u])
  {
  	for(++tot;st.top()!=u;st.pop())
  	{
  	  clr[st.top()]=tot;
  	  use[st.top()]=0;
  	  sum[tot]+=a[st.top()];
	}
	clr[u]=tot;
	use[u]=0;
	sum[tot]+=a[u];
	st.pop();
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
