#include<iostream>
#define ak 554056561
#define ioi(alpha,beta) alpha*3+beta
#define MAXN 20000010//772222
#define MAXX 9
using namespace std;
int dp[2][MAXX],n=0,ans=0;
int main()
{
  int i=0,j=0,k=0,l=0;
  for(cin>>n;i<3;i++)
  {
  	for(j=0;j<3;j++)
  	{
  	  dp[0][ioi(i,j)]=1;
	}
  }
  if(n==0)
  {
  	cout<<0<<endl;
  	return 0;
  }
  if(n==1)
  {
  	cout<<3<<endl;
  	return 0;
  }
  for(i=3;i<=n;i++)
  {
  	for(j=0;j<MAXX;j++)
  	{
  	  dp[i&1][j]=0;
	}
	for(j=0;j<3;j++)
  	{
  	  dp[i&1][ioi(j,j)]=dp[(i&1)^1][ioi(0,j)]+dp[(i&1)^1][ioi(1,j)]+dp[(i&1)^1][ioi(2,j)];
  	  dp[i&1][ioi(j,j)]%=ak;
	}
	for(j=0;j<3;j++)
	{
	  for(k=0;k<3;k++)
	  {
	  	if(j!=k)
	  	{
	  	  for(l=0;l<3;l++)
	  	  {
	  	    if(j+k+l!=3)
	  	    {
	  	      dp[i&1][ioi(j,k)]+=dp[(i&1)^1][ioi(l,j)];
	  	      dp[i&1][ioi(j,k)]%=ak;
			}
		  }
		}
	  }
	}
  }
  for(i=0;i<MAXX;i++)
  {
  	ans+=dp[n&1][i];
  	ans%=ak;
  }
  cout<<ans<<endl;
  return 0;
}
