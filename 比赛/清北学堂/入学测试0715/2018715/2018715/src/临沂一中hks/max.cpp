#include <cstdio>
#include <algorithm>
const int MAXN = 100000 + 1;
struct View {
	int x, c;
} views[MAXN];
namespace cmp {
	bool View (::View const &a, ::View const &b) {
		return a.x < b.x;
	}
}
int l, n, va, vb, p = 1, a, b, ans;
int main(int argc, char* const argv[]) {
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	scanf("%d %d %d %d", &l, &n, &va, &vb);
	for (register int i = 1; i <= n; i++) {
		scanf("%d %d", &views[i].x, &views[i].c);
	}
	std::sort(views + 1, views + n + 1, cmp::View);
	for (register int m = 1; m <= l; m++) {
		a += va, b += vb;
		if (m == views[p].x) {
			ans += views[p].c * (va - vb) * (m - views[p - 1].x);
			p++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
