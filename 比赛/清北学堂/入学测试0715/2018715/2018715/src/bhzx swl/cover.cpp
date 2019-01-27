#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
struct xd
{
	int z;
	int y;
};
xd a[100005];
bool cmp1(xd a,xd b)
{
	return a.z<=b.z;
};
bool cmp2(xd a,xd b)
{
	return a.y>=b.y;
}
void solve()
{
	if(a[2].z<a[1].y)
	{
	int min=a[1].z;
	sort(a+1,a+n+1,cmp2);
	int max=a[1].y;
	ans=max-min;
	}
	else
	{
		ans=a[1].y-a[1].z;
		sort(a+1,a+n+1,cmp2);
		ans+=a[1].y-a[1].z;
	}
}
int main()
{
	cin>>n>>k;
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int i;
	for(i=1;i<=n;i++)
		cin>>a[i].z>>a[i].y;
	sort(a+1,a+n+1,cmp1);
	solve();
	cout<<ans<<endl;
	return 0;
}
