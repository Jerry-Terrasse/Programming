#include <cstdio>
#include <algorithm>

#define N 100010

struct Seg
{
	int l, r;
} seg[N];

int n, k;

bool use[N];
int ans = -1;
void dfs(int i, int len, int num)
{
	if(num > k)return;
	
	if(i == n + 1)
	{
		ans = std::max(ans, len);
		return;
	}

	int nl, nr;
	int nxlen = (nr = seg[i].r) - (nl = seg[i].l);
	for(int j = 1; j <= n; j ++)
	if(use[j])nxlen -= nr = (std::min(nr, seg[j].r)) - (nl = std::max(nl, seg[j].l));

	if(nxlen > 0)use[i] = true, dfs(i + 1, len + nxlen, num + 1), use[i] = false;
	
	dfs(i + 1, len, num);
}

int main()
{
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	
	for(int i = 1; i <= n; i ++)
	scanf("%d%d", &seg[i].l, &seg[i].r);
	
	dfs(1, 0, 0);
	
	printf("%d", ans);
	
	return 0;
}
