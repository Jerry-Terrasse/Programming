#include<iostream>
#include<map>
#include<algorithm>
#define ll long long
#define MAXN 1000010
using namespace std;
struct pgm
{
  ll s,t;
}a[MAXN];
int f[MAXN<<1],x[MAXN<<1],y[MAXN<<1],n=0,cnt=0,xcnt=0;
map<ll,int>mp;
inline bool cmp(const pgm&,const pgm&);
inline void record(ll);
int main()
{
  int i=1,j=0;
  for(cin>>n;i<=n;i++)
  {
  	cin>>a[i].s>>a[i].t;
  	x[++cnt]=a[i].s;x[++cnt]=a[i].t;
  }
  sort(x+1,x+cnt+1);
  for(i=1;i<=cnt;i++)
  {
  	record(x[i]);
  }
  for(i=1;i<=n;i++)
  {
  	a[i].s=mp[a[i].s];
  	a[i].t=mp[a[i].t];
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;i++)
  {
  	for(j=xcnt;j>=a[i].t;j--)
  	{
  	  if(f[j]<f[a[i].s-1]+1)
  	  {
  	    f[j]=f[a[i].s-1]+1;
	  }
	}
  }
  cout<<f[xcnt]<<endl;
  return 0;
}
inline void record(ll x)
{
  if(!mp.count(x))
  {
  	mp.insert(make_pair(x,++xcnt));
  	y[xcnt]=x;
  }
  return;
}
inline bool cmp(const pgm &a,const pgm &b)
{
  return a.s<b.s||(a.s==b.s&&a.t<b.t);
}
