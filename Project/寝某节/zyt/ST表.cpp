#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,l,r,st[1000001][21];
int query(int l,int r) {
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&st[i][0]);
	for(int i=1; i<=21; i++)
		for(int j=1; j+(1<<i)-1<=n; j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	while(m--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
