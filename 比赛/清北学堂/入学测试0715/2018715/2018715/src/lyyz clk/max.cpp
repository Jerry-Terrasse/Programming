#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
typedef long long ll;
ll n,L,va,vb;
ll ta[maxn],tb[maxn];
struct scene
{
	ll x,c;
	bool operator < (const scene rhs) const
	{
		return this-> x > rhs.x;
	}
}a[maxn];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%lld%lld%lld%lld",&L,&n,&va,&vb);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].c);
		ta[i]=va*(a[i].x-a[i-1].x);
		tb[i]=vb*(a[i].x-a[i-1].x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(ta[i]-tb[i])*a[i].c;
	}
	printf("%lld",ans);
	return 0;
}
