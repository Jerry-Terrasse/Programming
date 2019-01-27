#include<iostream>
#define int long long
#define H 998244353
using namespace std;
int n=0,k=0;
inline int ksm(int,int);
inline bool prime(const int&);
signed main()
{
  register int i=0;
  cin>>n;k=n;
  for(i=2;i<=n;++i)
  {
    if(prime(i))
    {
      --k;
    }
  }
  cout<<ksm(2,k)<<endl;
  cin>>n;
  return 0;
}
inline bool prime(const int &x)
{
  register int i=0;
  for(i=2;i*i<=x;++i)
  {
    if(!(x%i))
    {
      return false;
    }
  }
  return true;
}
inline int ksm(int a,int b)
{
  register int ans=1;
  for(;b;b>>=1)
  {
    if(b&1)
    {
      (ans*=a)%=H;
    }
    (a*=a)%=H;
  }
  return ans;
}