#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define ll long long
#define N 1001003
#define inf 0x7fffffff
using namespace std;

ll read()
{
	int f=1;
	ll ret=0;
	char ch=getchar();
	while((ch>'9' || ch<'0') && ch!='-')
	ch=getchar();
	if(ch=='-')
	ch=getchar(),f=-1;
	while(ch<='9' && ch>='0')
	{
		ret=ret*10+ch-'0';
		ch=getchar();
	} 
	return ret*f;
}

struct xian
{
	ll l;
	ll r;
	ll len;
	bool vis;
};
xian a[100300];

bool cmp(xian x,xian y)
{
	return x.l<y.l;
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int n=read();
	int k=read();
	for(int i=1;i<=n;i++)
	{
		a[i].l=read();
		a[i].r=read();
		a[i].len=a[i].r-a[i].l;
	}
	sort(a+1,a+1+n,cmp);
	a[1].vis=true;
	int sum=a[1].len;
	for(int o=2;o<=n;o++)
	{
		if(a[o].l<=a[1].r)
		{
			a[o].len=a[o].len-(a[1].r-a[o].l);
			a[o].l=a[1].r;
		}
	}
	for(int i=2;i<=k;i++)
	{
		int maxl=-1;
		int maxi;
		
		for(int j=2;j<=n;j++)
		{
			if(!a[j].vis && a[j].len>maxl)
			{
				maxi=j;
				maxl=a[j].len;
			}
		}
		sum+=maxl;
		a[maxi].vis=true;
		//cout<<maxi<<" ! "<<maxl<<endl;
		for(int o=2;o<=n;o++)
		{
			if(a[o].l<=a[maxi].r)
			{
				a[o].len=a[o].len-(a[maxi].r-a[o].l);
				a[o].l=a[maxi].r;
			}
			if(a[o].r>=a[maxi].l)
			{
				a[o].len=a[o].len-(a[o].r-a[maxi].l);
				a[o].r=a[maxi].l;
			}
		}
	}
	cout<<sum;
	return 0;
}







