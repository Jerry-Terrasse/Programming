#include <cstdio>
#include <cctype>
#include <algorithm>

#define N 1000010

inline int read()
{
	register char c; register int x;
	while(!isdigit(c = getchar())); x = c ^ 48;
	while(isdigit(c = getchar()))x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

int L, n, Va, Vb;

struct HAHA
{
	int x, c;
} ha[N];

bool operator < (const HAHA a, const HAHA b)
{
	return a.x < b.x;
}

int maxn[N];

int main()
{
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	
	L = read(); n = read(); Va = read(); Vb = read();
	
	for(int i = 1; i <= n; i ++)
	ha[i].x = read(), ha[i].c = read();
	
	std::sort(ha + 1, ha + n + 1);
	
	maxn[n] = n;
	for(int i = n - 1; i >= 1; i --)
	if(ha[i].c > ha[maxn[i + 1]].c)maxn[i] = i;
	else maxn[i] = maxn[i + 1];
	
	long long ans = 0;
	
	for(int i = maxn[1], now = 0; i <= n; i = maxn[i] + 1)
	{
		ans += (((ha[i].x - now) * Va) - ((ha[i].x - now) * Vb)) * ha[maxn[i]].c;
		now = ha[maxn[i]].x;
	}
	
	printf("%lld", ans);
	
	return 0;
}
