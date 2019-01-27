#include <cstdio>
#include <algorithm>
#define NoLessThanZero(X) ((X) < 0 ? 0 : (X))
const int MAXN = 100000 + 1;
struct Segment {
	int l, r;
	bool isin(int const &i, int const &j) {
		return (i > l && j < r);
	}
};
Segment segs[MAXN], fullSeg;
int n, k, lessLen[MAXN], e, f;
bool killed[MAXN];
namespace cmp {
	bool Segment(::Segment const &a, ::Segment const &b) {
		return (a.r - a.l) < (b.r - b.l);
	}
}
void print() {
	printf("%d", fullSeg.r - fullSeg.l);
}
int main(int argc, char* const argv[]) {
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%d %d", &n, &k);
	fullSeg.l = 2147483647, fullSeg.r = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &segs[i].l, &segs[i].r);
		fullSeg.l = std::min(segs[i].l, fullSeg.l);
		fullSeg.r = std::max(segs[i].r, fullSeg.r);
	}
	std::sort(segs, segs + n, cmp::Segment);
	for (int i = 0; i < n; i++) {
		if (fullSeg.isin(segs[i].l, segs[i].r)) {
			killed[i] = 1;
			e++;
			if (n - e <= k) {
				print();
				return 0;
			}
			continue;
		}
	}
	for (int i = 0; i < n; i++) {
		if (killed[i]) continue;
		else {
			lessLen[f++] = NoLessThanZero(fullSeg.l - segs[i].l) + NoLessThanZero(segs[i].r - fullSeg.r);
		}
	}
	std::sort(lessLen, lessLen + f);
	for (int i = 0; i < (n - e - k > f) ? (n - e - k) : f; i++)
		fullSeg.r -= lessLen[i];
	print();
	return 0;
}
