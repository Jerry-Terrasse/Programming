#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,maxx,minn;
int q[300],z[300];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>q[i]>>z[i];
	for(int i=1;i<=n;i++)
	  if(maxx<z[i]) maxx=z[i];
	minn=q[1];
	for(int i=1;i<=n;i++)
	  if(minn>q[i]) minn=q[i];
	cout<<maxx-minn<<endl;
	return 0;
}
