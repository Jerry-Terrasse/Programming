#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int l,n,va,vb;
int x[100100],c[100100];
long long s[100100];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	va-=vb;
	for(int i=1;i<=n;++i) 
	{
		cin>>x[i]>>c[i];
		for(int j=i;j>=0;--j)
			s[i]=max(s[i],s[j]+(x[i]-x[j])*c[i]*va);
	}
	cout<<s[n];
	return 0;
}
