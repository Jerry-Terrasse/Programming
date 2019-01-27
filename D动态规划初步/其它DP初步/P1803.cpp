#include<cstdio>
#include<algorithm>
#define MAXN 1000010
using namespace std;
struct line
{
  int l,r;
  inline void input();
}a[MAXN];
int mem[MAXN],n=0;
inline void read(int&);
void write(const int&);
inline bool cmp(const line&,const line&);
int main()
{
  register int i=0,j=0,*f=mem+7;
  read(n);
  for(i=1;i<=n;++i)
  {
    a[i].input();
  }
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;++i)
  {
    for(;j<=a[i].r;++j)
    {
      if(f[j]<f[j-1])
      {
        f[j]=f[j-1];
      }
    }
    if(f[a[i].r]<f[a[i].l]+1)
    {
      f[a[i].r]=f[a[i].l]+1;
    }
  }
  /*for(i=0;i<=a[n].r;++i)
  {
    write(f[i]);
    putchar(' ');
  }*/
  write(f[a[n].r]);
  return 0;
}
inline bool cmp(const line &x,const line &y)
{
  return x.r<y.r;
}
inline void line::input()
{
  read(l);read(r);
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