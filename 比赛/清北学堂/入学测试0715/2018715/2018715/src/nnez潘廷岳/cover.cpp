#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node1{
	int li,ri;
}z[100003];
bool cmp(node1 x1,node1 x2);
void dfs(int x);
int n,k,res,top;
struct node{
	int l,r;
}a[100003];
bool cmp1(node x1,node x2);
int main()
{
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+n+1,cmp1);
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		res=max(res,a[i].r-a[i].l);
		cout<<res;
		return 0;
	}
	if(k==n)
	{
	//	sort(a+1,a+k+1,cmp1);
		int maxl=a[1].r,res=a[1].r-a[1].l;
		for(int i=2;i<=k;i++)
		{
			if(a[i].l<maxl)
			res+=max(0,a[i].r-maxl);
			else res+=a[i].r-a[i].l;
			if(a[i].r>maxl)
			maxl=a[i].r;
		}
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<res;
	return 0;
}
void dfs(int x)
{
	if(top==k)
	{
	//	sort(z+1,z+k+1,cmp);
		int maxl=z[1].ri,ans=z[1].ri-z[1].li;
		for(int i=2;i<=k;i++)
		{
			if(z[i].li<maxl)
			ans+=max(0,z[i].ri-maxl);
			else ans+=z[i].ri-z[i].li;
			if(z[i].ri>maxl)
			maxl=z[i].ri;
		}
		res=max(res,ans);
		return;
	}
	if(x==n+1)
	return;
	z[++top].li=a[x].l;
	z[top].ri=a[x].r;
	dfs(x+1);
	top--;
	dfs(x+1);
}
//bool cmp(node1 x1,node1 x2)
//{
//	return x1.li<x2.li;
//}
bool cmp1(node x1,node x2)
{
	return x1.l<x2.l;
}
