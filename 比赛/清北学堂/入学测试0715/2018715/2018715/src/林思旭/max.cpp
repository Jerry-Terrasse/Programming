#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int x;
	int c;
}jd[100001];

int cmp(const Node &a,const Node &b)
{
	if(a.c>b.c) return 1;
	else if(a.c==b.c) return a.x>b.x;
	else return 0;
}

int main()
{
	int n,l,va,vb,i,v,h,now;
	long long happy;
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&jd[i].x,&jd[i].c);
	}
	v=va-vb;
	sort(jd,jd+n,cmp);
	h=jd[0].x;
	now=1;
	happy=jd[0].x*v*jd[0].c;
	while(now<n)
	{
		if(jd[now].x>h)
		{
			happy+=(jd[now].x-h)*v*jd[now].c;
			h=jd[now].x;
		}
		now++;
	}
	printf("%lld",happy);
	return 0;
}
