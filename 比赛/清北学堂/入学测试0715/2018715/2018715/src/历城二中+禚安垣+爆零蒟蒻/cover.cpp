#include<cstdio>
#include<algorithm>
#define maxn 100010

inline void qr(int &x) {
	char ch=getchar();bool f=false;
	while(ch>'9'||ch<'0') {
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(f) x=-x;
}

inline int max(const int &a,const int &b) {if(a>b)return a;else return b;}
inline int min(const int &a,const int &b) {if(a<b)return a;else return b;}
inline int abs(const int &x) {if(x>=0) return x;else return -x;}

inline void swap(int &a,int &b) {
	int temp=a;a=b;b=temp;
}

int n,k,ans;
struct M {
	int l,r;
};
M MU[maxn];
int frog[maxn][110];
inline bool cmp(const M &a,const M &b) {
	if(a.r!=b.r)	return a.r<b.r;
	return a.l<b.l;
}

int main() {
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	qr(n);qr(k);
	for(int i=1;i<=n;++i) {
		qr(MU[i].l);qr(MU[i].r);
	}
	std::sort(MU+1,MU+1+n,cmp);
	for(int i=1;i<=n;++i) {
		frog[i][1]=MU[i].r-MU[i].l;
		for(int j=k;j>1;--j) {
			for(int h=0;h<i;++h) {
				if(MU[h].r<=MU[i].l) frog[i][j]=max(frog[i][j],frog[h][j-1]+MU[i].r-MU[i].l);
				else frog[i][j]=max(frog[i][j],frog[h][j-1]+MU[i].r-MU[h].r);
			}
		}
		ans=max(ans,frog[i][k]);
	}
	printf("%d\n",ans);
	return 0;
}
