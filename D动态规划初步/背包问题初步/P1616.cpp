#include<iostream>
#include "memory.h"
#include<cmath>
using namespace std;
int dp[100001];
int t=0,m=0,v[10001],w[10001];
int main()
{
  int i=0,j=0;
  memset(dp,0,sizeof(dp));
  cin>>t>>m;
  for(i=1;i<=m;i++)
  {
  	cin>>v[i]>>w[i];
  }
  for(i=1;i<=m;i++)
  {
  	for(j=v[i];j<=t;j++)
  	{
	  if(j>=v[i])
	  {
	  	dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	  }
	}
  }
  cout<<dp[t]<<endl;
}
