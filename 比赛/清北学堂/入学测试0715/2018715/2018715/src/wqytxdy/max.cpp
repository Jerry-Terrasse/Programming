#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e5+3;
struct node{
	LL h,c;
}a[N];
inline bool cmp(node x,node y){
	return x.c>y.c;	
}
LL va,vb;
int n,l;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%lld%lld",&l,&n,&va,&vb);
	for(int i=1;i<=n;++i)
	scanf("%lld%lld",&a[i].h,&a[i].c);
	sort(a+1,a+n+1,cmp);
	LL now,ans=0;
	now=a[1].h*(va-vb);
	ans+=now*a[1].c;
	LL ha=a[1].h,hb=a[1].h;
	for(int i=2;i<=n;++i){
		if(a[i].h>ha)
		ans=ans+a[i].c*(va-vb)*(a[i].h-ha),ha=hb=a[i].h;
	}
	cout<<ans;
	return 0;
}
