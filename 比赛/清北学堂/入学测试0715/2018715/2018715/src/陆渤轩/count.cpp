#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char a[4][4];
int ans1,ans2,Q1,Q2;
char x[100],y[100],z[100];
void check1(int a1,int a2,int b1,int b2,int c1,int c2)
{
	if(a[a1][a2]==a[b1][b2]&&a[b1][b2]==a[c1][c2])
	{
		x[++ans1]=a[a1][a2];
	}
}
void check2(int a1,int a2,int b1,int b2,int c1,int c2)
{
	if(a[a1][a2]==a[b1][b2]&&a[b1][b2]!=a[c1][c2])
	{
		y[++ans2]=a[a1][a1];
		z[ans2]=a[c1][c2];
	}
	if(a[a1][a2]!=a[b1][b2])
	{
		if(a[c1][c2]==a[a1][a2]||a[c1][c2]==a[b1][b2])
		{
			y[++ans2]=a[a1][a2];
			z[ans2]=a[b1][b2];
		}
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	check1(1,1,1,2,1,3);
	check1(2,1,2,2,2,3);
	check1(3,1,3,2,3,3);
	check1(1,1,2,1,3,1);
	check1(1,2,2,2,3,2);
	check1(1,3,2,3,3,3);
	check1(1,1,2,2,3,3);
	check1(1,3,2,2,3,1);
	check2(1,1,1,2,1,3);
	check2(2,1,2,2,2,3);
	check2(3,1,3,2,3,3);
	check2(1,1,2,1,3,1);
	check2(1,2,2,2,3,2);
	check2(1,3,2,3,3,3);
	check2(1,1,2,2,3,3);
	check2(1,3,2,2,3,1);
	for(int i=1;i<=ans1;i++)
	{
		for(int j=i+1;j<=ans1;j++)
		{
			if(x[i]==x[j])
			{
				x[j]='!';
			}
		}
	}
	for(int i=1;i<=ans1;i++)
	{
		if(x[i]!='!')Q1++;
	}
	for(int i=1;i<=ans2;i++)
	{
		for(int j=i+1;j<=ans2;j++)
		{
			if(y[i]==y[j]&&z[i]==z[j])
			{
				y[j]='!';
				z[j]='!';
			}
			if(y[i]==z[j]&&z[i]==y[j])
			{
				y[j]='!';
				z[j]='!';
			}
		}
	}
	for(int i=1;i<=ans2;i++)
	{
		if(y[i]!='!')Q2++;
	}
	cout<<Q1<<endl<<Q2<<endl;
}
