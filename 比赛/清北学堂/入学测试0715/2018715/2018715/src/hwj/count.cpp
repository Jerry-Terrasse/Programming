#include<cstdio>
#include<iostream>
using namespace std;
int f[4][4]={0},ans=0,team=0,hang=0,lie=0,dui=0,pd[30][30]={0};
char x;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>x;
			f[i][j]=x-64;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(f[i][1]==f[i][2]&&f[i][2]==f[i][3]) 	
		{
			if(pd[f[i][1]][f[i][1]]==0)
			{
				pd[f[i][1]][f[i][1]]=1;
				hang++;
			}
		}
		else if(f[i][1]==f[i][2])
		{
			if(pd[f[i][3]][f[i][1]]==0)
			{
				pd[f[i][3]][f[i][1]]=1;
				team++;
			}
		}
		else if(f[i][1]==f[i][3])
		{
			if(pd[f[i][2]][f[i][1]]==0)
			{
				pd[f[i][2]][f[i][1]]==1;
				team++;
			}
		}
		else if(f[i][2]==f[i][3])
		{
			if(pd[f[i][1]][f[i][2]]==0)
			{
				pd[f[i][1]][f[i][2]]=1;
				team++;
			}
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(f[1][i]==f[2][i]&&f[2][i]==f[3][i]) 
		{
			if(pd[f[1][i]][f[1][i]]==0)
			{
				pd[f[1][i]][f[1][i]]=1;
				lie++;
			}
		}
		else if(f[1][i]==f[2][i])
		{
			if(pd[f[3][i]][f[1][i]]==0)
			{
				pd[f[3][i]][f[1][i]]=1;
				team++;
			}
		}
		else if(f[1][i]==f[3][i])
		{
			if(pd[f[2][i]][f[1][i]]==0)
			{
				pd[f[2][i]][f[1][i]]=1;
				team++;
			}
		}
		else if(f[2][i]==f[3][i])
		{
			if(pd[f[1][i]][f[2][i]]==0)
			{
				pd[f[1][i]][f[2][i]]=1;
				team++;
			}
		}
	}
	if(f[1][1]==f[2][2]&&f[2][2]==f[3][3]) 
	{
		if(pd[f[1][1]][f[1][1]]==0)
			{
				pd[f[1][1]][f[1][1]]=1;
				dui++;
			}
	}
	else if(f[1][1]==f[2][2])
	{
		if(pd[f[3][3]][f[1][1]]==0)
		{
			pd[f[3][3]][f[1][1]]=1;
			team++;
		}
	}
	else if(f[1][1]==f[3][3])
	{
		if(pd[f[2][2]][f[1][1]]==0)
		{
			pd[f[3][3]][f[1][1]]=1;
			team++;
		}
	}
	else if(f[2][2]==f[3][3])
	{
		if(pd[f[1][1]][f[2][2]]==0)
		{
			pd[f[1][1]][f[2][2]]=1;
			team++;
		}
	}
	if(f[1][3]==f[2][2]&&f[2][2]==f[3][1]) 
	{
		if(pd[f[1][3]][f[1][3]]==0)
			{
				pd[f[1][3]][1]=1;
				dui++;
			}
	}
	else if(f[1][3]==f[2][2])
	{
		if(pd[f[2][2]][f[1][3]]==0)
		{
			pd[f[2][2]][f[1][3]]=1;
			team++;
		}
	}
	else if(f[1][3]==f[2][2])
	{
		if(pd[f[3][1]][f[1][3]]==0)
		{
			pd[f[3][1]][f[1][3]]=1;
			team++;
		}
	}
	else if(f[2][2]==f[3][1])
	{
		if(pd[f[1][3]][f[2][2]]==0)
		{
			pd[f[1][3]][f[2][2]]=1;
			team++;
		}
	}
	ans=hang+lie+dui;
	cout<<ans<<endl<<team;
	return 0;
}
