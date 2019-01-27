#include<iostream>
#include "memory.h"
#define ll long long
using namespace std;
ll dp[16][10],a=0,ans=0;
int b[16];
ll ac();
ll dfs(int,int,char);
int main()
{
  int i=0;
  memset(dp,-1,sizeof(dp));
  /*for(i=0;i<=20;i++)
  {
  	a=i;
	cout<<a<<":";
	cout<<ac()<<endl;
  }*/
  cin>>a;
  a--;
  ans=ac();
  cin>>a;
  ans=ac()-ans;
  cout<<ans<<endl;
  return 0;
}
ll ac()
{
  int i=0,j=0,ans=0;
  for(;a;a/=10)
  {
  	b[i++]=a%10;
  }
  i--;
  ans=dfs(i,0,2);
  for(j=1;j<b[i];j++)
  {
  	ans+=dfs(i,j,0);
  }
  if(b[i])ans+=dfs(i,b[i],1);
  return ans;
}
ll dfs(int x,int n,char bo)//bit,last number,lead|limit
{
  if(x<=0)
  {
  	return 1;
  }
  if(!bo && dp[x][n]!=-1)
  {
  	return dp[x][n]; 
  }
  int i=0,ans=0;
  if(bo&1)
  {
  	if((bo&2) || (n>=2))ans=dfs(x-1,0,(bo&2)|(bo&(0==b[x-1])));
	for(i=1;i<b[x-1];i++)
  	{
  	  if((-2>=(n-i)||(n-i)>=2)||((bo&2)&&(n==0)))ans+=dfs(x-1,i,0);
	}
	if(b[x-1] && (-2>=(b[x-1]-n) || (b[x-1]-n)>=2))ans+=dfs(x-1,b[x-1],1);
  }
  else
  {
  	if((bo&2) || (n>=2))ans=dfs(x-1,0,bo&2);
	for(i=1;i<=9;i++)
	{
	  if((-2>=(n-i)||(n-i)>=2)||((bo&2)&&(n==0)))ans+=dfs(x-1,i,0);
	}
  }
  if(bo)
  {
  	return ans;
  }
  else
  {
  	return dp[x][n]=ans;
  }
}
