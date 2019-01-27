#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
struct node
{
	int le,ri;
}a[100001];
bool cmp(node aa,node bb)
{
	if(aa.le==bb.le)return aa.ri>bb.ri;
	return aa.le<bb.le;
}
int n,ans,k,pd[100001],sc,s;
void print()
{
	cout<<"choose";
	for(int i=1;i<=n;i++)
	{
		if(pd[i])cout<<i<<" ";
	}
	cout<<"="<<ans<<endl;
}
void dfs(int nk,int nr)
{
	if(nk==k+1||(nk<k+1&&nk==n+1))
	{
		//print();
		sc=max(sc,ans);
	}
	for(int i=1;i<=n;i++)
	{
		if(pd[i])continue;
		if(a[i].ri<=nr)continue;
		if(a[i].le<nr)
		{
			ans+=a[i].ri-nr;pd[i]=1;
			dfs(nk+1,a[i].ri);
			ans-=a[i].ri-nr;pd[i]=0;
		}
		else
		{
			ans+=a[i].ri-a[i].le;pd[i]=1;
			dfs(nk+1,a[i].ri);
			ans-=a[i].ri-a[i].le;pd[i]=0;
		}
	}
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&s,&k);
	for(int i=1;i<=s;i++)
	{
		int sr1,sr2;
		scanf("%d%d",&sr1,&sr2);
		if(sr1==sr2)continue;
		if(sr1>sr2)swap(sr1,sr2);
		n++;a[n].le=sr1;a[n].ri=sr2;
	}
	sort(a+1,a+1+n,cmp);
	/*for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",a[i].le,a[i].ri);
	}*/
	dfs(1,0);
	cout<<sc;
	return 0;
}
