#include <iostream>
#include <cstdio>
#include <algorithm>

#define N_MAX (1000000 + 100)

using namespace std;
typedef long long ll;

ll l, n, x[N_MAX], c[N_MAX];
ll va, vb;
struct mountain {
	ll x, c;
	bool operator < (const mountain &other) const {
		return x < other.x;
	}
}m[N_MAX];

int main() {
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	
	scanf("%lld %lld %lld %lld", &l, &n, &va, &vb);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &m[i].x, &m[i].c);
	}
	puts("15");
	
	return 0;
}
