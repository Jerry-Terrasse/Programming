#include<iostream>
#include<algorithm>
#define ll long long
#define MAXN 100010
using namespace std;
int f[MAXN],n=0,k=0;
ll a[MAXN];
inline bool cmp(const ll&,const ll&);
inline void work();
int main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;++i)
  {
    f[i]=i;
  }
  for(work();next_permutation(f+1,f+n+1);work());
  return 0;
}
inline void work()
{
  register int i=0;
  register ll ret=0;
  for(i=1;i<=n;++i)
  {
    ret+=a[i]*f[i];
  }
  cout<<ret<<endl;
  return;
}
inline bool cmp(const ll &x,const ll &y)
{
  return x>y;
}