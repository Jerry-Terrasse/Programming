#include<iostream>
#include "memory.h"
#include<vector>
#define MAXN 10010
using namespace std;
int hbd[MAXN],vis[MAXN],n=0,m=0,ans=0;//hbd->has_been_dfsed
vector<int>e[MAXN];
void dfs(int);
int main()
{
  int i=0,j=0,k=0;
  for(cin>>n>>m;i<m;i++)
  {
  	cin>>j>>k;
  	e[j].push_back(k);
  }
  for(i=1;i<=n;i++)
  {
  	if(!hbd[i])
  	{
  	  memset(vis,0,sizeof(vis));
	  dfs(i);
	}
  }
  cout<<ans<<endl;
  return 0;
}
void dfs(int x)
{
  int i=0;
  hbd[x]=1;
  vis[x]=1;
  for(;i<e[x].size();i++)
  {
	if(vis[e[x][i]])
  	{
	  ans++;
	  //cout<<x<<"->"<<e[x][i]<<endl;
	}
	else
	{
	  if(!hbd[i])
	  {
	  	dfs(e[x][i]);
	  }
	}
  }
  vis[x]=0;
  return;
}
