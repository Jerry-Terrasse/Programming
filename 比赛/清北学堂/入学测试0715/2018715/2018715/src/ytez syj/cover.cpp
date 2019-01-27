#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct p{
	int l;int r;
}a[100001];
int n,k,ans,maxr=0,minl=100000000; 
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	   cin>>a[i].l>>a[i].r;
	   if(a[i].l<minl)minl=a[i].l;
	   if(a[i].r>maxr)maxr=a[i].r;
	}
	cout<<maxr-minl;
	return 0;
}
