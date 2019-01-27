#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int height,n,va,vb,p,last;
long long ans=0;
struct point
{
	int h,c;
};
point s[100005];
bool cmp(point a,point b)
{
	if(a.c==b.c)
	{
		return a.h<b.h;
	}
	else return a.c>b.c;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&height,&n,&va,&vb);
	int i;
	for(i=1;i<=n;i++)scanf("%d%d",&s[i].h,&s[i].c);
	sort(s+1,s+n+1,cmp);
	last=0;
	p=1;
	while(p<=n)
	{
		ans=ans+s[p].c*(s[p].h-last)/(va-vb);
		last=s[p].h;
		while(s[p].h<=last)
		{
			p++;
		}
	}
	printf("%lld",ans);
	return 0;
}
