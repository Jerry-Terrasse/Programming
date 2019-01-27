#include<iostream>
#include "memory.h"
#define MAXN 1010
using namespace std;
const int dx[8]={1,1,0,-1,-1,-1,0,1};
const int dy[8]={0,-1,-1,-1,0,1,1,1};
int mat[MAXN][MAXN],f[MAXN][MAXN],n=0,m=0,ans=0,mi=0x7fffffff,mix=0,miy=0;
int dfs(int,int);
int main()
{
  int i=0,j=0;
  memset(mat,-1,sizeof(mat));
  memset(f,-1,sizeof(f));
  ios::sync_with_stdio(0);
  for(cin>>n>>m;i<n;i++)
  {
  	for(j=0;j<m;j++)
  	{
  	  cin>>mat[i][j];
	}
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<m;j++)
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
  if(f[x][y]!=-1)
  {
  	return f[x][y];
  }
  int i=0,j=0,k=0;
  f[x][y]=0;
  for(k=0;k<8;k++)
  {
  	i=x+dx[k];j=y+dy[k];
  	if(i<0||i>=n||j<0||j>=n)
  	{
  	  continue;
	}
	if(mat[x][y]<mat[i][j] && f[x][y]<dfs(i,j))
  	{
  	  f[x][y]=f[i][j];
	}
  }
  return ++f[x][y];
}
