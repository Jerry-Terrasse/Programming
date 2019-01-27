#include<bits/stdc++.h>
using namespace std;
const int MAX=1000001;
int l,n,va,vb,ans,tot=1,now;
struct node{
	int x;
	int c;
}a[MAX];
int cmp(node i,node j)
{
	if(i.c==j.c)
		return i.x>j.c;
	if(i.x==j.x)
		return i.c>j.c;
	return i.c>j.c;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	int temp=va-vb;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].c);
	sort(a+1,a+1+n,cmp);
	while(now<l)
	{
		if(now-a[tot].x<0)
		{
			ans+=(a[tot].x-now)*temp*a[tot].c;
			now+=a[tot].x;
		}
		tot++;
		if(tot>n) break;
	}
	printf("%d",ans);
	return 0;
}
