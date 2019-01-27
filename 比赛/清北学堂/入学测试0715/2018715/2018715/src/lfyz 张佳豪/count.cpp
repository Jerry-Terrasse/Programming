#include<bits/stdc++.h>
using namespace std;
int m,n;
char a[4][4];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		char f;
		cin>>f;
		a[i][j]=f;
	}
	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3])m++;
		else
		{
			if(!(a[i][1]!=a[i][2]&&a[i][1]!=a[i][3]&&a[i][2]!=a[i][3]))n++;
		}
		if(a[1][i]==a[2][i]&&a[1][i]==a[3][i])m++;
		else
		{
			if(!(a[1][i]!=a[2][i]&&a[1][i]!=a[3][i]&&a[2][i]!=a[3][i]))n++;
		}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])m++;
	else
	{
		if(!(a[1][1]!=a[2][2]&&a[2][2]!=a[3][3]&&a[1][1]!=a[3][3]))n++;
	
	}
	if(a[3][1]==a[2][2]&&a[2][2]==a[1][3])m++;
	else
	{
		if(!(a[3][1]!=a[2][2]&&a[2][2]!=a[1][3]&&a[1][3]!=a[3][1]))n++;
	}
	cout<<m<<endl<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
