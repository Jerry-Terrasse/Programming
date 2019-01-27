#include<iostream>
#include "memory.h"
#define MAXN 25
using namespace std;
bool e[MAXN][MAXN];
int d[MAXN],n=0;
void dfs(int);
int main()
{
  int i=0,u=0,v=0;
  for(cin>>n>>i;i;i--)
  {
  	cin>>u>>v;
    e[u][v]=e[v][u]=1;
  }
  dfs(1);
  return 0;
}
void dfs(int x)
{
  if(x==n+1)
  {
  	int ans=0;
	for(int kk=0;kk<n;kk++)
  	{
  	  if(ans<d[kk])
  	  ans=d[kk];
	}
	cout<<ans+1<<endl;
	exit(0);
  }
  int use[MAXN],i=0;
  memset(use,0,sizeof(use));
  for(i=0;i<n;i++)
  {
  	if(e[x][i] && d[i]!=-1)
  	{
  	  use[d[i]]=1;
	}
  }
  for(i=0;i<x;i++)
  {
  	if(!use[i])
  	{
  	  d[x]=i;
  	  dfs(x+1);
  	  d[x]=-1;
	}
  }
  return;
}
