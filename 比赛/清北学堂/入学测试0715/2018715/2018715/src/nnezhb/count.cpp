#include<bits/stdc++.h>
using namespace std;
char b[5];
int a[4][4];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int ansp=0,anst=0;
	for(int i=1;i<=3;i++)
	{
		scanf("%s",b+1);
		for(int j=1;j<=3;j++)
			a[i][j]=int(b[j]);
	}
	
	int  flag=0;
	for(int i=1;i<=3;i++)//heng
	{
		for(int j=2;j<=3;j++)
		{
			if(a[i][j]!=a[i][1])
				flag++;
		}
		if(a[i][3]!=a[i][2])
			flag++;
		if(flag==0)
			ansp++;
		else if(flag==2)
			anst++;
		flag=0;
	}
	
	for(int i=1;i<=3;i++)//shu
	{
		for(int j=2;j<=3;j++)
		{
			if(a[j][i]!=a[1][i])
				flag++;
		}
		if(a[3][i]!=a[2][i])
			flag++;
		if(flag==0)
			ansp++;
		else if(flag==2)
			anst++;
		flag=0;
	}
	
	for(int i=2;i<=3;i++)//zuoshang->youxia
	{
		if(a[i][i]!=a[1][1])
			flag++;
	}
	if(a[2][2]!=a[3][3])
		flag++;
	if(flag==0)
		ansp++;
	else if(flag==2)
		anst++;
	flag=0;
	
	for(int i=2;i<=3;i++)
	{
		if(a[i][4-i]!=a[1][3])
			flag++;
	}
	if(a[2][2]!=a[3][1])
		flag++;
	if(flag==0)
		ansp++;
	else if(flag==2)
		anst++;
	flag=0;
	
	cout<<ansp<<endl<<anst;
	return 0;
}
