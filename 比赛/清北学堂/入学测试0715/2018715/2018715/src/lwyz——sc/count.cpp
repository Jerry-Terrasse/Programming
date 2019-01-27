#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c;
int a[101][101];
int ans=0,num=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>c;
			a[i][j]=c-65;
		}
	}
	/*for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cout<<a[i][j]<<endl;
		}
	}*/
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[1][i]==a[3][i]) ans++;
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]) ans++;
		if((a[1][i]==a[2][i])&&(a[1][i]!=a[3][i])) num++;
		if((a[1][i]==a[3][i])&&(a[1][i]!=a[2][i])) num++;
		if((a[2][i]==a[3][i])&&(a[1][i]!=a[3][i])) num++;
		if((a[i][1]==a[i][2])&&(a[i][1]!=a[i][3])) num++;
		if((a[i][1]==a[i][3])&&(a[i][1]!=a[i][2])) num++;
		if((a[i][2]==a[i][3])&&(a[i][1]!=a[i][3])) num++;
	}
	if(a[1][1]==a[2][2]&&a[1][1]==a[3][3]) ans++;
	if(a[3][1]==a[2][2]&&a[3][1]==a[1][3]) ans++;
	if((a[1][1]==a[2][2])&&(a[1][1]!=a[3][3])) num++;
	if((a[1][1]==a[3][3])&&(a[1][1]!=a[2][2])) num++;
	if((a[2][2]==a[3][3])&&(a[1][1]!=a[3][3])) num++;
	if((a[3][1]==a[2][2])&&(a[3][1]!=a[1][3])) num++;
	if((a[3][1]==a[1][3])&&(a[2][2]!=a[1][3])) num++;
	if((a[2][2]==a[1][3])&&(a[3][1]!=a[2][2])) num++;
	cout<<ans<<endl<<num<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
