#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int S = 1 << 20;
const int mo = 1e9 + 7;
const long long moS = 1ll * (LLONG_MAX / mo / 2) * mo;

int n;
inline void add(int &x, int y) { (x += y) >= mo ? x -= mo : 0; }
inline void sub(int &x, int y) { (x -= y) < 0 ? x += mo : 0; }
inline void addS(long long &x, long long y) {
    (x += y) >= moS ? x -= moS : 0;
}

void add(int *x, int *y) { for(int i = 0; i <= n; ++i) add(x[i], y[i]); }
void sub(int *x, int *y) { for(int i = 0; i <= n; ++i) sub(x[i], y[i]); }
void div(int *x, int *y) {
    static int z[N + 5];
    static long long t[N + 5];

    memset(t, 0, sizeof t);

    t[0] = mo - 1;
    for(int i = 0; i <= n; ++i) {
        z[i] = mo - (t[i] % mo);
        for(int j = 0; i + j <= n; ++j) {
            addS(t[i + j], 1ll * z[i] * y[j]);
        }
    }

    memset(t, 0, sizeof t);

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; i + j <= n; ++j) {
            addS(t[i + j], 1ll * x[i] * z[j]);
        }
    }

    for(int i = 0; i <= n; ++i) x[i] = t[i] % mo;
}

int t[S];
int c[N][N], f[S][N], g[S][N];

int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n - i; ++j) {
            scanf("%d", c[i] + i + j);
            c[i + j][i] = c[i][i + j];
        }
    }

    g[0][0] = t[0] = 1;

    for(int i = 1; i < (1 << n); ++i) {
        int u = __builtin_ctz(i), cnt = __builtin_popcount(i);

        t[i] = t[i ^ (1 << u)];
        for(int k = 0; k < n; ++k) if((i ^ (1 << u)) >> k & 1) {
            t[i] = 1ll * t[i] * (c[u][k] + 1) % mo;
        }

        f[i][cnt] = t[i];

        if((i & 1) ^ 1) {
            g[i][cnt] = t[i];
        }
    }

    for(int j = 0; j < n; ++j) {
        for(int i = 1; i < (1 << n); ++i) if(i >> j & 1) {
            add(f[i], f[i ^ (1 << j)]);
            add(g[i], g[i ^ (1 << j)]);
        }
    }
    for(int i = 0; i < (1 << n); ++i) div(f[i], g[i]);
    for(int j = 0; j < n; ++j) {
        for(int i = 1; i < (1 << n); ++i) if(i >> j & 1) {
            sub(f[i], f[i ^ (1 << j)]);
        }
    }

    printf("%d\n", f[(1 << n) - 1][n]);
    return 0;
}
