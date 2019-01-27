#include <cstdio>
#include <iostream>

int ren, duiwu;
char a[5][5], s1, s2, s3, s4, s5, s6;
bool vis[27], win[27][27];
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			std::cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		s1 = a[i][1];
		int heng = 1;
		s2 = a[1][i];
		int shu = 1;
		for (int j = 1; j <= 3; j++)
		{
			if (a[i][j] != s1)
			{
				s6 = a[i][j];
				heng++;
			}
			if (a[j][i] != s2)
			{
				s5 = a[j][i];
				shu++;
			}
		}
		if (shu == 1 && !vis[s2 - 'A' + 1])
		{
			vis[s2 - 'A' + 1] = 1;
			ren++;
		}
		else if (shu == 2 && !win[s2 - 'A' + 1][s5 - 'A' + 1])
		{
			win[s2 - 'A' + 1][s5 - 'A' + 1] = 1;
			win[s5 - 'A' + 1][s2 - 'A' + 1] = 1;
			duiwu++;
		}
		if (heng == 1 && !vis[s1 - 'A' + 1])
		{
			vis[s1 - 'A' + 1] = 1;
			ren++;
		}
		else if (heng == 2 && !win[s2 - 'A' + 1][s6 - 'A' + 1])
		{
			win[s2 - 'A' + 1][s6 - 'A' + 1] = 1;
			win[s6 - 'A' + 1][s2 - 'A' + 1] = 1;
			duiwu++;
		}
	}
	s3 = a[2][2];
	if (a[1][1] == s3)
	{
		if (a[3][3] == s3 && !vis[s3 - 'A' + 1])
		{
			vis[s3 - 'A' + 1] = 1;
			ren++;
		}
		else if (a[3][3] != s3 && !win[s3 - 'A' + 1][a[3][3] - 'A' + 1])
		{
			win[s3 - 'A' + 1][a[3][3] - 'A' + 1] = 1;
			win[a[3][3] - 'A' + 1][s3 - 'A' + 1] = 1;
			duiwu++;
		}
	}
	else
	{
		s4 = a[1][1];
		if ((a[3][3] == s4 || a[3][3] == s3 ) && !win[s3 - 'A' + 1][s4 - 'A' + 1])
		{
			win[s3 - 'A' + 1][s4 - 'A' + 1] = 1;
			win[s4 - 'A' + 1][s3 - 'A' + 1] = 1;
			duiwu++;
		}
	}
	if (a[3][1] == s3)
	{
		if (a[1][3] == s3 && !vis[s3 - 'A' + 1])
		{
			vis[s3 - 'A' + 1] = 1;
			ren++;
		}
		else if (a[1][3] != s3 && !win[s3 - 'A' + 1][a[1][3] - 'A' + 1])
		{
			win[s3 - 'A' + 1][a[1][3] - 'A' + 1] = 1;
			win[a[1][3] - 'A' + 1][s3 - 'A' + 1] = 1;
			duiwu++;
		}
	}
	else
	{
		s4 = a[3][1];
		if ((a[1][3] == s4 || a[1][3] == s3) && !win[s3 - 'A' + 1][s4 - 'A' + 1])
		{
			win[s3 - 'A' + 1][s4 - 'A' + 1] = 1;
			win[s4 - 'A' + 1][s3 - 'A' + 1] = 1;
			duiwu++;
		}
	}
	printf("%d\n%d\n", ren, duiwu);
	return 0;
}
