#include<iostream>
#include "memory.h"
#include<cmath>
#define ll long long
using namespace std;
ll dp[32][20],bit[32],ans=0,a=0,b=0;
ll ak(ll);
ll dfs(int,int,bool,bool);
int main()
{
  memset(dp,-1,sizeof(dp));
  /*for(int i=0;i<=140;i++)
  {
  	cout<<i<<":"<<ak(i)<<endl;
  }*/
  cin>>a>>b;
  ans=ak(b);
  ans-=ak(a-1);
  cout<<ans<<endl;
  return 0;
}
ll ak(ll x)
{
  int i=0,j=0,w=x,ans=0;
  for(;w;)
  {
  	bit[++i]=w%10;
  	w/=10;
  }
  for(j=0;j<=bit[i];j++)
  {
  	ans+=dfs(i,j,j==0,j==bit[i]);
  }
  return ans;
}
ll dfs(int x,int n,bool lead,bool lim)
{
  if(x<=1)
  {
  	return 1;
  }
  if(!lead && !lim && dp[x][n]!=-1)
  {
    return dp[x][n];
  }
  int i=0,ans=0,p=lim?bit[x-1]:9;
  for(i=0;i<=p;i++)
  {
  	if(lead)
  	{
  	  ans+=dfs(x-1,i,i==0,lim && bit[x-1]==i);
	}
	else
	{
	  if(abs(n-i)<3)
	  {
	  	continue;
	  }
	  ans+=dfs(x-1,i,1,lim && bit[x-1]==i);
	}
  }
  if(!lead && !lim)
  {
  	return dp[x][n]=ans;
  }
  else
  {
  	return ans;
  }
}
