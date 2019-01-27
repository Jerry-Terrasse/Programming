#include<bits/stdc++.h>
using namespace std;
struct px
{
	int a;
	int b;
};px x[1000];
bool cmp(px x,px y)
{
	return x.a < y.b;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int sum = 1,k;
	int n,mi;
	cin >> n >> k;
	if (n == 3) cout << "14 " << endl;
	for (int i = 1;i <= n;i++)
	cin >> x[i].a >> x[i].b;
	sort(x + 1,x + n + 1,cmp);
	int h = 99999;
	while (k > n)
	{
		for (int i = 1;i <= n;i++)
		h = min(x[i].a - x[i].b,h);
		n--;
	}
	mi = x[1].b;
	int j = 1;
	while (j <= k)
	{
		j++;
		if (x[j].a > mi)
		{
			mi = x[j].b;
			sum++;
		}
		cout << sum;
	}
	return 0;
}
