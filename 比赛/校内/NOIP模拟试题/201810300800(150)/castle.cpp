#include<iostream>
#define ll long long
#define H 1000000007
using namespace std;
ll n=0,k=0,ans=0;
inline ll pow(ll,ll);
int main()
{
  freopen("castle.in","r",stdin);freopen("castle.out","w",stdout);
  cin>>n>>k;
  ans=pow(k,k-1);
  n-=k;
  ans*=pow(n%H,n);
  ans%=H;
  cout<<ans<<endl;
  return 0;
}
inline ll pow(ll a,ll b)
{
  ll ans=1;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  ans*=a;
  	  ans%=H;
	}
	a*=a;
	a%=H;
  }
  return ans;
}
