#include<cstdio>
using namespace std;
#define LL long long
#define MAX 100000+1
int n,m,p,t,x,y;
LL k;
LL a[MAX];
struct node {
	LL w,mul,add;
} T[MAX<<2];
void build(int rt,int l,int r) {
	T[rt].mul=1;
	T[rt].add=0;
	if(l==r)
		T[rt].w=a[l];
	else {
		int m=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
		build(ls,l,m);
		build(rs,m+1,r);
		T[rt].w=T[ls].w+T[rs].w;
	}
	T[rt].w%=p;
}
void push_down(int rt,int l,int r) {
	int m=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
	T[ls].w=(T[rt].mul*T[ls].w+T[rt].add*(m-l+1))%p;
	T[rs].w=(T[rt].mul*T[rs].w+T[rt].add*(r-m))%p;
	T[ls].mul=(T[rt].mul*T[ls].mul)%p;
	T[rs].mul=(T[rt].mul*T[rs].mul)%p;
	T[ls].add=(T[rt].mul*T[ls].add+T[rt].add)%p;
	T[rs].add=(T[rt].mul*T[rs].add+T[rt].add)%p;
	T[rt].mul=1;
	T[rt].add=0;
}
void up_mul(int rt,int l,int r) {
	if(l>y || r<x)
		return;
	if(l>=x && r<=y) {
		T[rt].w=(T[rt].w*k)%p;
		T[rt].mul=(T[rt].mul*k)%p;
		T[rt].add=(T[rt].add*k)%p;
		return;
	}
	push_down(rt,l,r);
	int m=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
	up_mul(ls,l,m);
	up_mul(rs,m+1,r);
	T[rt].w=(T[ls].w+T[rs].w)%p;
}
void up_add(int rt,int l,int r) {
	if(l>y || r<x)
		return;
	if(l>=x && r<=y) {
		T[rt].w=(T[rt].w+k*(r-l+1))%p;
		T[rt].add=(T[rt].add+k)%p;
		return;
	}
	push_down(rt,l,r);
	int m=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
	up_add(ls,l,m);
	up_add(rs,m+1,r);
	T[rt].w=(T[ls].w+T[rs].w)%p;
}
LL query(int rt,int l,int r) {
	if(l>y || r<x)
		return 0;
	if(l>=x && r<=y)
		return T[rt].w;
	push_down(rt,l,r);
	int m=(l+r)>>1,ls=rt<<1,rs=rt<<1|1;
	return (query(ls,l,m)+query(rs,m+1,r))%p;
}
int main() {
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&t,&x,&y);
		if(t==1) {
			scanf("%lld",&k);
			up_mul(1,1,n);
		} else if(t==2) {
			scanf("%lld",&k);
			up_add(1,1,n);
		} else if(t==3)
			printf("%lld\n",query(1,1,n));
	}
	return 0;
}
