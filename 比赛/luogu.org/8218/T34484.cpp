#include<iostream>
#define MAXN 200020
using namespace std;
int a[MAXN],dp[MAXN],pd[MAXN],n=0,ans=0;
int main()
{
  int i=1,j=0;
  cin>>n;
  for(;i<=n;i++)
  {
  	cin>>a[i];
  }
  a[0]=a[n+1]=0x7fffffff;
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
  }
  for(i=n;i>=1;i--)
  {
  	for(j=n;j>i;j--)
  	{
  	  if(a[j]<=a[i] && pd[j]>pd[i])
  	  {
  	    pd[i]=pd[j];
	  }
	}
	pd[i]++;
  }
  for(i=1;i<=n;i++)
  {
  	if(ans<dp[i]+pd[i])
  	{
  	  ans=dp[i]+pd[i];
	}
  }
  cout<<ans-1<<endl;
  return 0;
}
