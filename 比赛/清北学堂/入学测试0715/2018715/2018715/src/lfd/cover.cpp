#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
#include<set>
#define R register
#pragma GCC optimize(2)

using namespace std;
int n,x,y,m,maxx;

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		maxx=max(maxx,y);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
