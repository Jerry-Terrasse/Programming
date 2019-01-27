#include<iostream>
#define MAXN 1010
#define MAXA 70070
#define H 998244353
using namespace std;
int f[MAXN][MAXA<<1],a[MAXN],n=0,ans=0;
int main()
{
  register int i=0,j=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i]; 
  }
  ans+=n;
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  ++f[j][a[j]+MAXA-a[i]];
  	  ++ans;
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<i;++j)
  	{
  	  ans+=f[j][a[i]+MAXA-a[j]];
  	  ans%=H;
	  f[i][a[i]+MAXA-a[j]]+=f[j][a[i]+MAXA-a[j]];
	  f[i][a[i]+MAXA-a[j]]%=H;
	}
  }
  cout<<ans<<endl;
  return 0;
}
