#include<cstdio>
#define MAXN 1000010
#define MAXM 2020
using namespace std;
int f[MAXM],a[MAXN],n=0,m=0,cnt=0,ansa=0,ansb=0;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(j=1;cnt<m;++j)
  {
    if(!f[a[j]])
    {
      ++cnt;
    }
    ++f[a[j]];
  }
  ansa=1;ansb=--j;
  --f[a[j]];
  for(i=1;j<=n;++j)
  {
    ++f[a[j]];
    for(;f[a[i]]>1;--f[a[i]],++i);
    if(j-i<ansb-ansa)
    {
      ansa=i;ansb=j;
    }
  }
  write(ansa);putchar(' ');write(ansb);
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