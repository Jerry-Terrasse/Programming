#include<iostream>
#define MAXN 520
using namespace std;
int a[MAXN],dp[MAXN],n=0,ans=0,cnt=0;
int main()
{
  int i=1,j=0;
  a[1]=0x7fffffff;
  for(cin>>n;i<=n;i++)
  {
    cin>>a[i];
  }
  for(i=1;i<=n;i++)
  {
	for(j=1;j<i;j++)
    {
      if(a[j]<=a[i] && dp[j]>dp[i])
      {
      	dp[i]=dp[j];
	  }
	}
	dp[i]++;
	if(ans<dp[i])
	{
	  ans=dp[i];
	}
  }
  for(i=1;i<=n;i++)
  {
  	cout<<dp[i]<<' ';
	if(dp[i]==ans)
  	{
  	  cnt++;
	}
  }
  
  cout<<ans<<endl; 
  return 0;
}
