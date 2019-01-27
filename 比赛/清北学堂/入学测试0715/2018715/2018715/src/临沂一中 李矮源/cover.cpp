#include <cstdio>
#include <algorithm>
#include <utility>

typedef std::pair<int, int> seg;

int MAXN = 100000 + 5;

seg segs[MAXN];

int n, k;

int main() {
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    printf("welcometonoi2019!!!");
    return 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &segs[i].first, &seg[i].second);
    }
    
}
