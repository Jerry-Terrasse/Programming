#include<bits/stdc++.h>
using namespace std;
char a[4][4];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	
	int team=0,person=0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
		getchar();
	}
	

	//person
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[2][i]==a[3][i])
			person++;
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])
			person++;
	}
	if((a[1][1]==a[2][2]&&a[2][2]==a[3][3])||(a[3][1]==a[2][2]&&a[2][2]==a[1][3]))
			person++;
	
	
	//team
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[2][i]!=a[3][i])
			team++;
		if(a[1][i]!=a[2][i]&&a[2][i]==a[3][i])
			team++;
		if(a[1][i]==a[3][i]&&a[2][i]!=a[3][i])
			team++;
		if(a[i][1]==a[i][2]&&a[i][2]!=a[i][3])
			team++;
		if(a[i][1]!=a[i][2]&&a[i][2]==a[i][3])
			team++;
		if(a[i][1]==a[i][3]&&a[i][2]!=a[i][3])
			team++;
	}
	if(a[1][1]==a[2][2]&&a[2][2]!=a[3][3])
		team++;
	if(a[1][1]!=a[2][2]&&a[2][2]==a[3][3])
		team++;
	if(a[1][1]==a[3][3]&&a[1][1]!=a[2][2])
		team++;
	if(a[1][3]==a[2][2]&&a[2][2]!=a[3][1])
		team++;
	if(a[1][3]!=a[2][2]&&a[2][2]==a[3][1])
		team++;
	if(a[1][3]==a[3][1]&&a[1][3]!=a[2][2])
		team++;
	
	
	cout<<person<<endl<<team;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
