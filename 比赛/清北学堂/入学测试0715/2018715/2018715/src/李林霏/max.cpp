#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define LL long long
using namespace std;

LL l,n,va,vb,m,x[100005],c[100005],t[100005],f[1000005],ans;

inline LL read()
{
	char ch=getchar();
	LL f=1,x=0;
	while (ch<'0' || ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	l=read(); n=read(); va=read(); vb=read();
	for (int i=1;i<=n;i++) 
	{
		x[i]=read(); c[i]=read();
		t[i]=x[i]*(va-vb);
	}
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		for (LL j=1;j<=t[i];j++)
		{
			f[j]=max(f[j],f[j-1]+c[i]);
		}
	}
	printf("%lld",f[t[n]]);
	return 0;
}
