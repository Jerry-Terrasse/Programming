#include<iostream>
#include "memory.h"
#define MAXN 5010
#define H 998244353
#define min(x,y) (x<y?x:y)
using namespace std;
int f[MAXN][MAXN*MAXN],n=0,m=0;
int dfs(int,int);
int main()
{
	int i=0;
	memset(f,-1,sizeof(f));
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		f[i][0]=1;
	}
	for(i=1;i<MAXN;i++)
	{
		f[0][i]=0;
	}
	if(m>n*(n-1)/2)
	{
		cout<<0<<endl;
		return 0;
	}
	m=min(m,n*(n-1)/2-m);
	cout<<dfs(n-1,m)<<endl;
	return 0;
}
int dfs(int n,int m)
{
	if(f[n][m]!=-1)
	{
		return f[n][m];
	}
	int i=0,k=0;
	f[n][m]=0;
	for(i=min(n,m);i>=0;i--)
	{
		k=dfs(n-1,m-i);
		f[n][m]+=k;
		f[n][m]%=H;
	}
	return f[n][m];
}
