#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, k;
long long ans;
struct node 
{
	int l, r;
};
node xd[100500];

bool cmp1(node a, node b)
{
	if(a.l == b.l)
	{
		return a.r > b.r;
	}
	return a.l < b.l;
}

void dfs(int step, int chosen, long long tot, int lst)
{
	if(chosen == k)
	{
		if(ans < tot)
		{
			ans = tot;
		}
		return;
	}
	if(step == n)
	{
		return;
	}
	for(int i = 0; i <= 1; i++)
	{
		if(i == 1)
		{
			dfs(step + 1, chosen, tot, lst);
		}
		else
		{
			int temp = tot + xd[step + 1].r - xd[step + 1].l;
			bool flag1 = 0;
			if(xd[lst].r >= xd[step + 1].l)
			{
				flag1 = 1;
				temp = temp - xd[lst].r + xd[step + 1].l;
			}
			dfs(step + 1, chosen + 1, temp, step + 1);
		}
	}
	
	return;
}

int main()
{
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		cin>>xd[i].l>>xd[i].r;
	}
	sort(xd + 1, xd + n + 1, cmp1);
	int tp = 0, nm = 0;
	for(int i = 1; i <= n; i++)
	{
		if(xd[i].r <= tp)
		{
			xd[i].l = 1111111111;
			xd[i].r = 1111111111;
			nm++;
		}
		else
		{
			tp = xd[i].r;
		}
	}
	sort(xd + 1, xd + n + 1, cmp1);
	dfs(0, 0, 0, 0);
	cout<<ans;
	return 0;
}
