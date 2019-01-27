#include<bits/stdc++.h>
using namespace std;
int a[5][5];
int pd[30][30]={(0,0)};
int ans1,ans2;
void find()
{
	int i,j;
	for(i=1;i<=3;i++)//h
	{
		if(a[i][1]!=a[i][2])
		{
			if(a[i][1]==a[i][3]&&pd[a[i][1]][a[i][3]]!=0)
			{
				ans2++;
				pd[a[i][1]][a[i][3]]=1;
			}
			else if(a[i][2]==a[i][3]&&pd[a[i][2]][a[i][3]]!=0)
			{
				pd[a[i][2]][a[i][3]]=1;
				ans2++;
			}
		}
		else
		{
			if(a[i][1]==a[i][3])
			{
				ans1++;
			}
			else
			{
				if(pd[a[i][2]][a[i][3]]!=0)
				{
					ans2++;
					pd[a[i][2]][a[i][3]]=1;
					pd[a[i][1]][a[i][3]]=1;
				}
			}
		}
	}
	for(i=1;i<=3;i++)
	{
		if(a[1][i]!=a[2][i])
		{
			if(a[1][i]==a[3][i]&&pd[a[1][i]][a[3][i]]!=0)
			{
				ans2++;
				pd[a[1][i]][a[3][i]]=1;
			}
			if(a[2][i]==a[3][i]&&pd[a[2][i]][a[3][i]]!=0)
			{
				ans2++;
				pd[a[2][i]][a[3][i]]==1;
			}
		}
		else
		{
				if(a[1][i]==a[3][i])
				ans1++;
				else
				{
					if(pd[a[1][i]][a[3][i]]!=0)
					{
						ans2++;
						pd[a[1][i]][a[3][i]]==1;
						pd[a[2][i]][a[3][i]]==1;
					}
				}

		}
	}
	if(a[1][1]!=a[2][2])
	{
		if(a[1][1]==a[3][3]&&pd[a[1][1]][a[3][3]]!=0)
		{
			ans2++;
			pd[a[1][1]][a[3][3]]=1;
		}
		if(a[2][2]==a[3][3]&&pd[a[2][2]][a[3][3]]!=0)
		{
			ans2++;
			pd[a[2][2]][a[3][3]]=1;
		}
	}
	else if(a[3][1]!=a[2][2])
	{
		if(a[3][1]==a[1][3]&&pd[a[3][1]][a[1][3]]!=0)
		{
			ans2++;
			pd[a[3][1]][a[1][3]]=1;
		}
		if(a[2][2]==a[1][3]&&pd[a[2][2]][a[1][3]]!=0)
		{
			ans2++;
			pd[a[2][2]][a[1][3]]=1;
		}
	}
	else
	{
		if(a[1][1]==a[3][3]||a[1][3]==a[3][1])
		ans1++;
		else
		{
			if(pd[a[2][2]][a[1][3]]!=0)
			{
				ans2++;
				pd[a[2][2]][a[1][3]]==1;
				pd[a[3][1]][a[1][3]]==1;
			}
			if(pd[a[2][2]][a[3][3]]!=0)
			{
				ans2++;
				pd[a[2][2]][a[3][3]]==1;
				pd[a[1][1]][a[3][3]]==1;
			}
		}
	}

}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,j;
	memset(a,0,sizeof(a));
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			cin>>a[i][j];
	find();
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
	
}
