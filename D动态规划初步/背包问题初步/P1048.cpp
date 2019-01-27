#include<iostream>
#include "memory.h"
#include<cmath>
using namespace std;
int dp[101][1001];
int t=0,m=0,v[101],w[101];
//int t=0,m=0,v[101],w[101],dp[101][1000];
int main()
{
  int i=0,j=0;
  memset(dp,0,sizeof(dp));
  memset(v,0,sizeof(v));
  memset(w,0,sizeof(w));
  cin>>t>>m;
  for(i=1;i<=m;i++)
  {
  	cin>>v[i]>>w[i];
  }
  for(i=1;i<=m;i++)
  {
  	for(j=0;j<=t;j++)
  	{
	  //cout<<i<<','<<j<<endl;
	  if(j>=v[i])
	  {
	  	dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
	  }
	  else
	  {
	  	dp[i][j]=dp[i-1][j];
	  }
	}
  }
  /*for(i=1;i<=m;i++)
  {
  	for(j=0;j<=t;j++)
  	{
  	  cout<<dp[i][j]<<' ';
	}
	cout<<endl;
  }*/
  //cout<<endl;
  cout<<dp[m][t]<<endl;
}
