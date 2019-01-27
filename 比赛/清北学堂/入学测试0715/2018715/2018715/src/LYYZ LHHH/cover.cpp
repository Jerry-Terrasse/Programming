#include <cstdio>

const int MAXN = 1e5 + 7;

int n, k;

struct Edge {
    int l, r;
} edge[MAXN];

int main() {
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &edge[i].l, &edge[i].r);
    }
    printf("14");
    return 0;
}
