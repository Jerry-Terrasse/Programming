//bad
#include<cstdio>
#define int long long
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;
int a[MAXN],s[MAXN],n=0,k=0,ans=0;
inline void read(int&);
void write(const int&);
inline void work();
signed main()
{
  register int i=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
    s[i]=s[i-1]+a[i];
  }
  for(k=1;k<=n;++k)
  {
    work();
    if(ans<0)
    {
      putchar('-');
      write(-ans);
    }
    else
    {
      write(ans);
    }
    putchar(' ');
  }
  return 0;
}
inline void work()
{
  register int i=0,ret=0;
  ans=-INF;
  for(i=1;i<=k;++i)
  {
    ret+=i*a[i];
  }
  if(ans<ret)
  {
    ans=ret;
  }
  for(;i+k-1<=n;++i)
  {
    ret+=k*a[i+k-1]-a[i-1];
    ret-=s[i+k-2]-s[i-1];
    if(ans<ret)
    {
      ans=ret;
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
  register bool bo=false;
  for(x=0;c<'0'||c>'9';c=getchar())
  {
    if(c=='-')
    {
      bo=true;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  if(bo)
  {
    x=~x+1;
  }
  return;
}