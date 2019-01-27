#include<iostream>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define ll long long
#define MAXN 1000010
#define FNI 0x80808080
#define rrr(x) ((int)rand()*rand()%(x))
using namespace std;
struct pr
{
  int a,b;
  inline pr();
};
struct edge
{
  int to,w,next,emm;
}e[MAXN<<1];
int head[MAXN],n=0,ban=0,cnt=0;
ll ans=0;
inline void addedge(const int&,const int&,const int&);
pr dfs(const int&,const int&);
int main()
{
  register int i=0,u=0,v=0,w=0;
  freopen("cc.in","r",stdin);freopen("cc.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<n;++i)
  {
  	cin>>u>>v>>w;
  	addedge(u,v,w);
  }
  for(ban=1;ban<n;++ban)
  {
	ans+=max(dfs(e[ban<<1].to,0).b,dfs(e[ban<<1].emm,0).b);
  }
  cout<<ans<<endl;
  return 0;
}
pr dfs(const int &x,const int &fa)
{
  register int i=0,f=0,g=0;
  pr ans,now;
  for(i=head[x];i;i=e[i].next)
  {
  	if((i+1>>1)==ban||e[i].to==fa)
  	{
  	  continue;
	}
	now=dfs(e[i].to,x);
	if(g<now.a+e[i].w)
	{
	  if(f>=now.a+e[i].w)
	  {
	  	g=now.a+e[i].w;
	  }
	  else
	  {
	  	g=f;
	  	f=now.a+e[i].w;
	  }
	}
	if(ans.a<now.a+e[i].w)
	{
	  ans.a=now.a+e[i].w;
	}
	if(ans.b<now.b)
	{
	  ans.b=now.b;
	}
  }
  if(ans.b<f+g)
  {
  	ans.b=f+g;
  }
  return ans;
}
inline pr::pr()
{
  a=b=0;
  return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++cnt].to=v;
  e[cnt].emm=u;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].emm=v;
  e[cnt].w=w;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}
