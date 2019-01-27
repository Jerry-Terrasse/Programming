#include <iostream>
#include <algorithm>

static const int maxn = 4001;
int n, k;
int ans;
struct node
{
    long long l, r;
}e[maxn];

bool cmp(const node &a, const node &b);

int main()
{
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    {
        std::cin >> e[i].l >> e[i].r;
    }

    std::sort(e+1, e+1+n, cmp);

    for (int i = 1; i <= k; ++ i)
    {
        ans = 0;
        for (int j = i+1; j <= k; ++ j)
        {
            if (e[j].l <= e[i].r)
            {
                ans += e[j].r - e[i].l;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
}

bool cmp(const node & a, const node & b)
{
    if (a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}
