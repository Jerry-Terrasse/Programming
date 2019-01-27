#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue> 
#include<map> 
using namespace std;
int n,k,maxn,ans;
int cov[120000],p[120000]; //dp i j选j条时最大长度 
struct line
{
	int h,t;
}e[120000];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&e[i].h,&e[i].t);
		p[e[i].h]++;p[e[i].t+1]--;
		maxn=max(e[i].t,maxn);
	}
	for(int i=1;i<=maxn;i++)
	cov[i]=cov[i-1]+p[i];
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,e[i].t-e[i].h);
		}
		cout<<ans;return 0;
	}
} 
