#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int oo = 0x3f3f3f3f;

template <typename T> inline bool chkmin(T& a, T b) {
    return a > b ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T& a, T b) {
    return a < b ? a = b, 1 : 0;
}

struct info {
    int mx, smx, mn, id;

    info() { 
        mn = oo;
        mx = smx = -oo; 
    }

    void upd(int sz, int v) {
        chkmin(mn, sz);
        if(sz > mx) {
            smx = mx, mx = sz, id = v;
        } else chkmax(smx, sz);
    }
};

int n, rt = 1;
info t[N + 5];
vector<int> G[N + 5], bit[N + 5];
int ans[N + 5], fa[N + 5], sz[N + 5], dfn[N + 5], dfc;

void pre_dfs(int u, int f = 0) {
    fa[u] = f;
    sz[u] = 1;
    dfn[u] = ++ dfc;

    for(auto v : G[u]) if(v != f) {
        pre_dfs(v, u);
        sz[u] += sz[v];
        t[u].upd(sz[v], v);
    }
}

inline int calc(const vector<int> &x, int l, int r) {
    return upper_bound(x.begin(), x.end(), r) - lower_bound(x.begin(), x.end(), l);
}

int c[N + 5];
void dfs(int u, int f = 0) {
    if(G[u].size() > 1) {
        int l = max(t[u].smx, (t[u].mx + t[u].mn) / 2), r = t[u].mx;
        while(l < r) {
            int mid = (l + r) >> 1;
            int liml = t[u].mx - mid - 1, limr = mid - t[u].mn;

            int cnt = 0;
            if(t[u].id == fa[u]) {
                for(int i = limr; i > 0; i -= (i & -i)) cnt += (int) bit[i].size() - calc(bit[i], dfn[u], dfn[u] + sz[u] - 1) - c[i];
                for(int i = liml; i > 0; i -= (i & -i)) cnt -= (int) bit[i].size() - calc(bit[i], dfn[u], dfn[u] + sz[u] - 1) - c[i];
                for(int i = min(limr + sz[u], n); i > 0; i -= (i & -i)) cnt += c[i];
                for(int i = min(liml + sz[u], n); i > 0; i -= (i & -i)) cnt -= c[i];
            } else {
                for(int i = limr; i > 0; i -= (i & -i)) cnt += calc(bit[i], dfn[t[u].id], dfn[t[u].id] + sz[t[u].id] - 1);
                for(int i = liml; i > 0; i -= (i & -i)) cnt -= calc(bit[i], dfn[t[u].id], dfn[t[u].id] + sz[t[u].id] - 1);
            }

            if(cnt > 0) 
                r = mid;
            else 
                l = mid + 1;
        }
        chkmin(ans[u], l);
    }

    for(int i = sz[u]; i <= n; i += (i & -i)) ++ c[i];
    for(auto v : G[u]) if(v != f) dfs(v, u);
    for(int i = sz[u]; i <= n; i += (i & -i)) -- c[i];
}

int main() {

    scanf("%d", &n);
    if(n == 1) return puts("0"), 0;
    for(int i = 2; i <= n; ++i) {
        static int u, v;
        u = i;
        scanf("%d", &v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    pre_dfs(rt);
    for(int i = 1; i <= n; ++i) {
        if(i != rt)
            t[i].upd(n - sz[i], fa[i]);

        ans[i] = t[i].mx;
        for(int j = sz[i]; j <= n; j += (j & -j)) {
            bit[j].push_back(dfn[i]);
        }
    }
    for(int i = 1; i <= n; ++i) sort(bit[i].begin(), bit[i].end());
    dfs(rt);
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);

    return 0;
}
