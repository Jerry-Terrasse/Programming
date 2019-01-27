#include<iostream>
#include "memory.h"
#include<cmath>
#define MAXN 22
#define lbt(x) x&-x
using namespace std;
long long dp[1<<MAXN],n=0;
long long dfs(int);
int main()
{
  int i=0,j=0,k=0,ak=0;
  ios::sync_with_stdio(0);
  memset(dp,-1,sizeof(dp));
  //while(cin>>ak)cout<<log2(lbt(ak))<<endl;
  for(cin>>n;i<n;i++)
  {
  	for(j=i+1;j<n;j++)
  	{
  	  for(k=j+1;k<n;k++)
  	  {
		cin>>ak>>ak>>ak>>dp[(1<<i)|(1<<j)|(1<<k)];
	  }
	}
  }
  dfs((1<<n)-1);
  cout<<dp[(1<<n)-1]<<endl;
  return 0;
}
long long dfs(int x)
{
  if(dp[x]!=-1)
  {
  	return dp[x];
  }
  int p=0,i=0,j=0,k=0;
  i=log2(lbt(x));
  for(j=i+1;j<n;j++)
  {
  	p=x^(1<<i)^(1<<j);
	for(k=j+1;k<n;k++)
  	{
  	  if((1<<j&x)&&(1<<k&x)&&(dfs(p^(1<<k))+dp[(1<<i)|(1<<j)|(1<<k)]>dp[x]))
  	  {
  	  	dp[x]=dp[p^(1<<k)]+dp[(1<<i)|(1<<j)|(1<<k)];
	  }
	}
  }
  return dp[x];
}
