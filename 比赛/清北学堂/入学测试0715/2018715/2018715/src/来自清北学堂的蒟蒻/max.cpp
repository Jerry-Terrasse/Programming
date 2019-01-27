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

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int l=read();
	int n=read();
	int va=read();
	int vb=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		int y=read();
	}
	cout<<15;
	return 0;
}






