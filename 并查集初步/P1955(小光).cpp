// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define nc() getchar()

const int maxn = 1e5 + 10;
int T, n, m, a[3][maxn], par[maxn << 1], rk[maxn << 1];

set <int> s;
map <int, int> mapp;

inline void read(register int& x) {
    x = 0;
    register char ch = nc();
    for (; ch < 48 || ch > 57; ch = nc());
    for (; ch > 47 && ch < 58; x = (x << 3) + (x << 1) + (ch ^ 48), ch = nc());
}

inline int find(const int& x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

inline void unite(register int x, register int y) {
    x = find(x), y = find(y);
    if (rk[x] > rk[y]) {
        if (x ^ y) {
            x ^= y ^= x ^= y;
        }
    }
    par[x] = y;
    if (rk[x] == rk[y]) {
        rk[y]++;
    }
}

int main() {
    read(T);
    for (; T--; ) {
        s.clear(), mapp.clear();
        read(m);
        for (int i = 1; i <= m; i++) {
            read(a[1][i]), read(a[2][i]), read(a[0][i]);
            s.insert(a[1][i]), s.insert(a[2][i]);
        }
        n = s.size();
        register auto iter = s.begin();
        for (register int i = 1; i <= n; i++, iter++) {
            par[i] = i, rk[i] = 1;
            mapp.insert(make_pair(*iter, i));
        }
        register bool flag = 1;
        for (register int i = 1; i <= m; i++) {
            a[1][i] = mapp.find(a[1][i]) -> sec;
            a[2][i] = mapp.find(a[2][i]) -> sec;
            if (a[0][i]) {
                unite(a[1][i], a[2][i]);
            }
        }
        for (register int i = 1; i <= m; i++) {
            if (!a[0][i] && find(a[1][i]) == find(a[2][i])) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}