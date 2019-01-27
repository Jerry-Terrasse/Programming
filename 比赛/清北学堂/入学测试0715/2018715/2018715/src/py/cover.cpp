#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
struct p
{
	int l;
	int r;
}a[100009];
int maxl,maxr;
bool cmp(p x,p y){
	return x.r>y.r;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		maxr=max(a[i].r,maxr);
		maxl=min(a[i].l,maxl);
	}
	cout<<maxr-maxl+1;
//	sort(a+1,a+n,cmp);
	return 0;
}
