#include<cstdio>
#include<algorithm>
#define umax 100005
using namespace std;

struct node{
	int x,c;
}opi[umax];

bool cmp(node a,node b)
{
	return a.c>b.c;
}

int l,n,va,vb;

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=0;i<n;i++)
		scanf("%d%d",&opi[i].x,&opi[i].c);
	sort(opi,opi+n,cmp);
	int ans=0,time=0,hgo=0;
	for(int i=0;i<n;i++)
	{
		time=(va-vb)*opi[i].x;
		if(hgo>time)	continue;
		ans+=opi[i].c*(time-hgo);
		hgo=time;
	}
	printf("%d",ans);
	return 0;
}
