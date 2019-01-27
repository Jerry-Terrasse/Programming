#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

typedef long long ll;

const int MAXN = 1e5 + 7;

ll l, n, va, vb;

struct Node {
    ll x, c;
} a[MAXN];

bool cmp(Node a, Node b) {
    if (a.c == b.c) {
        return a.c < b.c;
    }
    return a.c > b.c;
}

int main(int argc, char *argv[]) {
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    std::cin >> l >> n >> va >> vb;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].c;
    }
    ll ans = 0, pre = 1, d = 0, t = va - vb;
    std::sort(a + 1, a + n + 1, cmp);
    ans += a[1].c * (a[1].x * t);
    for (int i = 2; i <= n; i++) {
        if (a[i].x > a[pre].x) {
            d = a[i].x - a[pre].x;
            ans += a[i].c * d * t;
            pre = i;
        }
    }
    std::cout << ans << std::endl;;
    return 0;
}
