#include <cstdio>
#include <algorithm>

typedef long long ll;
const int MAXN=100010;
int L, n, Va, Vb;
ll ans;

struct pii {
	int x, c;
} m[MAXN];

bool cmp(pii a, pii b) {
	return a.x<b.x;
}

int main() {
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	scanf("%d%d%d%d", &L, &n, &Va, &Vb);
	int cha=Va-Vb;
	for(int i=0; i<n; i++) scanf("%d%d", &m[i].x, &m[i].c);
	std::sort(m, m+n, cmp);
	for(int i=1; i<n; i++) m[i].x=m[i].x-m[i-1].x;
	for(int i=0; i<n; i++) {
		ans+=(ll)m[i].x*cha*m[i].c;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
