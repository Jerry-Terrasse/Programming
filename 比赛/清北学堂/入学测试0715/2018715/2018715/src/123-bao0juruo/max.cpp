#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define For(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
inline int read()
{
	char c;
	bool t=0;
	int a=0;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-')
	{
		t=1;
		c=getchar();
	}
	while(isdigit(c))
	{
		a*=10;
		a+=(c-'0');
		c=getchar();
	}
	return a*(t?-1:1);
}
struct point{
	int x,c;
}jd[100001];
bool cmp(point a,point b)
{
	return a.c>b.c?1:0;
}
int l,n,va,vb,temp;
long long ans;
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int nowh=0,preh=0;
	l=read();
	n=read();
	va=read();
	vb=read();
	temp=va-vb;
	For(i,1,n)
	{
		jd[i].x=read();
		jd[i].c=read();
	}
	sort(jd+1,jd+n+1,cmp);
	For(i,1,n)
	{
		if(nowh<jd[i].x)
		{
			preh=nowh;
			nowh=jd[i].x;
			ans+=(temp*(nowh-preh)*jd[i].c);
		}
	}
	printf("%lld",ans);
	return 0;
}
