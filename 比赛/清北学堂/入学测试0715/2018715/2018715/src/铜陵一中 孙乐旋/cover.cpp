#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int f[100002],n,k,len=0,b[100002];
struct node{
	int s,e,l;
}a[100002];
int cmp1(node a,node b){
	return a.e<b.e;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i].s>>a[i].e;
		a[i].l=a[i].e-a[i].s;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;++i)
	for(int i=1;i<=n;++i){
		if(a[i-1].e>a[i].s) b[i]=a[i].l-a[i-1].e+a[i].s;
		if(a[i+1].s<a[i].e) b[i]=b[i]-a[i].e+a[i+1].s;
		if(b[i]<0) b[i]=0;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n-k;++i) f[i]=1;
	for(int i=1;i<=n;++i){
		if(f[i]==1) continue;
		if(len==0){
			len=a[i].l;continue;
		}
		len+=a[i].e-a[i-1].e;
	}
	cout<<a[n].e-a[1].s;
	return 0;
}
