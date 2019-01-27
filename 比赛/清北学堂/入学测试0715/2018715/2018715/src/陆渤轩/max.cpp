#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,va,vb,maxa,H;
long long sum;
struct Node
{
	int h,c;
}ds[100001];
bool cmp(const Node &a,const Node &b)
{
	if(a.c>b.c) return 1;
	else if(a.c==b.c)return a.h>b.h;
	else return 0;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>L>>n>>va>>vb;
	int v=va-vb;
	int a;
	for(int i=1;i<=n;i++)
	{
		cin>>ds[i].h>>a;
		if(a>ds[i].c)ds[i].c=a;
	}
	sort(ds+1,ds+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(ds[i].h>H)
		{
			sum+=(ds[i].h-H)*v*ds[i].c;
			H=ds[i].h;
		}
	}
	cout<<sum;
	return 0;
}
