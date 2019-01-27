#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k,l,sum,maxl;
struct node
{
	int l;
	int r;
	int len;
}s[100100];
bool cmp(node a,node b)
{
	if(a.l!=b.l)return a.l<b.l;
	else return a.r<b.r;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;++i)
	{
	    cin>>s[i].l>>s[i].r;
	    s[i].len=s[i].r-s[i].l;
	    maxl=max(maxl,s[i].len);
	}
	if(k==1){cout<<maxl<<endl;return 0;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n&&k;++i)
	{
		if(s[i].l>=s[l].r)sum+=s[i].len,k--,l=i;
		else if(s[i].r<s[i-1].r);
		else  sum+=s[i].r-s[i-1].r;
	}
	cout<<sum;
	return 0;
}
