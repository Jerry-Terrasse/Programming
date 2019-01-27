#include<iostream>
#define MAXN 100010
using namespace std;
struct edge
{
  int to,next;
}e[MAXN<<1];
int dfn[MAXN],low[MAXN],vis[MAXN],st[MAXN],head[MAXN],n=0,m=0,top=0,deep=0,cnt=0,ans=0;
inline void addedge(const int&,const int&);
inline void tarjan(int);
int main()
{
  register int i=0,u=0,v=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(;m--;)
  {
  	cin>>u>>v;
  	addedge(u,v);
  }
  for(i=1;i<=n;++i)
  {
  	if(!dfn[i])
  	{
  	  tarjan(i);
	}
  }
  cout<<ans<<endl;
  return 0;
}
void tarjan(int x)
{
  int i=0;
  dfn[x]=++deep;
  low[x]=deep;
  vis[x]=1;
  st[++top]=x;
  for(i=head[x];i;i=e[i].next)
  {
  	if(dfn[e[i].to])
  	{
  	  if(vis[e[i].to])
  	  {
  	    low[x]=min(low[x],low[e[i].to]);
	  }
	}
	else
	{
	  tarjan(e[i].to);
	  low[x]=min(low[x],low[e[i].to]);
	}
  }
  if(dfn[x]==low[x])
  {
  	for(i=0;st[top]!=x;)
  	{
  	  ++i;
  	  vis[st[top--]]=0;
	}
	--top;
	if(i)
	{
	  ++ans;
	}
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
