#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[4][4];
int ans1,ans2;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		string s;
		cin>>s;
		int len=s.size();
		for(int j=0;j<s.size();j++)
			a[i][j+1]=s[j];
	}
	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]&&a[i][2]==a[i][3])
			ans1++;
		else if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])
			ans2++;
	}
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[1][i]==a[3][i]&&a[2][i]==a[3][i])
			ans1++;
		else if(a[1][i]==a[2][i]||a[1][i]==a[3][i]||a[2][i]==a[3][i])
			ans2++;
	}
	if(a[1][1]==a[2][2]==a[3][3])
		ans1++;
	else if(a[1][1]==a[2][2]||a[1][1]==a[3][3]||a[2][2]==a[3][3])
			ans2++;
	if(a[3][1]==a[2][2]==a[1][3])
		ans1++;
	else if(a[3][1]==a[2][2]||a[3][1]==a[1][3]||a[2][2]==a[1][3])
			ans2++;
	printf("%d\n%d",ans1,ans2);
	return 0;
}
