#include<iostream>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define ll long long
#define MAXN 1010
#define FNI 0x80808080
#define rrr(x) ((int)rand()*rand()%(x))
using namespace std;
struct edge
{
  int to,w,next,emm;
}e[MAXN<<1];
int dis[MAXN][MAXN],head[MAXN],n=0,ban=0,cnt=0,maxd=0;
ll ans=0;
inline void addedge(const int&,const int&,const int&);
int main()
{
  int i=0,j=0,k=0,u=0,v=0,w=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<n;++i)
  {
  	cin>>u>>v>>w;
  	addedge(u,v,w);
  }
  for(ban=1;ban<n;++ban)
  {
	memset(dis,0x80,sizeof(dis));
	for(i=1;i<=cnt;++i)
	{
	  dis[e[i].emm][e[i].to]=e[i].w;
	}
	dis[e[ban<<1].emm][e[ban<<1].to]=dis[e[ban<<1].to][e[ban<<1].emm]=FNI;
	maxd=0;
	for(i=1;i<=n;++i)
	{
	  for(j=1;j<=n;++j)
	  {
	  	for(k=1;k<=n;++k)
	  	{
	  	  if(dis[i][k]!=FNI&&dis[k][j]!=FNI&&dis[i][j]<dis[i][k]+dis[k][j])
	  	  {
	  	    dis[i][j]=dis[i][k]+dis[k][j];
		  }
		}
		maxd=max(maxd,dis[i][j]);
	  }
	}
	ans+=maxd;
  }
  cout<<ans<<endl;
  return 0;
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
