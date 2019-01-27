#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cmath> 
using namespace std;

int l,n,va,vb;
int t;
int ans;
struct mr {
	int x;
	int c;
} a[100000]; 
void dfs(int ,int ,int );

int main() {
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	t = (va - vb) * l; // 一共御魔的时间 
	for(int i = 1;i <= n;++i) scanf("%d%d",&a[i].x,&a[i].c);
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}
void dfs(int z,int q,int za) { //当前位置 颓废  与a相遇时间 
	if(za < 0) return ;
	if(z == l) {
		ans = max(ans,q);
		return ;
	}
	//cout << za << endl << endl;
	for(int i = 1;i <= n;++i) {
		if(z == a[i].x) {
			for(int j = 1;j <= za;++j)
				dfs(z,q + a[i].c * j,za - j);
		}
	}
	dfs(z + 1,q,za + va - vb); 	
}
