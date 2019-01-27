#include<iostream>
#include "memory.h"
#define MAXN 25
using namespace std;
int d[MAXN],ans=0,n=0;
bool e[MAXN][MAXN],vis[MAXN];
int ak(int);
int main()
{
  int i=0,u=0,v=0,bo=0;
  for(cin>>n>>i;i;i--)
  {
  	cin>>u>>v;
  	e[u-1][v-1]=e[v-1][u-1]=1;
  }
  for(ans=1;;ans++)
  {
    memset(d,-1,sizeof(d));
  	memset(vis,0,sizeof(vis));
  	//cout<<ans<<endl;
	for(i=0;i<n;i++)
	{
	  bo=ak((i+2)%n);
	  if(bo==-1)
	  {
	  	break;
	  }
	}
	if(bo!=-1)
	{
	  break;
	}
  }
  cout<<ans<<endl;
  return 0;
}
int ak(int x)
{
  if(d[x]!=-1)
  {
  	return d[x];
  }
  vis[x]=1;
  int i=0,bo=0;
  bool use[MAXN];
  memset(use,0,sizeof(use));
  for(;i<n;i++)
  {
  	if(e[x][i] && !vis[i])
  	{
  	  bo=ak(i);
  	  if(bo==-1)
  	  {
  	  	break;
	  }
	  else
	  {
	  	use[bo]=1;
	  }
	}
  }
  if(bo==-1)
  {
  	return -1;
  }
  for(i=0;i<=ans;i++)
  {
  	if(!use[i])
  	{
  	  break;
	}
  }
  if(i==ans)
  {
  	return -1;
  }
  else
  {
  	vis[x]=0;
  	d[x]=i;
  	return i;
  }
}
