#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int left;
	int right;
}a[200];
bool cmp(node x,node y)
{
	return x.right>y.right;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int n,k,now,maxlen=-1,maxleft,maxthis,maxl;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].left>>a[i].right;
	}
	sort(a+1,a+1+n,cmp);
/*
	for(int i=1;i<=n;i++)
		cout<<a[i].left<<' '<<a[i].right<<endl;
*/
/*
	for(int i=1;i<=n;i++)
	{
		len=-1;
		for(int j=i;j<=n;j++)
		{
			if(a[j].right>=a[i].left&&a[j].right<=a[i].right)
				if(a[i].left-a[j].left>len)
				{
					len=a[i].left-a[j].left;
					lenx=a[i].left;
				}
		}
	}
*/	
	now=1;
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j].right>a[now].left&&a[j].right<a[now].right)	
				if(a[now].left-a[j].left>maxlen)
				{
					maxlen=a[now].left-a[j].left;
					maxleft=a[j].left;
					maxthis=j;
				}
		}
		now=maxthis;
		maxlen=-1;
	}
	cout<<a[1].right-maxleft<<endl;
	return 0;
}
