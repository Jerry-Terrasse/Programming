#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans1, ans2;
int a[5][5];
struct Node
{
	int to;
} cp[60];
bool single_win[30], team_win[100];
void match(int a, int b)
{
	if(!cp[a].to)
	{
		cp[a].to = b;
		ans2++;
	}
}
void solve()
{
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
		{
			if(a[i][j] == a[i-1][j] && a[i][j] == a[i+1][j])
			{
				single_win[a[i][j]] = true;
			}
			if(a[i][j] == a[i][j-1] && a[i][j] == a[i][j+1])
			{
				single_win[a[i][j]] = true;
			}
			if(a[i][j] == a[i-1][j-1] && a[i][j] == a[i+1][j+1])
			{
				single_win[a[i][j]] = true;
			}
			if(a[i][j] == a[i+1][j-1] && a[i][j] == a[i-1][j+1])
			{
				single_win[a[i][j]] = true;
			}
		}
	for(int i=0; i<=26; i++)
	{
		if(single_win[i]) ans1++;
	}
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
		{
			if(i==2) if(a[i][j] == a[i-1][j]) match(a[i][j], a[i+1][j]), match(a[i+1][j], a[i][j]);
			if(i==2) if(a[i][j] == a[i+1][j]) match(a[i][j], a[i-1][j]), match(a[i-1][j], a[i][j]);
			if(i==2) if(a[i-1][j] == a[i+1][j]) match(a[i+1][j], a[i-1][j]), match(a[i-1][j], a[i+1][j]);
			if(j==2) if(a[i][j] == a[i][j-1]) match(a[i][j], a[i][j+1]), match(a[i][j+1], a[i][j]);
			if(j==2) if(a[i][j] == a[i][j+1]) match(a[i][j], a[i][j-1]), match(a[i][j-1], a[i][j]);
			if(j==2) if(a[i][j-1] == a[i][j+1]) match(a[i][j+1], a[i][j-1]), match(a[i][j-1], a[i][j+1]);
			if(i==2 && j==2) if(a[i][j] == a[i-1][j-1]) match(a[i][j], a[i+1][j+1]), match(a[i+1][j+1], a[i][j]);
			if(i==2 && j==2) if(a[i][j] == a[i+1][j+1]) match(a[i][j], a[i-1][j-1]), match(a[i-1][j-1], a[i][j]);
			if(i==2 && j==2) if(a[i+1][j+1] == a[i-1][j-1]) match(a[i][j], a[i+1][j+1]), match(a[i+1][j+1], a[i][j]);
			if(i==2 && j==2) if(a[i][j] == a[i+1][j-1]) match(a[i][j], a[i-1][j+1]), match(a[i-1][j+1], a[i][j]);
			if(i==2 && j==2) if(a[i][j] == a[i-1][j+1]) match(a[i][j], a[i+1][j-1]), match(a[i+1][j-1], a[i][j]);
			if(i==2 && j==2) if(a[i+1][j-1] == a[i-1][j+1]) match(a[i][j], a[i-1][j+1]), match(a[i-1][j+1], a[i][j]);
		}
		ans2 /= 2;
}
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	memset(a, 999, sizeof(a));
	for(int i=1; i<=3; i++)
	{
		char ch[5];
		scanf("%s", ch+1);
		for(int j=1; j<=3; j++)
			a[i][j] = (int)(ch[j]-'A') + 1;
	}
	solve();
	printf("%d\n%d", ans1, ans2);
	return 0;
}
