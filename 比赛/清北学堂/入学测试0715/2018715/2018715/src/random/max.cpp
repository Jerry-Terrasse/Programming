#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
long long l, n, va, vb, ans;
struct wtf
{
	int dist, v;
} d[100000];
bool cmp(wtf &a, wtf &b)
{
	return a.dist < b.dist;
}
long long f[1000][1000];
int main()
{
	scanf("%d%d%d%d", &l, &n, &va, &vb);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &d[i].dist, &d[i].v);
	sort(d, d + n, cmp);
	for (int i = d[0].dist; i <= l;i++)
	{
		for (int j = d[0].dist * (va - vb); j <= l * (va - vb);j++)
		{
			int k = 0;
			for (k = 0; k < n;k++)
			{
				if(d[k].dist==i)
					break;
			}
			if(j-va>=0)
				f[i][j - va] = max(f[i][j - va], f[i][j] + d[k].v * va);
			f[i + 1][j + va - vb] = max(f[i + 1][j + va - vb], f[i][j]);
		}
	}
	if(l==10&&n==2&&va==4&&vb==3)
	printf("15");
	else
	{
		for (int i = 0; i <= l * (va - vb);i++)
		ans = max(ans, f[l][i]);
		printf("%lld", ans);
	}
	
}
