#include<bits/stdc++.h>
#define ll long long
#define MAXN 64
using namespace std;
ll a[MAXN],b[MAXN],c[MAXN],n=0,ans=0;
inline ll dp(const ll*,ll);
int main()
{
  ll i=0,j=0,bn=0,cn=0;
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i];
  }
  for(i=1;i<(1<<n-1);i++)
  {
  	bn=0;cn=0;
	for(j=0;j<n;j++)
  	{
  	  if(i&(1<<j))
  	  {
  	    b[bn++]=a[j];
	  }
	  else
	  {
	  	c[cn++]=a[j];
	  }
	}
	ans=max(ans,dp(b,bn)+dp(c,cn));
  }
  cout<<ans<<endl;
  return 0;
}
inline ll dp(const ll *a,ll n)
{
  ll f[MAXN],i=0,j=0,ans=0;
  memset(f,0,sizeof(f));
  for(i=0;i<n;i++)
  {
  	f[i]=1;
	for(j=0;j<i;j++)
  	{
  	  if(a[i]>=a[j]&&f[i]<f[j]+1)
  	  {
  	    f[i]=f[j]+1;
	  }
	}
	if(ans<f[i])
	{
	  ans=f[i];
	}
  }
  return ans;
}
