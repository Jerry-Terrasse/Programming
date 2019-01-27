#include<iostream>
#define ak 554056561
#define ioi(alpha,beta) alpha*3+beta
#define MAXN 20000010//772222
#define MAXX 9
using namespace std;
long long dp[2][2],n=0,ans=0;
int main()
{
  long long i=0,j=0,k=0,l=0;
  cin>>n;
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
  dp[0][0]=dp[0][1]=1;
  for(i=3;;i++)
  {
  	dp[i&1][0]=dp[i&1^1][0]+dp[i&1^1][1];
  	dp[i&1][1]=dp[i&1^1][0]*2+dp[i&1^1][1];
  	dp[i&1][0]%=ak;
  	dp[i&1][1]%=ak;
  	//ac[dp[i&1][0]][dp[i&1][1]=1;
  }
  ans=dp[n&1][0]*6+dp[n&1][1]*3;
  ans%=ak;
  cout<<ans<<endl;
  return 0;
}
