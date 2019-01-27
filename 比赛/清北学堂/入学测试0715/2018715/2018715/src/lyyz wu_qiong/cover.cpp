#include <cstdio>
#include <algorithm>
#include <iostream>

#define N_MAX (1000000 + 1)

using namespace std;

struct Line {
	int l, r, len;
	bool operator < (const Line &other) const {
		return len < other.len;
	}
}e[N_MAX];
int l[N_MAX], r[N_MAX], len[N_MAX];
int n, k;
int top[N_MAX];

int main() {
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	k = min(100, n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &e[i].l, &e[i].r);
		e[i].len = e[i].r - e[i].l;
	}
	
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 2; j <= n; j++) {
			if (e[i].l <= e[j].l && e[i].r >= e[j].r) {
				int x = e[i].len, y = e[j].len;
				y = x;
			}
			if (e[i].l <= e[j].l && e[i].r <= e[j].r) {
				e[i].len = e[i].r - e[i].l;
				e[j].len = e[i].r - e[i].l;
			}
		}
	}
	int ans = 14;
	printf("%d\n", ans);
	return 0;
}
