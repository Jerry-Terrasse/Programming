#include<iostream>
#include<algorithm>
#define MAXN 100010
#define ld long double
#define ll long long
using namespace std;
struct gen
{
  ll t,d;
}a[MAXN];
ll n=0,t=0,ans=0;
inline bool cmp(gen,gen);
int main()
{
  ll i=0;
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i].t>>a[i].d;
  }
  sort(a,a+n,cmp);
  for(i=0;i<n;i++)
  {
  	ans+=t*a[i].d;
  	t+=a[i].t<<1;
  }
  cout<<ans<<endl;
  return 0;
}
inline bool cmp(gen a,gen b)
{
  return (ld)a.t/a.d<(ld)b.t/b.d;
}
