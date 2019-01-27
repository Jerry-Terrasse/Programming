#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 301;
struct Edge
{
	int x, y;
}a[MAXN];
int n, k, ans, size = 1;

bool cmp(Edge a, Edge b)
{
	return a.x < b.x;
}

int main()
{
	//freopen("cover.in", "w", stdin);
	//freopen("cover.out", "r", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1, cmp);
	int y;
	for (int i = 1; i <= n - k; i ++)
	{
	    for (int j = i + 1; j <= n; j ++)
	    {
	    	if(a[j].x < a[i].y && size < k)
	    	{
	    		y = max(y, a[j].y);
			}
		}
		ans = y - a[i].x;
		size ++;
	}
	printf("%d", ans);
	return 0;
}
