#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL l,n,a,b,num,mmax,ans;
struct hehe{
	LL x;
	LL y; 
}d1[100001],d2[100001];
int cmp(hehe e,hehe f){
	return e.x<f.x;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%lld%lld%lld%lld",&l,&n,&a,&b);
	for(LL i=1;i<=n;++i)
		scanf("%lld%lld",&d1[i].x,&d1[i].y);
	sort(d1+1,d1+n+1,cmp);
	for(LL i=n;i>=1;--i)
		if(d1[i].y>=mmax){
			d2[++num].x=d1[i].x;
			d2[num].y=d1[i].y;
			mmax=d1[i].y;
		}
	for(LL i=1;i<=num;++i)
		ans+=(d2[i].x-d2[i+1].x)*(a-b)*d2[i].y;
	printf("%lld",ans);
	return 0;
}
