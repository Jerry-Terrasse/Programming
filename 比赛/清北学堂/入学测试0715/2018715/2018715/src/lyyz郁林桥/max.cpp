#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
inline LL read(){
	char ch, c;
	LL res;
	while (ch = getchar(), ch < '0' || ch > '9') c = ch;
	res = ch - 48;
	while (ch = getchar(), ch >= '0' && ch <= '9')
	res = (res << 3) + (res << 1) + ch - 48;
	if (c == '-') res = -res;
	return res; 
}
struct Edge{
	LL to;
	LL val;
}e[100001];
LL L, n, Va, Vb, ci, xi;
int main(){
    freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	int tot = 15, num = 0;
	L = read();
	n = read();
	Va = read();
	Vb = read();
	for (LL i = 1; i <= n; i++){
		cin >> e[i].to >> e[i].val;
	} 
	for (LL i = 1; i <= n; i++){
		for (num = 0; num <= e[i].to; num++){
			num++;
		} 
		while (num == e[i].to) tot = tot + e[i].val * (num * Va - num * Vb);
	}
	cout << tot << endl;
	return 0;
}
