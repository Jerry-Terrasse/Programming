#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct p
{
	int h;
	int v;
}a[1000009];
int maxh;
int ans;
int l,n,va,vb;
int now;
bool cmp(p x,p y)
{
	return x.v>y.v;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	int c=va-vb;
	for(int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].v;
		maxh=max(maxh,a[i].h);
	}
	sort(a+1,a+n,cmp);
	int i=1;
	while(1)
	{
		if(now<a[i].h){
			int ab=(a[i].h-now)/c;
			ans+=ab*a[i].v;
		now=a[i].h;
		}
		if(now==maxh)break;
		i++;
	}
	cout<<ans;
	return 0;
}
