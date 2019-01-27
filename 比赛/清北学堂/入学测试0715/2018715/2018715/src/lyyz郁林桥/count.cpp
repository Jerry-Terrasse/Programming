#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10001;
typedef long long LL;
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
int ans = 0, num = 0;
char a[maxn][maxn];
int main(){
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int n = 3;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	if (a[1][1] == a[1][2] == a[1][3]) num++;
	if (a[2][1] == a[2][2] == a[2][3]) num++;
	if (a[3][1] == a[3][2] == a[3][3]) num++;
	if (a[1][1] == a[2][1] == a[3][1]) num++;
	if (a[1][2] == a[2][2] == a[3][2]) num++;
	if (a[1][3] == a[2][3] == a[3][3]) num++;
	if (a[1][1] == a[2][2] == a[3][3]) num++;
	if (a[1][3] == a[2][2] == a[3][1]) num++;
	if (a[1][1] == a[1][2] || a[1][2] == a[1][3] || a[1][3] == a[1][1]) ans++;
	if (a[2][1] == a[2][2] || a[2][2] == a[2][3] || a[2][3] == a[2][1]) ans++;
	if (a[3][1] == a[3][2] || a[3][2] == a[3][3] || a[3][3] == a[3][1]) ans++;
	if (a[1][1] == a[2][1] || a[1][1] == a[3][1] || a[2][1] == a[3][1]) ans++;
	if (a[1][2] == a[2][2] || a[2][2] == a[3][2] || a[1][2] == a[3][2]) ans++;
	if (a[1][3] == a[2][3] || a[1][3] == a[3][3] || a[2][3] == a[3][3]) ans++;
	if (a[1][1] == a[2][2] || a[1][1] == a[3][3] || a[2][2] == a[3][3]) ans++;
	if (a[1][3] == a[2][2] || a[1][3] == a[3][1] || a[2][2] == a[3][1]) ans++;
	cout << num << endl;
	cout << ans << endl;
	return 0;
}
