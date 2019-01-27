#include<iostream>
#include<queue>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include "memory.h"
#define ld long double
#define MAXN 32
#define ok(x,y) ((x>=1)&&(y>=1)&&(x<=n)&&(y<=m))
#define sqr(x) ((x)*(x))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};
struct edge
{
  int tox,toy,w,next;
}e[MAXN*MAXN<<2];
ld ans=0;
int dis[MAXN][MAXN],vis[MAXN][MAXN],head[MAXN][MAXN],a[MAXN][MAXN],n=0,m=0,t=0,cnt=0;
inline void addedge(const int&,const int&,const int&,const int&,const int&);
inline void dijkstra(int,int);
int main()
{
  int i=1,j=0,k=0,l=0,o=0,p=0;
  for(cin>>n>>m>>t;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(;a[i][j]<'0'||a[i][j]>'1';a[i][j]=getchar());
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(k=0;k<4;++k)
  	  {
  	    if(ok(i+dx[k],j+dy[k]))
  	    {
  	      addedge(i,j,i+dx[k],j+dy[k],(a[i][j]=='1')+(a[i+dx[k]][j+dy[k]]=='1'));
		}
	  }
	}
  }
  /*for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  for(k=1;k<=n;++k)
  	  {
  	    for(l=1;l<=n;++l)
  	    {
  	      for(o=1;o<=n;++o)
  	      {
  	        for(p=1;p<=n;++p)
  	        {
  	          dis[i][j][o][p]=min(dis[i][j][o][p],dis[i][j][k][l]+dis[k][l][o][p]);
			}
		  }
		}
	  }
	}
  }*/
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  dijkstra(i,j);
	  for(k=1;k<=n;++k)
  	  {
  	    for(l=1;l<=n;++l)
  	    {
  	      if(dis[k][l]<=t)
  	      {
  	        ans=max(ans,sqr(i-k)+sqr(j-l));
		  }
		}
	  }
	}
  }
  cout<<fixed<<setprecision(6)<<sqrt(ans)<<endl;
  return 0;
}
void dijkstra(int x,int y)
{
  int i=0,j=0,u=0,v=0;
  memset(dis,0x3f,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis[x][y]=0;
  priority_queue<pair<int,pair<int,int> > >q;
  for(q.push(make_pair(0,make_pair(x,y)));q.size();)
  {
	u=q.top().second.first;
  	v=q.top().second.second;
  	q.pop();
  	if(vis[u][v])
  	{
  	  continue;
	}
  	vis[u][v]=true;
  	for(i=head[u][v];i;i=e[i].next)
  	{
  	  if(dis[e[i].tox][e[i].toy]>dis[u][v]+e[i].w)
  	  {
  	    dis[e[i].tox][e[i].toy]=dis[u][v]+e[i].w;
  	    q.push(make_pair(-dis[e[i].tox][e[i].toy],make_pair(e[i].tox,e[i].toy)));
	  }
	}
  }
  return;
}
/*inline void addedge(const int &ux,const int &uy,const int &vx,const int &vy,const int &w)
{
  dis[ux][uy][vx][vy]=w;
  //cout<<ux<<' '<<uy<<' '<<vx<<' '<<vy<<" = "<<w<<endl;
  return;
}*/
inline void addedge(const int &ux,const int &uy,const int &vx,const int &vy,const int &w)
{
  e[++cnt].tox=vx;
  e[cnt].toy=vy;
  e[cnt].w=w;
  e[cnt].next=head[ux][uy];
  head[ux][uy]=cnt;
  return;
}
