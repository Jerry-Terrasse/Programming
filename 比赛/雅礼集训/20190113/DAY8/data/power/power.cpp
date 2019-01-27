#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int M = 4000;
const int mo = 998244353;

void add(int &x, int y) {
    (x += y) >= mo ? x -= mo : 0;
}

int fpm(int x, int y) {
    int res = 1;
    for(; y > 0; y >>= 1) {
        if(y & 1)
            res = 1ll * res * x % mo;
        x = 1ll * x * x % mo;
    }
    return res;
}

int fac[N + 5], inv[N + 5];

int binom(int x, int y) {
    return 1ll * fac[x] * inv[y] % mo * inv[x-y] % mo;
}

void init() {
    fac[0] = 1;
    for(int i = 1; i <= N; ++i) fac[i] = 1ll * fac[i-1] * i % mo;
    inv[N] = fpm(fac[N], mo - 2);
    for(int i = N; i >= 1; --i) inv[i-1] = 1ll * inv[i] * i % mo;
}

int sl, sr;
int n, k, a;
int l[N + 5], r[N + 5];

int calc(int s, int x) {
    int res = 0;
    for(int i = 0; i < n; ++i) {
        if(i & 1) {
            res = (res - 1ll * binom(n-1, i) * fpm(x, i+k+1) % mo * fpm(s, n-1-i) % mo * inv[n-1] % mo * fpm(i+k+1, mo - 2)) % mo;
        } else {
            res = (res + 1ll * binom(n-1, i) * fpm(x, i+k+1) % mo * fpm(s, n-1-i) % mo * inv[n-1] % mo * fpm(i+k+1, mo - 2)) % mo;
        }
    }
    return (res + mo) % mo;
}

void input() {
    init();
    scanf("%d%d%d", &n, &k, &a);
    if(k % 2 == 0) a = max(a, -a);

    for(int i = 0; i < n; ++i) {
        scanf("%d%d", l + i, r + i);

        sl += l[i], sr += r[i];
        if(l[i] == r[i]) -- i, -- n;
    }

    if(!n) {
        if((k & 1) ^ 1) {
            printf("%d\n", (fpm(std::max(abs(sl), abs(a)), k) + mo) % mo);
        } else {
            printf("%d\n", (fpm(std::max(sl, a), k) + mo) % mo);
        }
        exit(0);
    }
}

void solve() {
    static int f[N * M + 5];

    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        int len = r[i] - l[i];
        for(int j = N * M - len; j >= 0; --j) {
            add(f[j + len], mo - f[j]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= N * M; ++i) if(f[i]) {
        static int s;

        if((s = sl + i) <= a) ans = (ans + 1ll * f[i] * fpm(a, k) % mo * fpm(a - s, n) % mo * inv[n]) % mo;    
        if((s = sr - i) >= a) ans = (ans + 1ll * f[i] * (calc(s, s) - calc(s, a) + mo)) % mo;

        if(k % 2 == 0) {
            if((s = sl + i) <=-a) ans = (ans - 1ll * f[i] * fpm(a, k) % mo * fpm(-a - s, n) % mo * inv[n]) % mo;
            if((s = sl + i) <=-a) ans = (ans + 1ll * f[i] * (calc(-s, -s) - calc(-s, a) + mo)) % mo;
        } 
    }
    for(int i = 0; i < n; ++i) ans = 1ll * ans * fpm(r[i] - l[i], mo - 2) % mo;

    ans = (ans + mo) % mo;
    printf("%d\n", ans);
}

int main() {

    input();
    solve();

    return 0;
}
