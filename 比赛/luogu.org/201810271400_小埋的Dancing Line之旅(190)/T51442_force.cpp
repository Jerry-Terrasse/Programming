#include<iostream>
#include<map>
#define ll long long
using namespace std;
ll n=0,p=0,a=0,b=0,c=0;
map<ll,ll>mp;
int main()
{
	ll i=0;
	cin>>n>>p>>b;
	b-=n;a=(n<<1)-1;
	b=((b%p)+p)%p;
	a%=p;
	if(a==b)
	{
		cout<<1<<endl;
		return 0;
	}
	mp.insert(make_pair(c=a,1));
	for(i=2;;++i)
	{
		c*=a;
		c%=p;
		if(c==b)
		{
			cout<<i<<endl;
			break;
		}
		if(mp.count(c))
		{
			cout<<"INF"<<endl;
			break;
		}
		mp.insert(make_pair(c,i));
	}
	return 0;
}
