#include<iostream>
#include "memory.h"
#define MAXM 10005
#define MAXN 105
using namespace std;
int m=0,n=0,a[MAXN],dp[MAXN][MAXM];
int main()
{
  int i=0,j=0;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
  	cin>>a[i];
  }
  memset(dp,0,sizeof(dp));
  for(i=0;i<=n;i++)
  {
  	dp[i][0]=1;
  }
  for(i=1;i<=n;i++)
  {
  	for(j=0;j<=m;j++)
  	{
  	  if(j>=a[i])
  	  {
  	  	dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
	  }
	  else
	  {
	  	dp[i][j]=dp[i-1][j];
	  }
	}
  }
  /*cout<<'{'<<endl;
  for(i=0;i<=n;i++)
  {
  	for(j=0;j<=m;j++)
  	{
  	  cout<<dp[i][j]<<' ';
	}
	cout<<endl;
  }
  cout<<'}'<<endl;*/
  cout<<dp[n][m]<<endl;
  return 0;
}
