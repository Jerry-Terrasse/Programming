#include<iostream>
using namespace std;
char a[4][4];
int b[4][4],ans1,ans2,g[28][28];
void judgehl();
void judgex();
int main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			b[i][j]=a[i][j]-48;
		}
	}
	judgehl();
	judgex();
	cout<<ans1<<endl;
	cout<<ans2;
	return 0;
}
void judgehl()
{
	int x,y,z;
	for(int i=1;i<=3;i++)
	{
		x=b[i][1];y=b[i][2];z=b[i][3];
		if(x==y||y==z||x==z)
		{
			if(x==y&&y==z&&g[x][x]==0)
			{
				ans1++;
				g[x][x]=1;
			}
			else{
				if(x==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
				if(x==z&&!g[x][y])
				{
					ans2++;
					g[x][y]=g[y][x]=1;
				}
				if(z==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
			}
		}
		x=b[1][i];y=b[2][i];z=b[3][i];
		if(x==y||y==z||x==z)
		{
			if(x==y&&y==z&&g[x][x]==0)
			{
				ans1++;
				g[x][x]=1;
			}
			else{
				if(x==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
				if(x==z&&!g[x][y])
				{
					ans2++;
					g[x][y]=g[y][x]=1;
				}
				if(z==y&&!g[y][x])
				{
					ans2++;
					g[x][y]=g[y][x]=1;
				}
			}
		}
	}
}
void judgex()
{
	int x,y,z;
	x=b[1][1];
	y=b[2][2];
	z=b[3][3];
	if(x==y||y==z||x==z)
		{
			if(x==y&&y==z&&g[x][x]==0)
			{
				ans1++;
				g[x][x]=1;
			}
			else{
				if(x==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
				if(x==z&&!g[x][y])
				{
					ans2++;
					g[x][y]=g[y][x]=1;
				}
				if(z==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
			}
		}
	x=b[1][3];
	y=b[2][2];
	z=b[3][1];
	if(x==y||y==z||x==z)
		{
			if(x==y&&y==z&&g[x][x]==0)
			{
				ans1++;
				g[x][x]=1;
			}
			else{
				if(x==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
				if(x==z&&!g[x][y])
				{
					ans2++;
					g[x][y]=g[y][x]=1;
				}
				if(z==y&&!g[x][z])
				{
					ans2++;
					g[x][z]=g[z][x]=1;
				}
			}
		}
}
