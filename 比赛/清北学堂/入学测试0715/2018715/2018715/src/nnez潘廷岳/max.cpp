#include<iostream>
#include<cstdio>
#include<algorithm>
struct node{
	int h,v;
}a[100004];
bool cmp(node x1,node x2);
int L,n,va,vb,hi;
long long ans;
using namespace std;
int main()
{
//	freopen("max.in","r",stdin);
//	freopen("max.out","w",stdout);
	cin>>L>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].h,&a[i].v);
	}
	sort(a+1,a+n+1,cmp);
	ans=(va-vb)*a[1].h*a[1].v;
	hi=a[1].h;
	for(int i=2;i<=n;i++)
	{
		if(a[i].h>hi)
		{
			ans+=(va-vb)*(a[i].h-hi)*a[i].v;
			hi=a[i].h;
		}
	}
	cout<<ans;
	return 0;
}
bool cmp(node x1,node x2)
{
	if(x1.v==x2.v)
	return x1.h>x2.h;
	return x1.v>x2.v;
}
