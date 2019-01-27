#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
struct interest
{
	int x, c;
	bool operator < (interest B) const
	{
		if(c==B.c) return x>B.x;
		else return c>B.c;
	}
}a[N];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int l, n, va, vb, pos=0, ans=0;
	scanf("%d%d%d%d", &l, &n, &va, &vb);
	for(int i=1; i<=n; i++)
		scanf("%d%d", &a[i].x, &a[i].c);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		int px=a[i].x-pos;
		if(px<=0) continue;
		ans+=px*(va-vb)*a[i].c;
		pos+=px;
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}