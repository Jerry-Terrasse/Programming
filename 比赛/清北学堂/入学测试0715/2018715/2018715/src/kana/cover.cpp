#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <utility> 
using namespace std;

int n,k;
int minn = 999999,maxn = -999999;

struct mr {
	int x,y,l;
} c[100000];

bool cmp(mr x,mr y) {
	return x.x < y.x;
}
void dfs(int );
int main() {
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;++i) {
		scanf("%d%d",&c[i].x,&c[i].y);
		c[i].l = c[i].y -c[i].x;
	}
	for(int i = 1;i <= n;++i) {
		minn = min(minn,c[i].x);
		maxn = max(maxn,c[i].y);
	}
	printf("%d\n",maxn - minn);
	return 0; 
}


