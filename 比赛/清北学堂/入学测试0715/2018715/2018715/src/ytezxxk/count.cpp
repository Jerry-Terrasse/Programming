#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int tu[4][4];
int ans1,ans2;
bool a[27][27]={0};
bool b[27]={0};
char f;
int d[9][4];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
			cin>>f;
			tu[i][j]=f-'A'+1;
	}
	for(int i=1;i<=3;i++)
	{
		d[i][1]=tu[i][1];
		d[i][2]=tu[i][2];
		d[i][3]=tu[i][3];
		d[i+3][1]=tu[1][i];
		d[i+3][2]=tu[2][i];
		d[i+3][3]=tu[3][i];
	}
	for(int i=1;i<=3;i++)
	{
		d[7][i]=tu[i][i];
		d[8][i]=tu[i][4-i];
	}
	for(int i=1;i<=8;i++)
	{
		if((d[i][1]==d[i][2]&&d[i][2]==d[i][3])&&b[d[i][1]]==0){ans1++;b[d[i][1]]=1;}
		if((d[i][1]==d[i][2]&&d[i][2]!=d[i][3])&&a[d[i][1]][d[i][2]]==0){ans2++;a[d[i][1]][d[i][2]]=1;}
		if((d[i][2]==d[i][3]&&d[i][3]!=d[i][1])&&a[d[i][2]][d[i][3]]==0){ans2++;a[d[i][2]][d[i][3]]=1;}
		if((d[i][3]==d[i][1]&&d[i][1]!=d[i][2])&&a[d[i][3]][d[i][1]]==0){ans2++;a[d[i][3]][d[i][1]]=1;}
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
