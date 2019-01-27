#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#define X 1000010

using namespace std;
inline int read() {
	register char c; register int x;
	while(!isdigit(c = getchar())); x = c ^ 48;
	while(isdigit(c = getchar()))x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

int L, n, Va, Vb;

struct Mountains {
	int x;
	int c;
} ba[X];

bool cmp(Mountains a,Mountains b) {
	return a.x < b.x; 
}

int maxn[X];


int main() {
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	L = read(); n = read(); Va = read(); Vb = read();
	for(int i = 1; i <= n; i ++) ba[i].x = read(), ba[i].c = read();
	sort(ba + 1, ba + n + 1,cmp);
	
	maxn[n] = n;
	for(int i = n - 1; i >= 1; i --) 
	if(ba[i].c > ba[maxn[i + 1]].c) maxn[i] = i;
	else maxn[i] = maxn[i + 1];					//µÝÍÆ 
	 
	long long ans = 0;
	
	for(int i = maxn[1], location = 0; i <= n; i = maxn[i] + 1)	{
		ans += (((ba[i].x - location) * Va) - ((ba[i].x - location) * Vb)) * ba[maxn[i]].c;
		location = ba[maxn[i]].x;
	}
	
	printf("%lld", ans);
	
	return 0;
}
