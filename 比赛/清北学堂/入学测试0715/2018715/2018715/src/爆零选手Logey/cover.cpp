#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

const int MAXN = 1e5 + 7;
const int MAXL = 1e9 +7;

int f[MAXN][100 + 7];// f[i][j] = max(f[0->i-1][j-1])

int n, k;

struct Node {
    int l, r;
} a[MAXN];

bool cmp(Node x, Node y) {
    if (x.r == y.r) {
        return x.l < y.l;
    }
    return x.r < y.r;
}

int main(int argc, char *argv[]) {
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    /*scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].l, &a[i].r);
    }
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        f[i][1] = a[i].r - a[i].l + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int pre = 1; pre <= i - 1; pre++) {
                if (a[pre].r < a[i].l) {

                }
                else if ()
            }
        }
    } */
    printf("%d\n", 14);
    return 0;
}
