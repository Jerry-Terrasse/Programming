#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define ll long long
#define N 1001003
#define inf 0x7fffffff
using namespace std;

ll read()
{
	int f=1;
	ll ret=0;
	char ch=getchar();
	while((ch>'9' || ch<'0') && ch!='-')
	ch=getchar();
	if(ch=='-')
	ch=getchar(),f=-1;
	while(ch<='9' && ch>='0')
	{
		ret=ret*10+ch-'0';
		ch=getchar();
	} 
	return ret*f;
}

char a[4][4];
bool b[26];
bool man[26];
bool win[26][26];

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(false);
	for(int i=1;i<=3;i++)
	{
		int w1,w2;
		int sum=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j]; 
			int x=a[i][j]-'A';
			if(!b[x])
			{
				sum++;
				b[x]=true;
				if(sum==1)
				w1=x;
				if(sum==2)
				w2=x;
			}
		}
		if(sum==2)
		{
			win[w1][w2]=true;
		}
		else
		{
			if(sum==1)
			man[w1]=true;
		}
	}
	for(int i=1;i<=3;i++)
	{
		int w1,w2;
		int sum=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=3;j++)
		{
			int x=a[j][i]-'A';
			if(!b[x])
			{
				sum++;
				b[x]=true;
				if(sum==1)
				w1=x;
				if(sum==2)
				w2=x;
			}
		}
		if(sum==2)
		{
			win[w1][w2]=true;
		}
		else
		{
			if(sum==1)
			man[w1]=true;
		}
	}
	int sum=0;
	int w1,w2;
	memset(b,0,sizeof(b));
	for(int i=1;i<=3;i++)
	{
		int x=a[i][i]-'A';
		if(!b[x])
		{
			sum++;
			b[x]=true;
			if(sum==1)
			w1=x;
			if(sum==2)
			w2=x;
		}
	}
	if(sum==2)
	{
		win[w1][w2]=true;
	}
	else
	{
		if(sum==1)
		man[w1]=true;
	}
	sum=0;
	memset(b,0,sizeof(b));
	
	for(int i=1;i<=3;i++)
	{
		int x=a[i][4-i]-'A';
		if(!b[x])
		{
			sum++;
			b[x]=true;
			if(sum==1)
			w1=x;
			if(sum==2)
			w2=x;
		}
		
	}
	if(sum==2)
	{
		win[w1][w2]=true;
	}
	else
	{
		if(sum==1)
		man[w1]=true;
	}
	int mansum=0;
	for(int i=0;i<=25;i++)
	{
		if(man[i])
		mansum++;
	}
	cout<<mansum<<endl;
	int teamsum=0;
	for(int i=0;i<=25;i++)
	{
		for(int j=i+1;j<=25;j++)
		{
			if(win[i][j] || win[j][i])
			teamsum++;
		}
	}
	cout<<teamsum;
	return 0;
}







