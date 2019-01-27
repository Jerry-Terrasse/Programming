#include<iostream>
#include<cmath>
#define MAXN 100010
#define Max(xx,yy) xx<yy?yy:xx
using namespace std;
long long l[MAXN][2],n=0,m=0,ans=0x7FFFFFFF;
int main()
{
  long long i=0,j=0,x=0,y=0,v=0,d=0;
  cin>>n>>m;
  for(;i<n;i++)
  {
  	cin>>l[i][0]>>l[i][1];
  }
  for(i=0;i<m;i++)
  {
  	cin>>x>>y>>v;
  	d=0;
	for(j=0;j<n;j++)
  	{
  	  d=Max(d,abs(x-l[j][0])+abs(y-l[j][1]));
	}
	ans=min(ans,d*v);
  }
  cout<<ans<<endl;
  return 0;
}
