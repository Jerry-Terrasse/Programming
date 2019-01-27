#include<iostream>
#include<algorithm>
//#define ll long long
#define MAXN 1010
using namespace std;
struct ll
{
  int 
}
struct gen
{
  ll l,r;
}a[MAXN];
ll n=0;
inline bool cmp(gen,gen);
int main()
{
  ll i=0,pro=1,ans=0;
  for(cin>>n;i<=n;i++)
  {
  	cin>>a[i].l>>a[i].r;
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;i++)
  {
  	pro*=a[i-1].l;
  	ans=max(ans,pro/a[i].r);
  }
  cout<<ans<<endl;
  return 0;
}
inline bool cmp(gen a,gen b)
{
  return a.l*b.r+a.l*b.l*a.r<b.l*a.r+a.l*b.l*b.r;
}
