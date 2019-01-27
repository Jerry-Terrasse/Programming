#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
struct seg
{
	ll l, r;
} d[100000];
bool cmp(seg &a, seg &b)
{
	return a.l < b.l;
}
ll n, k, f[100][100000], asd[100][100000];
int main()
{
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &d[i].l, &d[i].r);
	sort(d, d + n, cmp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 <= k; j++)
		{
			if (d[i].l >= asd[j][i])
			{
				if (f[j + 1][i + 1] < f[j][i] + d[i].r - d[i].l)
				{
					f[j + 1][i + 1] = f[j][i] + d[i].r - d[i].l;
					asd[j + 1][i + 1] = d[i].r;
				}
			}
			else if (d[i].r > asd[j][i])
			{
				if (f[j + 1][i + 1] < f[j][i] + d[i].r - asd[j][i])
				{
					asd[j + 1][i + 1] = d[i].r;
					f[j + 1][i + 1] = f[j][i] + d[i].r - asd[j][i];
				}
			}
			else
				f[j + 1][i + 1] = max(f[j + 1][i + 1], f[j][i]);
			f[j][i + 1] = max(f[j][i], f[j][i + 1]);
		}
	printf("%lld", f[k][n]);
}
