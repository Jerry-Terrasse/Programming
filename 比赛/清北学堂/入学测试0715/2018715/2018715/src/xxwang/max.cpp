#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std ;

int l,n,va,vb;
int w[101000],c[100100];
int f[100000];
int sum,t=1,wait;
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=1;i<=n;i++)
	 scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	{ 
	     sum += (w[i] - wait)*(va-vb)*c[i] ;
	     wait = w[i] ;
	 } 
	 cout << sum ;
} 
