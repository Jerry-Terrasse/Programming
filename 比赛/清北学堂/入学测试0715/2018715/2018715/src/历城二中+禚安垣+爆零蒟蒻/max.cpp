#include<cstdio>
#include<algorithm>
#define maxn 100010
#define ll long long int

inline void qr(ll &x) {
	char ch=getchar();bool f=false;
	while(ch>'9'||ch<'0') {
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(f) x=-x;
}

inline ll max(const ll &a,const ll &b) {if(a>b)return a;else return b;}
inline ll min(const ll &a,const ll &b) {if(a<b)return a;else return b;}
inline ll abs(const ll &x) {if(x>=0) return x;else return -x;}

inline void swap(ll &a,ll &b) {
	ll temp=a;a=b;b=temp;
}

ll l,n,va,vb,frog[maxn],ta[maxn],tb[maxn];
struct M {
	ll x,c;
};
M MU[maxn];
inline bool cmp(const M &a,const M &b) {
	if(a.x!=b.x)	return a.x<b.x;
	return a.c>b.c;
}

int main() {
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	qr(l);qr(n);qr(va);qr(vb);
	for(int i=1;i<=n;++i) {qr(MU[i].x);qr(MU[i].c);ta[i]=va*MU[i].x;tb[i]=vb*MU[i].x;}
	std::sort(MU+1,MU+1+n,cmp);
	for(int i=1;i<=n;++i) {
		if(MU[i].x==MU[i-1].x)	continue;
		for(int j=0;j<i;++j) {
			frog[i]=max(frog[i],frog[j]+(ta[i]-ta[j]-tb[i]+tb[j])*MU[i].c);
		}
	}
	printf("%lld\n",frog[n]);
	return 0;
}
