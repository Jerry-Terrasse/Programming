#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100005

using namespace std;

struct point{
	ll val,high;
}v[N];

ll Va,Vb,top,n;
ll ans,temp,t1,t2,l;

inline bool cmp(const point&a,const point&b){return a.high<b.high;}

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w"stdout);
	scanf("%lld%lld%lld%lld",&top,&n,&Va,&Vb);
	for(int i=1;i<=n;++i) scanf("%lld%lld",&v[i].high,&v[i].val);
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(v[i].high<=top){
			l=v[i].high-v[i-1].high;
			t1=l*Va,t2=l*Vb;temp=t1-t2;
			ans+=(v[i].val*temp);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
