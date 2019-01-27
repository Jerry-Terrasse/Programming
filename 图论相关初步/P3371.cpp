#include<iostream>
#include<queue>
#define MAXN 10010
#define MAXM 500050
#define pr pair<int,int>
using namespace std;
struct edge
{
  int next,to,w;
}e[MAXM];
int head[MAXN],d[MAXN],n=0,m=0,cnt=1,s=0;
bool vis[MAXN];
priority_queue<pr,vector<pr >,greater<pr > >q;
void addedge(int,int,int);
int main()
{
  int i=0,j=0,u=0,v=0,w=0;
  ios::sync_with_stdio(0);
  cin>>n>>m>>s;
  for(;m;m--)
  {
  	cin>>u>>v>>w;
  	addedge(u,v,w);
  }
  for(i=1;i<=n;i++)
  {
  	d[i]=0x7fffffff;
  }
  d[s]=0;
  q.push(make_pair(0,s));
  for(;!q.empty();)
  {
  	i=q.top().second;
	q.pop();
  	if(vis[i])
  	{
  	  continue;
	}
	vis[i]=1;
  	for(j=head[i];j;j=e[j].next)
  	{
  	  if(e[j].w+d[i]<d[e[j].to])
  	  {
  	  	d[e[j].to]=e[j].w+d[i];
  	  	q.push(make_pair(d[e[j].to],e[j].to));
	  }
	}
  }
  for(i=1;i<=n;i++)
  {
  	cout<<d[i]<<' ';
  }
  cout<<endl;
  return 0;
}
void addedge(int u,int v,int w)
{
  e[cnt].next=head[u];
  e[cnt].to=v;
  e[cnt].w=w;
  head[u]=cnt;
  cnt++;
  return;
}
