#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[4][4];
bool p[70][70];
int ans,bns;
int read()
{
	for(int i=1;i<=3;i++)
	 {
	 for(int j=1;j<=3;j++)
	 
	 	{
	 		char c=getchar();
	        a[i][j]=c-'0';
		 }
		 char c=getchar();
	 }
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read();

	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])ans++;
		else if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])
		{
			if(a[i][1]==a[i][2]&&p[a[i][1]][a[i][3]]==0)
			{
				p[a[i][1]][a[i][3]]=p[a[i][3]][a[i][1]]=1;
				bns++;
			}
			else if(a[i][1]==a[i][3]&&p[a[i][1]][a[i][2]]==0)
			{
				p[a[i][1]][a[i][2]]=p[a[i][2]][a[i][1]]=1;
				bns++;
			//	cout<<"$$$$"<<endl;
			}
			else if(a[i][2]==a[i][3]&&p[a[i][2]][a[i][1]]==0)
			{
				p[a[i][2]][a[i][1]]=p[a[i][1]][a[i][2]]=1;
				bns++;
			}
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[2][i]==a[3][i])ans++;
		else if(a[1][i]==a[2][i]||a[1][i]==a[3][i]||a[2][i]==a[3][i])
		{
			if(a[1][i]==a[2][i]&&p[a[1][i]][a[3][i]]==0)
			{
				p[a[1][i]][a[3][i]]=p[a[3][i]][a[1][i]]=1;
				bns++;
				
			}
			else if(a[1][i]==a[3][i]&&p[a[1][i]][a[2][i]]==0)
			{
				p[a[1][i]][a[2][i]]=p[a[2][i]][a[1][i]]=1;
				bns++;
				//cout<<"!!!!!!!1"<<" "<<i<<endl;
			}
			else if(a[2][i]==a[3][i]&&p[a[2][i]][a[1][i]]==0)
			{
				p[a[2][i]][a[1][i]]=p[a[1][i]][a[2][i]]=1;
				bns++;
			}
		}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])ans++;
	 else if(a[1][1]==a[2][2]||a[1][1]==a[3][3]||a[2][2]==a[3][3])
	 {
	 	if(a[1][1]==a[2][2]&&p[a[2][2]][a[3][3]]==0)
	 	{
	 		p[a[3][3]][a[2][2]]=p[a[2][2]][a[3][3]]=1;
	 		bns++;
		 }
		else if(a[1][1]==a[3][3]&&p[a[3][3]][a[2][2]]==0)
	 	{
	 		p[a[2][2]][a[3][3]]=p[a[3][3]][a[2][2]]=1;
	 		bns++;
		 }
		else if(a[2][2]==a[3][3]&&p[a[3][3]][a[1][1]]==0)
	 	{
	 		p[a[1][1]][a[3][3]]=p[a[3][3]][a[1][1]]=1;
	 		bns++;
		 }
	 }
	if(a[1][3]==a[2][2]&&a[2][2]==a[3][1])ans++;
	 else if(a[1][3]==a[2][2]||a[1][3]==a[3][1]||a[2][2]==a[3][1])
	 {
	 	if(a[1][3]==a[2][2]&&p[a[2][2]][a[3][1]]==0)
	 	{
	 		p[a[3][1]][a[2][2]]=p[a[2][2]][a[3][1]]=1;
	 		bns++;
		 }
		else if(a[1][3]==a[3][1]&&p[a[1][3]][a[2][2]]==0)
	 	{
	 		p[a[2][2]][a[1][3]]=p[a[1][3]][a[2][2]]=1;
	 		bns++;
	 	//	cout<<"PPPP"<<endl;
		 }
		else if(a[2][2]==a[3][1]&&p[a[3][1]][a[1][3]]==0)
	 	{
	 		p[a[1][3]][a[3][1]]=p[a[3][1]][a[1][3]]=1;
	 		bns++;
		 }
	 }
//	 cout<<p[a[1][1]][a[3][1]]<<endl;
	cout<<ans<<endl;
	cout<<bns<<endl;
}
