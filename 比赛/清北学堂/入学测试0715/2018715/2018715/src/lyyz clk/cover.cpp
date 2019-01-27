#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int n,k,ans=0;

struct Edge
{
	int l,r;
}e[maxn];

int cmp(Edge a,Edge b)
{
	if(a.l>b.l)return 1;
	else
	{
		if(a.r<b.r)return 1;
		else return 0;
	}
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&e[i].l,&e[i].r);
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,e[i+k-1].r-e[i].l+1);
	}
	printf("%d",ans);
	return 0;
}
