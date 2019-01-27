#include<iostream>
#include<cstdio>
using namespace std;
struct num
{
  int a,b;
  inline num();
  inline void init();
  inline void output();
  inline void sim();
  inline void operator+=(const num&);
  inline bool read();
}ans,a;
int n=0;
inline int gcd(const int&,const int&);
int main()
{
  int i=0;
  for(;a.read();ans+=a);
  ans.output();
  return 0;
}
inline void num::output()
{
  a?(b==1?cout<<a:(b==-1?cout<<-a:(b<0?cout<<-a<<'/'<<-b:cout<<a<<'/'<<b))):cout<<0;
  return;
}
inline void num::sim()
{
  register int d=gcd(a,b);
  a/=d;b/=d;
  return;
}
inline void num::operator+=(const num &x)
{
  a=a*x.b+x.a*b;
  b*=x.b;
  sim();
  return;
}
inline bool num::read()
{
  init();
  cin>>a;
  getchar();
  return cin>>b;
}
inline void num::init()
{
  a=0;b=1;
  return;
}
inline num::num()
{
  init();
  return;
}
inline int gcd(const int &a,const int &b)
{
  return b?gcd(b,a%b):a;
}
