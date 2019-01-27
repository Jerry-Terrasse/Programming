#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int l,n,va,vb,x[maxn]={0},c[maxn]={0},xx,ans,mid;
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	xx=va-vb;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>c[i];
		mid=x[i]-x[i-1];
		ans+=xx*mid*c[i];
	}
	printf("%d",ans);
	return 0;
}
