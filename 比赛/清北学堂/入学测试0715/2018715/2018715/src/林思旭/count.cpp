#include<cstdio>
using namespace std;

char a[3][3];
bool istrue[27][27];

int ispeople(char x,char y,char z)
{
	int x1=(int)x,y1=(int)y,z1=(int)z;
	if(x1==y1)
	{
		if(z1!=x1)
		{
			if(istrue[x1-65][z1-65]==0)
			{
				istrue[x1-65][z1-65]=1;
				istrue[z1-65][x1-65]=1;
				return 2;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if(istrue[x1-65][x1-65]==0)
			{
				istrue[x1-65][x1-65]=1;
				return 1;
			}
			else 
			{
				return 0;
			}
		}
	}
	else
	{
		if(z1==x1||z1==y1)
		{
			if(istrue[x1-65][y1-65]==0)
			{
				istrue[x1-65][y1-65]=1;
				istrue[y1-65][x1-65]=1;
				return 2;
			}
			else
			{
				return 0;	
			}	
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int i,j,countpeople,countteam,n;
	char ch;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%c",&a[i][j]);
		}
		scanf("%c",&ch);
	}
	countpeople=0;
	countteam=0;
	n=ispeople(a[0][0],a[0][1],a[0][2]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[1][0],a[1][1],a[1][2]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[2][0],a[2][1],a[2][2]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[0][0],a[1][0],a[2][0]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[0][1],a[1][1],a[2][1]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[0][2],a[1][2],a[2][2]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[0][0],a[1][1],a[2][2]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	n=ispeople(a[0][2],a[1][1],a[2][0]);
	if(n==1) countpeople++;
	else if(n==2) countteam++;
	printf("%d\n%d",countpeople,countteam);
	return 0;
}
