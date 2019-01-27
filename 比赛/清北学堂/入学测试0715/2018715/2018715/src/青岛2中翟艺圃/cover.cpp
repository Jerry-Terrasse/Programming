#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int l[100010];
int r[100010];
int x[1000000];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int maxl=1000000001,maxr=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		for(int j=l[i];j<=r[i];j++)
		{
			x[j]++;
		}
		if(maxl>l[i])
		{
			maxl=l[i];
		}
		if(maxr<r[i])
		{
			maxr=r[i];
		}
	}
	int jz,jzd,next;
	k=n-k;
	while(k!=0)
	{
		for(int i=1;i<=n;i++)
		{
			jzd=0;
			for(int j=l[i];j<=r[i];j++)
			{
				if(x[j]==1)
				{
					jzd++;
				}
			}
			if(i==1)
			{
				jz=jzd;
			}
			if(jzd>jz)
			{
				jz=jzd;
				next=i;
			}
		}
		for(int i=l[next];i<=r[next];i++)
		{
			x[i]--;
		}
		k--;
	}
	int answer=0;
	int dyg=0;
	int hjhjh=0;
	for(int i=maxl;i<=maxr;i++)
	{
		if(x[i]<=0&&dyg==1)
		{
			answer--;
			dyg=0;
			hjhjh=1;
		}
		if(x[i]>=1)
		{
			if(dyg==0)
			{
				dyg==1;
			}
			answer++;
		}
	}
	if(hjhjh==0)
	{
		answer--;
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
