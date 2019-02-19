#include<cstdio>
#define int long long
#define MAXN 2000020
using namespace std;
int f[MAXN],a[MAXN],n=0,ans=0;
inline void read(int&);
void write(const int&);
signed main()
{
  register int i=0,j=0,mina=0,ret=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  f[n]=n+1;
  for(i=n-1;i;--i)
  {
    if(a[i]<=a[i+1])
    {
      f[i]=f[i+1];
    }
    else
    {
      f[i]=i+1;
    }
  }
  for(i=1;i<=n;++i)
  {
    for(j=i,mina=a[i];j<=n;)
    {
      j=f[j]-1;
      ret=(j+1-i)*mina;
      if(ans<ret)
      {
        ans=ret;
      }
      ++j;
      if(mina>a[j])
      {
        mina=a[j];
      }
    }
  }
  write(ans);
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
  static char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
