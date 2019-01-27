#include<iostream>
#include<cmath>
#include<iomanip>
#define ld long double
#define MAXN 1010
using namespace std;
struct vct
{
  ld a,b;
  inline vct();
  inline vct(const ld&,const ld&);
  inline void input();
  inline void operator=(const vct&);
  inline ld operator*(const vct&);
  inline ld operator!();
  inline vct operator-(const vct&);
}a[MAXN];
ld ans=1e17;
int n=0;
inline void work(const int&,const int&,const int&);
inline ld iabs(const ld&);
int main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
    a[i].input();
  }
  a[0]=a[n];a[n+1]=a[1];
  for(i=1;i<=n;++i)
  {
    work(i,i-1,i+1);
  }
  cout<<fixed<<setprecision(7)<<ans<<endl;
  return 0;
}
inline vct vct::operator-(const vct &x)
{
  return vct(a-x.a,b-x.b);
}
inline vct::vct(const ld &ia,const ld &ib):a(ia),b(ib){}
inline ld vct::operator!()
{
  return sqrt(a*a+b*b);
}
inline ld iabs(const ld &x)
{
  return x<0?-x:x;
}
inline ld vct::operator*(const vct &x)
{
  return iabs(a*x.b-b*x.a);
}
inline void vct::operator=(const vct &x)
{
  a=x.a;b=x.b;
  return;
}
inline void vct::input()
{
  cin>>a>>b;
  return;
}
inline vct::vct()
{
  a=b=0;
  return;
}
inline void work(const int &x,const int &y,const int &z)
{
  register ld ret=0;
  ret=(a[x]-a[y])*(a[x]-a[z]);
  ret/=!(a[y]-a[z]);
  ret/=2;
  if(ret<ans)
  {
    ans=ret;
  }
  return;
}