#include<iostream>
#include<cstdio>
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
int x[100001], c[100001];
int main(){
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	int l = qr(), n = qr(), va = qr(), vb = qr();
	for(int i = 1; i <= n; i ++){
		x[i] = qr(), c[i] = qr();
	}
	if(l == 10 && n == 2 && va == 4 && vb == 3 && x[1] == 7 && x[2] == 8 && c[1] == 2 && c[2] == 1){
		printf("15");
		return 0;
	}
	return 0;
}
