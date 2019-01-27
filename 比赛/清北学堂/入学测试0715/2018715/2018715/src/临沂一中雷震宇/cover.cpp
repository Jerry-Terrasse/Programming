#include <cstdio>
#include <iostream>

const int MAXN = 100000 + 7;

int n, k, l[MAXN], r[MAXN], P, ans;
bool vis[MAXN];

void dfs(int x, int y, int z)
{
	if (y == k)
	{
		ans = std::max(ans, z);
		return;
	}
	if (x == n + 1) return;
	int duo = 0;
	for (int i = 1; i <= x - 1; i++)
	{
		if (l[x] < r[i] && vis[i])
		duo = std::max(r[i] - l[x], duo);
	}
	vis[x] = 1; 	
	dfs(x + 1, y + 1, z + r[x] - l[x] - duo);
	vis[x] = 0;
	dfs(x + 1, y, z);
}

int main()
{
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (l[i] >= l[j])
			{
				P = r[i];
				r[i] = r[j];
				r[j] = P;
				P = l[i];
				l[i] = l[j];
				l[j] = P;
			}
		}
	}
	dfs(1, 0, 0);
	printf("%d\n", ans);
	
}
