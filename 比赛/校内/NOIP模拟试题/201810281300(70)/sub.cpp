#include<iostream>
#define ll long long
#define H 998244353
using namespace std;
inline ll pow(ll,ll);
int main()
{
  int i=0;
  cout<<pow(16,H-2)*75%H<<endl;
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
