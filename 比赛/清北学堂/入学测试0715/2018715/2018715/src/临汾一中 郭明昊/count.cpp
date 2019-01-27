#include<cstdio>
#include<iostream>
using namespace std;
const int N=100;
char s[N][N];
int ans_person, ans_team;
bool vis_person[N], vis_team[N][N];
void check(char a, char b, char c)
{
	if(a==b && b==c)
	{
		if(!vis_person[a-'A'])
		{
			ans_person++;
			vis_person[a-'A']=1;
		}
	}
	else if(!(a!=b && b!=c && a!=c))
	{
		if(a==b) b=c;
		if(!vis_team[a-'A'][b-'A'])
		{
			ans_team++;
			vis_team[a-'A'][b-'A']=vis_team[b-'A'][a-'A']=1;
		}
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=0; i<3; i++)
		scanf("%s", s[i]);
	check(s[0][0], s[0][1], s[0][2]);
	check(s[1][0], s[1][1], s[1][2]);
	check(s[2][0], s[2][1], s[2][2]);
	check(s[0][0], s[1][0], s[2][0]);
	check(s[0][1], s[1][1], s[2][1]);
	check(s[0][2], s[1][2], s[2][2]);
	check(s[0][0], s[1][1], s[2][2]);
	check(s[0][2], s[1][1], s[2][0]);
	printf("%d\n%d", ans_person, ans_team);
	fclose(stdin);
	fclose(stdout);
	return 0;
}