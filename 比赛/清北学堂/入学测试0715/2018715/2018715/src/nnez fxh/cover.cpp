#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
const int maxn = 100500;
int n, k, ans;
int points[maxn], top, topx;
bool vis[maxn];
struct Node
{
	int l, r;
} a[maxn], now[maxn];
void dfs(int depth)
{
	if(depth > k)
	{
		int res = 0;
		top = 0;
		for(int i=1; i<=k; i++)
		{
			points[++top] = now[i].l;
			points[++top] = now[i].r;
		}
		sort(points+1, points+1+k*2);
		for(int i=1; i<(k<<1); i++)
		{
			for(int j=1; j<=k; j++)
			{
				if(now[j].l <= points[i] && now[j].r >= points[i+1])
				{
					res += points[i+1] - points[i];
					break;
				}
			}
		}
		//printf("%d\n", res);
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
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				vis[i] = true;
				now[++topx] = a[i];
				dfs(depth+1);
				now[topx] = a[0];
				--topx;
				vis[i] = false;
			}
		}
	}
}
int main()
{
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d", &a[i].l, &a[i].r);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
