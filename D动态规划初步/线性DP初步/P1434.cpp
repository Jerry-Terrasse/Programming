#include<iostream>
#include "memory.h"
#define MAXN 110
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int a[MAXN][MAXN],f[MAXN][MAXN],r=0,c=0,ans=-1;
int dfs(int,int);
int main()
{
  int i=1,j=0;
  memset(a,0x3f,sizeof(a));
  for(cin>>r>>c;i<=r;i++)
  {
  	for(j=1;j<=c;j++)
  	{
  	  cin>>a[i][j];
	}
  }
  for(i=1;i<=r;i++)
  {
  	for(j=1;j<=c;j++)
  	{
  	  if(ans<dfs(i,j))
  	  {
  	    ans=f[i][j];
	  }
	}
  }
  cout<<ans<<endl;
  return 0;
}
int dfs(int x,int y)
{
  if(f[x][y])
  {
  	return f[x][y];
  }
  int i=0,u=0,v=0;
  for(;i<4;i++)
  {
  	u=x+dx[i];
  	v=y+dy[i];
  	if(a[x][y]>a[u][v])
  	{
  	  f[x][y]=max(f[x][y],dfs(u,v));
	}
  }
  return ++f[x][y];
}
