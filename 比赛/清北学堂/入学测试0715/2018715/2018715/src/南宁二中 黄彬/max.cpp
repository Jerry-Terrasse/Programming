#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,n,va,vb,ans=0;
int xi[100010],ci[100010];
int xi1[100010],ci1[100010];

void sortt(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	sortt(l,mid);
	sortt(mid+1,r);
	
	int l1=l,r1=mid+1,now=l;
	while(l1<=mid&&r1<=r)
	{
		if(ci[l1]>=ci[r1])
		{
			ci1[now]=ci[l1];
			xi1[now]=xi[l1];
			l1++;
		}
		else
		{
			ci1[now]=ci[r1];
			xi1[now]=xi[r1];
			r1++;
		}
		now++;
	}
	while(l1<=mid)
	{
		ci1[now]=ci[l1];
		xi1[now]=xi[l1];
		l1++;
		now++;
	}
	while(r1<=r)
	{
		ci1[now]=ci[r1];
		xi1[now]=xi[r1];
		r1++;
		now++;
	}
	for(int i=l;i<=r;i++)
	{
		xi[i]=xi1[i];
		ci[i]=ci1[i];
	}
	return;
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%lld %lld %lld %lld",&l,&n,&va,&vb);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&xi[i],&ci[i]);
	sortt(1,n);
	int now=0,speed=va-vb;
	for(int i=1;i<=n;i++)
	{
		if(now>=xi[i])continue;
		ans+=speed*(xi[i]-now)*ci[i];
		now=xi[i];
	}
	printf("%ld",ans);
	return 0;
}
