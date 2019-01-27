#include<iostream>
#define ll long long
using namespace std;
ll n=0,m=0,H=0;
inline ll pow(ll,ll);
inline ll mul(ll,ll);
int main()
{
  int i=0;
  cin>>n>>H>>m;
  cout<<pow(n,m)<<endl;
  return 0;
}
inline ll mul(ll a,ll b)
{
  ll ans=0;
  for(;b;a=(a<<1)%H,b>>=1)
  {
  	if(b&1)
  	{
  	  ans=(ans+a)%H;
	}
  }
  return ans;
}
inline ll pow(ll a,ll b)
{
  ll ans=1;
  for(;b;a=mul(a,a),b>>=1)
  {
  	if(b&1)
  	{
  	  ans=mul(ans,a);
	}
  }
  return ans;
}
