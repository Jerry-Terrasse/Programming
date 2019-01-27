#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ru[3][3], temp[3];
bool peo[27], grp[27][27];
int ans1, ans2;

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for(int i = 0; i <= 2; i++)
	{
		cin>>ru[i];
	}
	for(int i = 0; i <= 2; i++)
	{
		int tp = 0;
		memset(temp, 0, sizeof(temp));
		for(int j = 0; j <= 2; j++)
		{
			bool flag1 = 0;
			for(int t = 0; t <= 2; t++)
			{
				if(ru[i][j] == temp[t])
				{
					flag1 = 1;
				}
			}
			if(flag1 == 0)
			{
				temp[tp] = ru[i][j];
				tp++;
			}
		}
		if(tp == 1)
		{
			if(peo[temp[0] - 'A' + 1] == 0)
			{
				peo[temp[0] - 'A' + 1] = 1;
				ans1++;
			}
		}
		if(tp == 2)
		{
			if(grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] == 0)
			{
				grp[temp[0] - 'A' + 1][temp[1] - 'A' + 1] = 1;
				grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] = 1;
				ans2++;
			}
		}
	}
	for(int i = 0; i <= 2; i++)
	{
		int tp = 0;
		memset(temp, 0, sizeof(temp));
		for(int j = 0; j <= 2; j++)
		{
			bool flag1 = 0;
			for(int t = 0; t <= 2; t++)
			{
				if(ru[j][i] == temp[t])
				{
					flag1 = 1;
				}
			}
			if(flag1 == 0)
			{
				temp[tp] = ru[j][i];
				tp++;
			}
		}
		if(tp == 1)
		{
			if(peo[temp[0] - 'A' + 1] == 0)
			{
				peo[temp[0] - 'A' + 1] = 1;
				ans1++;
			}
		}
		if(tp == 2)
		{
			if(grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] == 0)
			{
				grp[temp[0] - 'A' + 1][temp[1] - 'A' + 1] = 1;
				grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] = 1;
				ans2++;
			}
		}
	}
		int tp = 0;
		memset(temp, 0, sizeof(temp));
		for(int j = 0; j <= 2; j++)
		{
			bool flag1 = 0;
			for(int t = 0; t <= 2; t++)
			{
				if(ru[j][j] == temp[t])
				{
					flag1 = 1;
				}
			}
			if(flag1 == 0)
			{
				temp[tp] = ru[j][j];
				tp++;
			}
		}
		if(tp == 1)
		{
			if(peo[temp[0] - 'A' + 1] == 0)
			{
				peo[temp[0] - 'A' + 1] = 1;
				ans1++;
			}
		}
		if(tp == 2)
		{
			if(grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] == 0)
			{
				grp[temp[0] - 'A' + 1][temp[1] - 'A' + 1] = 1;
				grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] = 1;
				ans2++;
			}
		}
		tp = 0;
		memset(temp, 0, sizeof(temp));
		for(int j = 0; j <= 2; j++)
		{
			bool flag1 = 0;
			for(int t = 0; t <= 2; t++)
			{
				if(ru[j][2 - j] == temp[t])
				{
					flag1 = 1;
				}
			}
			if(flag1 == 0)
			{
				temp[tp] = ru[j][2 - j];
				tp++;
			}
		}
		if(tp == 1)
		{
			if(peo[temp[0] - 'A' + 1] == 0)
			{
				peo[temp[0] - 'A' + 1] = 1;
				ans1++;
			}
		}
		if(tp == 2)
		{
			if(grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] == 0)
			{
				grp[temp[0] - 'A' + 1][temp[1] - 'A' + 1] = 1;
				grp[temp[1] - 'A' + 1][temp[0] - 'A' + 1] = 1;
				ans2++;
			}
		}
	cout<<ans1<<endl<<ans2;
	return 0;
}
