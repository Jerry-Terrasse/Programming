#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long l,a,b,f[1010101],ans,timee;
struct node
{
	long long x,y;
}e[1010001];
bool cmp(node a,node s)
{
	return a.x==s.x?a.y<s.y:a.x<s.x;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%lld%d%lld%lld",&l,&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&e[i].x,&e[i].y);
	sort(e+1,e+1+n,cmp);
	int w=a-b;
	for(int i=1;i<=n;i++)
	{
		timee=w*e[i].x-timee;
		ans+=timee*e[i].y;
	}
	printf("%lld",ans);
}
