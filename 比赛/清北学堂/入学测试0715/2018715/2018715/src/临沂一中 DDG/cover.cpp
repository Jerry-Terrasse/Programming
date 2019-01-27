#include<iostream>
#include<cstdio>
#include<algorithm>
int qr(){
	int ans = 0, f = 1;
	char c = ' ';
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = (ans << 3) + (ans << 1) + c - '0';
		c = getchar();
	}
	return ans * f;
}
int n, k, ans, p, l[100001], r[100001];
bool vis[100001];
void dfs(int x, int y, int z){
	if(y == k){
		ans = std::max(ans, z);
		return;
	}
	if(x > n){
		return;
	}
	int duo = 0;
	for(int i = 1; i <= x-1; i ++){
		if(l[x] < r[i] && vis[i]){
			duo = std::max(r[i] - l[x],duo);
		} 
	}
	vis[x] = 1;
	dfs(x+1, y+1, z + r[x] - l[x] - duo);
	vis[x] = 0;
	dfs(x+1, y, z);
}
int main(){
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	n = qr(), k = qr();
	for(int i = 1; i <= n; i ++){
		l[i] = qr(), r[i] = qr();
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			if(l[i] >= l[j]){
				p = r[i];
				r[i] = r[j];
				r[j] = p;
				p = l[i];
				l[i] = l[j];
				l[j] = p;
			}
		}
	}
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}




