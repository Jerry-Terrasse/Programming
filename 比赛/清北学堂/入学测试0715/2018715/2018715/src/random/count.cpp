#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
char d[3][4];
int ans1, ans2, tab[26];
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", d[i]);
		for (int j = 0; j < 3; j++)
			++tab[d[i][j] - 'A'];
		int tmp = 0;
		for (int k = 0; k < 26; k++)
			if (tab[k])
				++tmp;
		if (tmp == 1)
			++ans1;
		else if (tmp == 2)
			++ans2;
		memset(tab, 0, sizeof(tab));
		tmp = 0;
	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
			++tab[d[i][j] - 'A'];
		int tmp = 0;
		for (int k = 0; k < 26; k++)
			if (tab[k])
				++tmp;
		if (tmp == 1)
			++ans1;
		else if (tmp == 2)
			++ans2;
		memset(tab, 0, sizeof(tab));
		tmp = 0;
	}
	for (int i = 0; i < 3; i++)
		++tab[d[i][i] - 'A'];
	int tmp = 0;
	for (int k = 0; k < 26; k++)
		if (tab[k])
			++tmp;
	if (tmp == 1)
		++ans1;
	else if (tmp == 2)
		++ans2;
	memset(tab, 0, sizeof(tab));
	tmp = 0;
	for (int i = 0; i < 3; i++)
		++tab[int(d[i][2 - i])];
	for (int k = 0; k < 26; k++)
		if (tab[k])
			++tmp;
	if (tmp == 1)
		++ans1;
	else if (tmp == 2)
		++ans2;
	printf("%d\n%d", ans1, ans2);
}
