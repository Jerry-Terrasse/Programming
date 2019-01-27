#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue> 
#include<map> 
using namespace std;
int l,n,va,vb,ans,now; 
const int maxn=120000;
struct node
{
	int hig,hap;
}e[maxn];
bool cmp(node a,node b)
{
	return a.hap>b.hap;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&e[i].hig,&e[i].hap);
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(e[i].hig-now>0)
		{
			ans+=((e[i].hig-now)*(va-vb)*e[i].hap);
			now=e[i].hig;
		}
	}
	cout<<ans;
}
