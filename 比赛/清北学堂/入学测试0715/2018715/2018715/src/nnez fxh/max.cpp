#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
const int maxn = 100500;
int L, n, va, vb, ans;
int x[maxn], c[maxn], now[maxn], t[maxn];
void dfs(int depth)
{
	if(depth > n)
	{
		int res = 0, lastnum = 0, lasth = 0;
		for(int i=1; i<=n; i++)
		{
			if(now[i] == 2)
			{
				res += (va - vb) * (x[i] - x[lastnum]) * c[i];
				lastnum = i;
			}
			
		}
		ans = max(ans, res);
		if(clock() > 980)
		{
			printf("%d", ans);
			exit(0);
		}
	}
	else
	{
		if(clock() > 980)
		{
			printf("%d", ans);
			exit(0);
		}
		for(int i=1; i<=2; i++)
		{
			if(i==1) now[depth] = 1;
			else now[depth] = 2;
			dfs(depth+1);
		}
	}
}
int main()
{
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	scanf("%d %d %d %d", &L, &n, &va, &vb);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d", &x[i], &c[i]);
	}
	dfs(1);
	//printf("15\n");
	printf("%d", ans);
	return 0;
}
