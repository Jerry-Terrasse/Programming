#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int x,c;
}a[100001];
bool cmp(node aa,node bb)
{
	return aa.c>bb.c;
}
unsigned long long l,n,va,vb,g,ans;
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].x<=g)continue;
		ans+=(va-vb)*(a[i].x-g)*a[i].c;
		g=a[i].x;
	}
	cout<<ans;
	return 0;
}
