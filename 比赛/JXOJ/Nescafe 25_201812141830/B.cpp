#include<cstdio>
#define MAXN 200020
using namespace std;
int a[MAXN],n=0,ans=0;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0,pre=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=1,j=2;j<=n;i=j,++j)
  {
    for(;a[i]<pre&&j<=n;++j)
    {
      a[i]+=a[j];
      ++ans;
    }
    if(a[i]<pre)
    {
      ++ans;
    }
    pre=a[i];
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}