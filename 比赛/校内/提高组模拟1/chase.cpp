#include<iostream>
#include<iomanip>
#define MAXN 100010
#define ld long double
#define ll long long
using namespace std;
struct chase
{
  ll v,t;
  inline ld meet(const chase&);
  inline ld dis(ld);
}a[MAXN];
ll n=0,fast=0,slow=0,late=0,ds=0;
ld l=0,r=0,mid=0,far=0,near=0,now=0;
int main()
{
  ll i=0;
  bool bo=true;
  freopen("graph.in","r",stdin);freopen("graph.out","w",stdout);
  ios::sync_with_stdio(0);
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i].t>>a[i].v;
    if(a[fast].v<a[i].v)
    {
      fast=i;
	}
	if(a[slow].v>a[i].v)
	{
	  slow=i;
	}
	if(a[late].t<a[i].t)
	{
	  late=i;
	}
  }
  l=a[late].t;r=a[slow].meet(a[fast]);
  if(r!=r || r<l)
  {
  	r=l;
  }
  ds=a[fast].v-a[slow].v;
  for(;(r-l)*ds>=0.001 || bo;)
  {
  	bo=false;
	mid=(l+r)/2;
  	fast=slow=0;
  	far=near=a[0].dis(mid);
  	for(i=1;i<n;i++)
  	{
  	  now=a[i].dis(mid);
  	  if(now>far)
  	  {
  	    far=now;
  	    fast=i;
	  }
	  if(now<near)
	  {
	  	near=now;
	  	slow=i;
	  }
	}
	if(a[fast].v<a[slow].v)
	{
	  l=mid;
	}
	else
	{
	  r=mid;
	}
  }
  cout<<fixed<<setprecision(2)<<far-near<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline ld chase::dis(ld water)
{
  return v*(water-t);
}
inline ld chase::meet(const chase& b)
{
  return (ld)(v*t-b.v*b.t)/(v-b.v);
}
