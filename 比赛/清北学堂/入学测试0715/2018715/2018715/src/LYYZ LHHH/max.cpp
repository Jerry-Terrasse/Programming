#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MAXN = 1e5 + 7;
const LL INF = 0x3f3f3f3f;

LL l, n, Va, Vb;
LL ans, d;

struct Node {
    LL x, c;
} view[MAXN];

int cmp(Node a, Node b) {
    if (a.c == b.c) {
        return a.x < b.x;
    }
    return a.c > b.c;
}

int main() {
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    scanf("%lld%lld%lld%lld", &l, &n, &Va, &Vb);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &view[i].x, &view[i].c);
    }

    int t = Va - Vb;
    std::sort(view+1, view+n+1, cmp);

    int pre = 1;
    ans += view[1].c * (view[1].x * t);
    for (int i = 2; i <= n; i++) {
        if (view[i].x > view[pre].x) {
            d = view[i].x - view[pre].x;
            ans += view[i].c * (d * t);
            pre = i;
        }
    }
    printf ("%lld", ans);
    return 0;
}

/*
10 2 4 3
7 2
8 1
*/
