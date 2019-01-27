#include<cstdio>
#define MAXN 1000010
using namespace std;
int rel[MAXN],f[MAXN],a[MAXN],n=0;
long long now=0,end=0,ans=0;
inline void read(int&);
void write(const int&);
inline void work();
int main()
{
  register int i=0;
  read(n);end=1<<n;
  for(i=0;i<n;++i)
  {
    read(a[i]);
  }
  for(now=0;now<end;++now)
  {
    work();
  }
  write(ans);
  putchar('\n');
  for(i=1;i<=n;++i)
  {
    write(rel[i]);
    putchar(' ');
  }
  return 0;
}
inline void work()
{
  register int i=0,cnt=0;
  long long ret=0;
  for(i=0;i<n;++i)
  {
    if(now>>i&1)
    {
      f[++cnt]=i;
    }
  }
  for(i=n;i--;)
  {
    if(~now>>i&1)
    {
      f[++cnt]=i;
    }
  }
  for(i=1;i<=n;++i)
  {
    ret+=i*a[f[i]];
  }
  if(ret<ans)
  {
    ans=ret;
    for(i=1;i<=n;++i)
    {
      rel[i]=f[i];
    }
  }
  return;
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