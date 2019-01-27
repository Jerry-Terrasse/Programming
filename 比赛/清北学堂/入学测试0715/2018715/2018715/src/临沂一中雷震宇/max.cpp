#include <cstdio>
#include <iostream>

const int MAXN = 1000000 + 7;

int l, n, a, b, d, val, lastd;
int w[MAXN], x[MAXN], ans;
double la, lb, aa;
int main()
{
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	scanf("%d %d %d %d", &l, &n, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &d, &val);
		{
			if (d == lastd)
			{
				i--;
				w[i] = std::max(w[i], val);
				n--;
			}
			else 
			{
				x[i] = d;
				lastd = d;
				w[i] = val;
			}
		}
	}
	aa = (double)1 / a;
	int p = 0;
	while(p <= n)
	{
		for (int i = 1; ; i++)
		{
			if (la + aa > lb)
			{
				break;
			}
			else
			{
				ans += w[p];
				la += aa;
			}
		}
		if (p == n)
		{
			printf("%d\n", ans);
			return 0;			
		}
		p++;
		la += (x[p] - lb) * b / a;
		lb = x[p];
	}

}
