#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int l, n, va, vb;
struct node
{
	int x, c;
};
node jd[100500];

bool cmp1(node a, node b)
{
	if(a.x == b.x)
	{
		return a.c < b.c;
	}
	return a.x < b.x;
}

int main()
{
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	cin>>l>>n>>va>>vb;
	for(int i = 1; i <= n; i++)
	{
		cin>>jd[i].x>>jd[i].c;
	}
	sort(jd + 1, jd + n + 1, cmp1);
	jd[0].x = 0, jd[0].c = 0;
	int z = 0;
	long long ans = 0;
	while(z < n)
	{
		int hi = jd[z + 1].c, temp = z + 1;
		for(int i = z + 1; i <= n; i++)
		{
			if(hi < jd[i].c)
			{
				hi = jd[i].c;
				temp = i;
			}
		}
		long long tm = (jd[temp].x - jd[z].x) * (va - vb);
		ans += tm * jd[temp].c;
		z = temp;
	}
	cout<<ans;
	return 0;
}
