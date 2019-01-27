#include<iostream>
#include<queue>
#include "memory.h"
#define MAXN 16
#define MAXX 1010
using namespace std;
struct edge
{
  int to,next;
}e[MAXX*MAXX<<1];
int head[MAXX],ext[MAXX],dis[MAXX],a[MAXN],n=0,x=0,cnt=0,ans=0;
bool vis[MAXX];
priority_queue<pair<int,int> >q;
inline void addedge(const int&,const int&);
int main()
{
  int i=0,j=0;
  memset(dis,0x3f,sizeof(dis));
  cin>>x>>n;
  ++x;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  ext[1]=1;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j+a[i]<=x;++j)
  	{
  	  if(ext[j])
  	  {
  	    ext[j+a[i]]=1;
  	    addedge(j,j+a[i]);
	  }
	}
  }
  if(!ext[x])
  {
  	cout<<-1<<endl;
  	return 0;
  }
  for(q.push(make_pair(0,1)),dis[1]=0;q.size();q.pop())
  {
  	i=q.top().second;
  	if(vis[i])
  	{
  	  continue;
	}
	vis[i]=1;
  	for(j=head[i];j;j=e[j].next)
  	{
  	  if(dis[e[j].to]>dis[i]+1)
  	  {
  	    dis[e[j].to]=dis[i]+1;
  	    q.push(make_pair(-dis[e[j].to],e[j].to));
	  }
	}
  }
  for(i=2;i<=x;++i)
  {
  	ans=max(ans,dis[i]);
  }
  cout<<ans<<endl;
  return 0;
}
inline void addedge(const int &u,const int &v)
{
  e[++cnt].to=v;
  e[cnt].next=head[u];
  head[u]=cnt;
  return;
}
