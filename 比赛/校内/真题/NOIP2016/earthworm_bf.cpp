#include<iostream>
#include<cmath>
#include<algorithm>
#define ld long double
#define MAXN 8000080
using namespace std;
int a[MAXN],n=0,m=0,q=0,u=0,v=0,t=0,maxa=0;
ld p=0;
inline bool cmp(const int&,const int&);
int main()
{
  register int i=0,j=0,k=0;
  cin>>n>>m>>q>>i>>j>>t;
  p=(ld)i/j;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=m;++i)
  {
  	for(j=2,maxa=1;j<=n;++j)
  	{
  	  if(a[j]>a[maxa])
  	  {
  	    maxa=j;
	  }
	}
	if(!(i%t))
	{
	  cout<<a[maxa]<<' ';
	}
	for(k=1;k<maxa;++k)
	{
	  a[k]+=q;
	}
	for(k=maxa+1;k<=n;++k)
	{
	  a[k]+=q;
	}
	a[++n]=floor(a[maxa]*p);
	a[maxa]-=a[n];
  }
  cout<<endl;
  sort(a+1,a+n+1,cmp);
  for(i=t;i<=n;i+=t)
  {
  	cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
inline bool cmp(const int &a,const int &b)
{
  return a>b;
}
