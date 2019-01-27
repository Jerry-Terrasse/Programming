#include<iostream>
#define ll long long
#define pp 998244353
using namespace std;
inline ll pow(ll a,ll b)
{
	ll ans=1;
	for(;b;)
	{
		if(b&1)
		{
			ans*=a;
			ans%=pp;
		}
		a*=a;
		a%=pp;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll i=0,j=0;
	cout<<pow(4,pp-2)<<endl;
	for(;;)
	{
		cin>>i>>j;
		cout<<(i*j)%pp<<endl;
	}
	return 0;
}
