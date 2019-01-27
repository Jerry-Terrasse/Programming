#include<cstdio>
using namespace std;
int n,m,x,y,t,tree[500001];
int lowbit(int a) {
	return a & -a;
}
void add(int k,int a) {
	while(k<=n) {
		tree[k]+=a;
		k+=lowbit(k);
	}
}
int sum(int a) {
	int ans=0;
	while(a!=0) {
		ans+=tree[a];
		a-=lowbit(a);
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&x);
		add(i,x);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)add(x,y);
		if(t==2)printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}
