//U53964 WD与循环
#include<cstdio>
#define int long long
#define H 19491001
using namespace std;
int js[H],arc[H];
inline void read(int&);
void write(const int&);
inline void init();
inline void lucas(int,int);
signed main()
{
  register int t=0,n=0,m=0;
  init();
  for(read(t);t--;)
  {
    read(n);read(m);
    lucas(m+n,n);
  }
  return 0;
}
inline void lucas(int n,int m)
{
  register int ret=1,u=0,v=0;
  for(;n||m;n/=H,m/=H)
  {
    u=n%H;v=m%H;
    if(u<v)
    {
      puts("0");
      return;
    }
    (ret*=js[u])%=H;
    (ret*=arc[js[v]])%=H;
    (ret*=arc[js[u-v]])%=H;
  }
  write(ret);
  putchar('\n');
  return;
}
inline void init()
{
  register int i=0;
  for(js[0]=1,i=1;i<H;++i)
  {
    js[i]=i*js[i-1]%H;
  }
  for(arc[1]=1,i=2;i<H;++i)
  {
    arc[i]=-H/i*arc[H%i]%H+H;
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
/*

C(n+m,n)%H

n m
m+n -> n N*
sigma i=n to m+n
  C(i-1,n-1)
2 9
10 1

1 1
2 1
...
10 1*/