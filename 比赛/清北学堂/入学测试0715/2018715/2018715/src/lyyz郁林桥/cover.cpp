#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int read(){
	char ch, c;
	int res;
	while (ch = getchar(), ch < '0' || ch > '9') c = ch;
	res = ch - 48;
	while (ch = getchar(), ch >= '0' && ch <= '9')
	res = (res << 3) + (res << 1) + ch - 48;
	if (c == '-') res = -res;
	return res;
}
int a[10000], b[10000], xi, ci, n, k, s1, s2;
int main(){
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	n = read();
	k = read();
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; i++){
		s1 = min(a[i], a[i + 1]);
		s2 = max(b[i], b[i + 1]);
	}
	int ans = s2 - s1;
	cout << ans << endl;
	return 0;
}
