#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int x,c;
}a[1000000];
bool cmp(node f,node g)
{
	return f.x<g.x;
}
int main()
{
	int l,n,va,vb,via,maxn=0,last=0;
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	via=va-vb;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		maxn+=(a[i].x-last)*a[i].c*via;
		last=a[i].x;
	}
	cout<<maxn<<endl;
	return 0;
}
