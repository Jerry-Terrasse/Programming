#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l[100010],r[111010],len[100010];
struct ting
{
	int l,r,len;
}e[100010];
bool cmp(ting x, ting y)
{
	return x.len>y.len;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);

	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].l;
		cin>>e[i].r;
		e[i].len=e[i].r-e[i].l+1;
	}
	sort(e+1,e+n+1,cmp);
	int ans=0;
	int m=1;
	for(int i=1;i<=k;i++)
	{
		
	    ans+=e[1].len;
		for(int j=1;j<=n;j++)
		{
			if(e[j].l<e[1].r)
		{
			e[j].l=e[1].r+1;
			e[j].len=e[j].r-e[j].l+1;
		}
		if(e[j].r>e[1].l)
		{
			e[j].r=e[1].l-1;
			e[j].len=e[j].r-e[j].l+1;
		}
		
		e[n].l=e[1].r;
		e[n].len=0;
		sort(e+1,e+n+1,cmp);
		}
		
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
