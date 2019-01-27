#include<iostream>
#include<algorithm>
using namespace std;
int l,n,va,vb;
struct point
{
	int x;
	int c;
} p[100010];
bool cmp(point a,point b) {
	return a.x<b.x;
}
int m[100010];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].c;
	}
	sort(p+1,p+1+n,cmp);
	m[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(p[i].c>p[m[i+1]].c) m[i]=i;
		else m[i]=m[i+1];
	}
	long long ans=0;
	int lo=0;
	for(int i=1;i<=n;i++)
	{
		if(m[i]!=m[i-1])
		{
			ans+=p[m[i]].c*(va-vb)*(p[m[i]].x-p[lo].x);
			lo=m[i];
		}
	}
	cout<<ans;
	return 0;
}
