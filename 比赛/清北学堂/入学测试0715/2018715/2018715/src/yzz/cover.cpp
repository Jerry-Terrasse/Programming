#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,cnt;
struct node{
	int l,r;
}a[100004];
void cmp(node *a,node *b)
{
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
int maxx;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	 scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1=n,cmp);
	int t=a[1].r ;
	k--;
	while(a[i].l<=t)
	{
		maxx=max(a[i].r,maxx);
		if(a[i+1].l>t) 
		{
			t=a[i].r;
		}
		i++;
	}
	printf("%d\n",t-1);
	return 0;
}
