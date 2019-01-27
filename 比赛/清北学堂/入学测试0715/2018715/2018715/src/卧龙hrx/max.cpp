#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int L,n,Va,Vb,time;
int maxn=100000;
struct AB
{
	int xi,ci;
	int lt;
}a[100001];
long long ans;
bool cmp(AB a,AB b)
{
	return a.ci>b.ci;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&L,&n,&Va,&Vb);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].xi,&a[i].ci);
		
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		a[i].lt=a[i].xi*Va-a[i].xi*Vb;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].lt>0)
		{
			ans+=a[i].lt*a[i].ci;
			for(int j=i;j<=n;j++)
			{
				if(a[j].xi>a[i].xi)
				{
					if(a[j].lt-a[i].lt>=0)a[j].lt-=a[i].lt;
					else a[j].lt=0;
				}
			}
			a[i].lt=0;
		}
	}
	printf("%lld",ans);
	
}
