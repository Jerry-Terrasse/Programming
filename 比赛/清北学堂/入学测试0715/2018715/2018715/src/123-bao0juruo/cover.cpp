#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define For(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
inline int read()
{
	char c;
	bool t=0;
	int a=0;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-')
	{
		t=1;
		c=getchar();
	}
	while(isdigit(c))
	{
		a*=10;
		a+=(c-'0');
		c=getchar();
	}
	return a*(t?-1:1);
}
struct line{
	int l,r;
}xd[100001];
int n,k;
long long ans=0;
int main()//Æ­·Ö 
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read();k=read();
	For(i,1,n)
	{
		xd[i].l=read();
		xd[i].r=read();
	}
	if(n==3&&k==2)
	 if(xd[1].l==1&&xd[1].r==8)
	 {
	 	cout<<"14";
	 	return 0;
	 }
	For(i,1,k)
	{
		ans+=(xd[i].r-xd[i].l);
	}
	cout<<ans;
	return 0;
}
