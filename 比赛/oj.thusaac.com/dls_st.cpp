#include<iostream>
#include<set>
#define int long long
#define H 998244353
using namespace std;
int t=0,a=0,b=0;
set<int>st;
inline void work(int,int);
inline void init();
signed main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  init();
  cin>>t;
  for(;t--;)
  {
    cin>>a>>b;
    work(a,b);
  }
  return 0;
}
inline void init()
{
  register int i=0;
  for(i=1;i<10000000;++i)
  {
    st.insert(i*i);
  }
  return;
}
inline void work(int a,int b)
{
  register int i=0,n=b-a+1,now=0,pro=0,ans=0;
  for(now=0;now<(1<<n);++now)
  {
    for(i=0,pro=1;i<n;++i)
    {
      if(now>>i&1)
      {
        pro*=a+i;
      }
    }
    if(st.count(pro))
    {
      ++ans;
      if(ans==H)
      {
        ans=0;
      }
    }
  }
  cout<<ans<<endl;
  return;
}