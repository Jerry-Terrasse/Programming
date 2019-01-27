#include<cstdio>
#define ll long long
#define int long long
using namespace std;
inline void read(int&);
void write(const int&);
signed main()
{
  register int f[2]={0,0},n=0,a=0,b=0,c=0,d=0,i=0,j=0;
  register ll x=0;
  read(n);read(a);read(b);read(c);read(d);read(*f);x=*f;*f=0;
  for(i=1;i<=n;++i)
  {
    x=((a*x+b)%d*x+c)%d;
    ++f[__builtin_parity(x)];
  }
  write((ll)f[0]*f[1]);
  return 0;
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
