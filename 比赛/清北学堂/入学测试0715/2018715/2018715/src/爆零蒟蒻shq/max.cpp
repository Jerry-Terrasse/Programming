#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

#include <vector>
#include <stack>

typedef long long lhhh;

const int MAXN = 1000000 + 10;
const lhhh INF = 0x3f3f3f;

class Node {
public:
    lhhh left, right;
} a[MAXN];

int cmp (Node a, Node b) {
    return a.right == b.right ? a.left < b.left : a.right > b.right;
}

inline lhhh SlowRead () {
    char ch = 0;
    lhhh data = 0, f = 1;

    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while  (ch >= '0' && ch <= '9') {
        data = data * 10 + ch - '0';
        ch = getchar();
    }

    return data * f;
}

lhhh l, n, b, f;
lhhh ans, d;
int pre = 1;

int main(int argc, char const *argv[]) {
    freopen ("max.in", "r", stdin);
    freopen ("max.out", "w", stdout);

    memset (a, 0, sizeof (a));

    l = SlowRead(); n = SlowRead();
    f = SlowRead(); b = SlowRead();

    for (int i = 1; i <= n; i++) {
        a[i].left = SlowRead();
        a[i].right = SlowRead();
    }

    int t = f - b;

    std::sort (a + 1, a + n + 1, cmp);

    ans += a[1].right * (a[1].left * t);

    for (int i = 2; i <= n; i++) {
        if (a[i].left > a[pre].left) {
            d = a[i].left - a[pre].left;
            ans += a[i].right * (d * t);
            pre = i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
