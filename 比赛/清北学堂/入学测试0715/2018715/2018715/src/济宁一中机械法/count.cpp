#include<iostream>
using namespace std;
char a[5][5];
int w1[27];
int w2[27][27];
int convert(char x)
{
	return x-'A'+1;
}
int cmp(int x,int y,int z,int w)
{
	if(a[x][y]==a[z][w]) return 1;
	return 0;
}
int main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]) w1[convert(a[i][1])]=1;
		if(a[i][1]==a[i][2]&&a[i][1]!=a[i][3]) w2[convert(a[i][1])][convert(a[i][3])]=w2[convert(a[i][3])][convert(a[i][1])]=1;
		if(a[i][1]==a[i][3]&&a[i][2]!=a[i][3]) w2[convert(a[i][1])][convert(a[i][2])]=w2[convert(a[i][2])][convert(a[i][1])]=1;
		if(a[i][3]==a[i][2]&&a[i][1]!=a[i][3]) w2[convert(a[i][1])][convert(a[i][3])]=w2[convert(a[i][3])][convert(a[i][1])]=1;
		if(a[1][i]==a[2][i]&&a[1][i]==a[3][i]) w1[convert(a[1][i])]=1;
		if(a[1][i]==a[2][i]&&a[1][i]!=a[3][i]) w2[convert(a[1][i])][convert(a[3][i])]=w2[convert(a[3][i])][convert(a[1][i])]=1;
		if(a[1][i]==a[3][i]&&a[2][i]!=a[3][i]) w2[convert(a[1][i])][convert(a[2][i])]=w2[convert(a[2][i])][convert(a[1][i])]=1;
		if(a[3][i]==a[2][i]&&a[1][i]!=a[3][i]) w2[convert(a[1][i])][convert(a[3][i])]=w2[convert(a[3][i])][convert(a[1][i])]=1;
	}
	if(a[1][1]==a[2][2]&&a[1][1]==a[3][3]) w1[convert(a[1][1])]=1;
	if(a[1][1]==a[2][2]&&a[1][1]!=a[3][3]) w2[convert(a[1][1])][convert(a[3][3])]=w2[convert(a[3][3])][convert(a[1][1])]=1;
	if(a[3][3]==a[2][2]&&a[1][1]!=a[3][3]) w2[convert(a[1][1])][convert(a[3][3])]=w2[convert(a[3][3])][convert(a[1][1])]=1;
	if(a[1][1]==a[3][3]&&a[2][2]!=a[3][3]) w2[convert(a[2][2])][convert(a[3][3])]=w2[convert(a[3][3])][convert(a[2][2])]=1;
	if(a[1][3]==a[2][2]&&a[3][1]==a[2][2]) w1[convert(a[1][3])]=1;
	if(a[1][3]==a[2][2]&&a[1][3]!=a[3][1]) w2[convert(a[1][3])][convert(a[3][1])]=w2[convert(a[3][1])][convert(a[1][3])]=1;
	if(a[1][3]==a[3][1]&&a[2][2]!=a[1][3]) w2[convert(a[2][2])][convert(a[1][3])]=w2[convert(a[1][3])][convert(a[2][2])]=1;
	if(a[3][1]==a[2][2]&&a[2][2]!=a[1][3]) w2[convert(a[2][2])][convert(a[1][3])]=w2[convert(a[1][3])][convert(a[2][2])]=1;
	int ans1=0,ans2=0;
	for(int i=1;i<=26;i++)
	{
		if(w1[i]) ans1++;
	}
	for(int i=1;i<=26;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(w2[i][j]) ans2++;
		}
	}
	cout<<ans1<<endl;
	cout<<ans2/2<<endl;
	return 0;
}
