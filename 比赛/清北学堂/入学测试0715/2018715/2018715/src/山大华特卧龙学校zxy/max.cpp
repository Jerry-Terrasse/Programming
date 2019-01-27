#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,n,va,vb,maxx,sum;
int x[100000],c[100000];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	  cin>>x[i]>>c[i];
	for(int i=1;i<=n;i++)
	  if(c[maxx]<c[i]) maxx=i;
	int t;
	t=x[maxx]*(va-vb);
	sum=t*c[maxx];
	for(int i=1;i<=n;i++)
	  if(x[i]>x[maxx]){
	  	int h=x[i]-x[maxx];
	  	int ti=h*(va-vb);
	  	sum+=ti*c[i];
	  }
	cout<<sum<<endl;
	return 0;
}
