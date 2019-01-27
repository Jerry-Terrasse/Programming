#include<iostream>
#define ld long double
#define int long long
#define MAXN 55
#define H 998244353
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
int l[MAXN],r[MAXN],n=0,k=0,a=0;
inline int ksm(int,int);
inline int _ksm(const int&,const int&);
inline bool emm(const int&,const int&);
signed main()
{
  register int i=0,sum=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k>>a;
  for(i=1;i<=n;++i)
  {
    cin>>l[i]>>r[i];
    sum+=l[i];
    sum+=r[i];
  }
  if(emm(sum,a<<1))
  {
    cout<<_ksm(a,k)<<endl;
  }
  else
  {
    cout<<_ksm(sum*_ksm(2,H-2)%H,k)<<endl;
    //cout<<_ksm(sum,k)*_ksm(_ksm(2,k),H-2)%H<<endl;
  }
  return 0;
}
inline bool emm(const int &x,const int &y)
{
  if(k&1)
  {
    return x<=y;
  }
  else
  {
    return abs(x)<=abs(y);
  }
}
inline int _ksm(const int &x,const int &y)
{
  if(x<0)
  {
    if(y&1)
    {
      return (H-ksm(-x,y)%H);
    }
    else
    {
      return ksm(-x,y);
    }
  }
  return ksm(x,y);
}
inline int ksm(int x,int y)
{
  register int ret=1;
  for(;y;y>>=1)
  {
    if(y&1)
    {
      (ret*=x)%=H;
    }
    (x*=x)%=H;
  }
  return ret;
}
