//U55107 WD与矩阵
#include<cstdio>
#define ll long long
#define H 998244353
using namespace std;
inline ll ksm(ll);
inline void read(int&);
void write(const int&);
int main()
{
  register int n=0,m=0,t=0;
  for(read(t);t--;)
  {
    read(n);read(m);
    write(ksm((ll)(n-1)*(m-1)));
    putchar('\n');
  }
  return 0;
}
inline ll ksm(ll b)
{
  register ll a=2,ret=1;
  for(;b;b>>=1)
  {
    if(b&1)
    {
     (ret*=a)%=H;
    }
    (a*=a)%=H;
  }
  return ret;
}
void write(const int &x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}