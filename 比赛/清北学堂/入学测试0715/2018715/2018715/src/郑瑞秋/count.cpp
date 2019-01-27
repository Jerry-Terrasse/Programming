#include<iostream>
#include<cstdio>
using namespace std;

char c;
int a[5][5],n1,n2,man[30],men[30][30];

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		cin>>c;
		a[i][j]=c-65;
	}
	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3])man[a[i][1]]++;
		if(a[1][i]==a[2][i]&&a[1][i]==a[3][i])man[a[1][i]]++;
		
		if(a[i][1]==a[i][2]&&a[i][1]!=a[i][3])men[a[i][1]][a[i][3]]++,men[a[i][3]][a[i][1]]++;
		if(a[i][1]==a[i][3]&&a[i][1]!=a[i][2])men[a[i][1]][a[i][2]]++,men[a[i][2]][a[i][1]]++;
		if(a[i][2]==a[i][3]&&a[i][1]!=a[i][2])men[a[i][1]][a[i][2]]++,men[a[i][2]][a[i][1]]++;
		
		if(a[1][i]==a[2][i]&&a[1][i]!=a[3][i])men[a[1][i]][a[3][i]]++,men[a[3][i]][a[1][i]]++;
		if(a[1][i]==a[3][i]&&a[1][i]!=a[2][i])men[a[1][i]][a[2][i]]++,men[a[2][i]][a[1][i]]++;
		if(a[2][i]==a[3][i]&&a[1][i]!=a[2][i])men[a[1][i]][a[2][i]]++,men[a[2][i]][a[1][i]]++;
	}
	if(a[1][1]==a[2][2]&&a[1][1]==a[3][3])man[a[1][1]]++;
	if(a[1][3]==a[2][2]&&a[1][3]==a[3][1])man[a[2][2]]++;
	
	if(a[1][1]==a[2][2]&&a[1][1]!=a[3][3])men[a[1][1]][a[3][3]]++,men[a[3][3]][a[1][1]]++;
	if(a[1][1]==a[3][3]&&a[2][2]!=a[3][3])men[a[2][2]][a[3][3]]++,men[a[3][3]][a[2][2]]++;
	if(a[2][2]==a[3][3]&&a[1][1]!=a[2][2])men[a[2][2]][a[1][1]]++,men[a[1][1]][a[2][2]]++;
	
	if(a[3][1]==a[2][2]&&a[3][1]!=a[1][3])men[a[1][3]][a[3][1]]++,men[a[3][1]][a[1][3]]++;
	if(a[3][1]==a[1][3]&&a[2][2]!=a[1][3])men[a[2][2]][a[1][3]]++,men[a[1][3]][a[2][2]]++;
	if(a[2][2]==a[1][3]&&a[1][3]!=a[2][2])men[a[2][2]][a[1][3]]++,men[a[1][3]][a[2][2]]++;
	
	for(int i=0;i<26;i++)
	{
		if(man[i]){
			n1++;
			//for(int j=1;j<=26;j++)men[j][i]=men[i][j]=0;
		}
	}
	for(int i=0;i<26;i++)
	for(int j=0;j<26;j++)
	{
		if(men[i][j])n2++;//cout<<i<<" "<<j<<endl;
	}
	n2/=2;
	cout<<n1<<endl<<n2;
}
