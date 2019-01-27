#include<iostream>
#include<cmath>
using namespace std;
int n=0,m=0,v[25],w[25],dp[25][30000];
int main()
{
  int i=0,j=0;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  	cin>>v[i]>>w[i];
  	w[i]*=v[i];
  }
  for(i=1;i<=m;i++)
  {
  	for(j=1;j<=n;j++)
  	{
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
  	for(j=0;j<=n;j++)
  	{
  	  cout<<dp[i][j]<<' ';
	}
	cout<<endl;
  }*/
  cout<<dp[m][n]<<endl;
}
