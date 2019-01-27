//P1291 [SHOI2002]百事世界杯之旅
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct S
{
  int a,b;
  inline S();
  inline S(const int&,const int&);
  inline void operator+=(const S&);
  inline void operator++();
  inline void operator--();
}ans;
int n=0;
signed main()
{
  register int i=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
    ans+=S(n,i);
    ++ans;
  }
  --ans;
  return 0;
}
inline void S::operator--()
{
  register int p=a/b,o=0,cnt=0;
  a-=p*b;
  if(a)
  {
    for(o=p;o;o/=10,++cnt);
    for(o=cnt;o--;cout<<' ');
    cout<<a<<endl;
    cout<<p;
    for(p=b;p;p/=10)
    {
      cout<<'-';
    }
    cout<<endl;
    for(o=cnt;o--;cout<<' ');
    cout<<b<<endl;
  }
  else
  {
    cout<<p<<endl;
  }
  return;
}
inline void S::operator++()
{
  register int x=__gcd(a,b);
  a/=x;
  b/=x;
  return;
}
inline void S::operator+=(const S &x)
{
  a=a*x.b+b*x.a;
  b*=x.b;
  return;
}
inline S::S(const int &x,const int &y):a(x),b(y){}
inline S::S()
{
  a=0;b=1;
  return;
}