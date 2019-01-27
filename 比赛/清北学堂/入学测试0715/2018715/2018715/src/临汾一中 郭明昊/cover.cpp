#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int t[N], n, k, last, ans;
bool del[N];
struct line
{
	int l, r;
	bool operator < (line B)const
	{
		return l<B.l;
	}
}a[N];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d%d", &a[i].l, &a[i].r);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		if(a[i].r<=last) del[i]=1;
		else last=a[i].r;
	for(int i=1; i<=n; i++)
		if(del[i]) swap(a[i], a[n--]);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		ans=max(ans, a[i].r-a[i].l);
		if(k>=2)
		for(int j=i+1; j<=n; j++)
			if(a[i].r<=a[j].l) ans=max(ans, a[j].r-a[j].l+a[i].r-a[i].l);
			else ans=max(ans, a[j].r-a[i].l);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}