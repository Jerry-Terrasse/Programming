#include<iostream>
#define ll long long
#define MAXN 1000000010
#define H 1000000007
using namespace std;
ll n=0,ans=0,C=0;
inline ll pow(ll,ll);
int main()
{
  int i=1;
  //cin>>n;
  for(n=1;n<=30;n++)
  {
  	ans=0;
	C=n;
  for(i=1;i<n;++i)
  {
  	C*=(n-i);
  	C%=H;
  	C*=pow(i+1,H-2);
  	C%=H;
  	ans+=i*C;
  	ans%=H;
	}
	cout<<n<<':'<<ans<<endl;
	}
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
