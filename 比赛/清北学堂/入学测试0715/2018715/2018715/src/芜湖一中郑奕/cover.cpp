#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Maxn=100005;
int n,k,now[Maxn],sum,ans;
struct node {
	int l,r;
} a[Maxn];
struct V {
	int val,ve;
} v[Maxn];
bool cmp(V x,V y) {
	if(x.ve!=y.ve)return x.ve<y.ve;
	return x.val<y.val;
}
inline int mx(int x,int y) {
	return x>y?x:y;
}
void update() {
	sum=0;
	for(int i=1; i<=n; i++) {
		if(now[i]==1) {
			v[++sum].val=-1;
			v[sum].ve=a[i].l;
			v[++sum].val=1;
			v[sum].ve=a[i].r;
		}
	}
	sort(v+1,v+1+sum,cmp);
	int ss=0,xx=0;
	for(int i=1; i<=sum-1; i++) {
		if(v[i].val==-1)ss++;
		if(ss>=1)xx+=v[i+1].ve-v[i].ve;
		if(v[i].val==1)ss--;
	}
	ans=mx(ans,xx);
}
void dfs(int i,int step) {
	if(i==n+1) {
		update();
		return;
	}
	if(step<k) {
		now[i]=1;
		dfs(i+1,step+1);
		now[i]=0;
		dfs(i+1,step);
	} else {
		now[i]=0;
		dfs(i+1,step);
	}
}
int main() {
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}

