#include<iostream>
#include<algorithm>
#include<iomanip>
#define MAXN 2005
using namespace std;
struct hum
{
  int id;
  int t;
}a[MAXN];
int n=0;
long long s=0;
inline bool cmp(hum,hum);
int main()
{
  int i=1;
  a[0].id=0;a[0].t=0;
  cin>>n;
  for(;i<=n;i++)
  {
	cin>>a[i].t;
  	a[i].id=i;
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;i++)
  {
  	cout<<a[i].id<<' ';
  }
  cout<<endl;
  for(i=1;i<=n;i++)
  {
  	a[i].t+=a[i-1].t;
  	s+=a[i-1].t;
  }
  cout<<fixed<<setprecision(2)<<(long double)s/n;
  return 0;
}
inline bool cmp(hum a,hum b)
{
  return (a.t<b.t)||((a.t==b.t)&&(a.id<b.id));
}
