#include <iostream>
#include <cstdio>

class max
{
private:
    static const int maxn = 300000;
    int l, n, va, vb;
    int ans, now;
    int x[maxn], c[maxn];
    bool vis[maxn];

public:
    max(int _n, int _va, int _vb);
    void op();
    friend std::ostream & operator << (std::ostream & os, max & t)
    {
        std::cout << t.ans;
        return os;
    }
};

max::max(int _n, int _va, int _vb) : n(_n), va(_va), vb(_vb)
{
    for (int i = 1; i <= n; ++ i)
        std::cin >> x[i] >> c[i];

    op();
}

void max::op()
{
    int md = -9999;
    for (int i = n; i <= 1; ++ i)
    {
        if (c[i] > md)
        {
            md = c[i];
            vis[i] = true;
        }
    }

    for (int i = 1; i <= n; ++ i)
    {
        if (vis[i] == true)
        {
            int t = (va - vb) * (x[i] - now);
            now = x[i];
            ans += t * c[i];
        }
    }
}

int main()
{
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    int l, n, va, vb;
    std::cin >> l >> n >> va >> vb;
    max _op(n, va, vb);
    std::cout << _op;
    return 0;
}

