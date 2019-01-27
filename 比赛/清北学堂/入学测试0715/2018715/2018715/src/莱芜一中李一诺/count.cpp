#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue> 
#include<map> 
using namespace std;
char a[5][5];
int n[5][5],che[50][50];
map<char,int>m;
int peo,tea;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			n[i][j]=a[i][j]-'0'-16;
		}
	for(int i=1;i<=3;i++)
	{
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])
		{
			if(!m[a[i][1]]) peo++;
			m[a[i][1]]=1;
		}
		if(n[i][1]==n[i][2]&&n[i][1]!=n[i][3])
		{
			if(!che[n[i][1]][n[i][3]]) tea++;
			che[n[i][1]][n[i][3]]=1;
			che[n[i][3]][n[i][1]]=1;
		}
		if(n[i][1]==n[i][3]&&n[i][1]!=n[i][2])
		{
			if(!che[n[i][1]][n[i][2]]) tea++;
			che[n[i][1]][n[i][2]]=1;
			che[n[i][2]][n[i][1]]=1;
		}
		if(n[i][3]==n[i][2]&&n[i][1]!=n[i][3])
		{
			if(!che[n[i][3]][n[i][1]]) tea++;
			che[n[i][3]][n[i][1]]=1;
			che[n[i][1]][n[i][3]]=1;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(a[1][i]==a[2][i]&&a[2][i]==a[3][i])
		{
			if(!m[a[1][i]]) peo++;
			m[a[1][i]]=1;
		}
		if(n[1][i]==n[2][i]&&n[2][i]!=n[3][i])
		{
			if(!che[n[1][i]][n[3][i]]) tea++;
			che[n[1][i]][n[3][i]]=1;
			che[n[3][i]][n[1][i]]=1;
		}
		if(n[1][i]==n[3][i]&&n[2][i]!=n[3][i])
		{
			if(!che[n[1][i]][n[2][i]]) tea++;
			che[n[1][i]][n[2][i]]=1;
			che[n[2][i]][n[1][i]]=1;
		}
		if(n[3][i]==n[2][i]&&n[2][i]!=n[1][i])
		{
			if(!che[n[3][i]][n[1][i]]) tea++;
			che[n[3][i]][n[1][i]]=1;
			che[n[1][i]][n[3][i]]=1;
		}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])
	{
		if(!m[a[1][1]]) peo++;
		m[a[1][1]]=1;
	}
	if(a[1][1]==a[2][2]&&a[2][2]!=a[3][3])
	{
		if(!che[n[1][1]][n[3][3]]) tea++;
			che[n[1][1]][n[3][3]]=1;
			che[n[3][3]][n[1][1]]=1;
	}
	if(a[1][1]==a[3][3]&&a[2][2]!=a[3][3])
	{
		if(!che[n[1][1]][n[2][2]]) tea++;
			che[n[1][1]][n[2][2]]=1;
			che[n[2][2]][n[1][1]]=1;
	}
	if(a[3][3]==a[2][2]&&a[2][2]!=a[1][1])
	{
		if(!che[n[3][3]][n[1][1]]) tea++;
			che[n[3][3]][n[1][1]]=1;
			che[n[1][1]][n[3][3]]=1;
	}
	if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]) 
	{
		if(!m[a[1][3]]) peo++;
		m[a[1][1]]=1;
	}
	if(a[1][3]==a[2][2]&&a[2][2]!=a[3][1])
	{
		if(!che[n[1][3]][n[3][1]]) tea++;
			che[n[1][3]][n[3][1]]=1;
			che[n[1][3]][n[1][3]]=1;
	}
	if(a[1][3]==a[3][1]&&a[2][2]!=a[3][1])
	{
		if(!che[n[1][3]][n[2][2]]) tea++;
			che[n[1][3]][n[2][2]]=1;
			che[n[2][2]][n[1][3]]=1;
	}
	if(a[3][1]==a[2][2]&&a[2][2]!=a[1][3])
	{
		if(!che[n[3][1]][n[1][3]]) tea++;
			che[n[3][1]][n[1][3]]=1;
			che[n[1][3]][n[3][1]]=1;
	}
	cout<<peo<<endl;
	cout<<tea;
}
