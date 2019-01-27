#include<cstdio>
#define register signed
#define MAXN 100010
#define MAXG 3030
using namespace std;
int f[MAXN][MAXG],a[MAXN],d[MAXN],g[MAXN],n=0,m=0;
inline void read(int&);
void write(const int&);
inline void work(int,const int&);
inline void output();
int main()
{
  register int i=0,j=0;
  read(n);read(m);
  for(i=1;i<n;++i)
  {
    read(a[i]);
  }
  for(i=1;i<=m;++i)
  {
    read(g[i]);read(d[i]);
  }
  for(i=1;i<=m;++i)
  {
    work(g[i],d[i]);
  }
  output();
  return 0;
}
inline void output()
{
  register int i=0,j=0,ans=0;
  for(i=0;i<n;++i)
  {
    for(j=0,ans=0;j<MAXG;++j)
    {
      if(f[i][j])
      {
        ++ans;
      }
    }
    write(ans);
    putchar('\n');
  }
}
inline void work(int x,const int &id)
{
  for(f[0][id]=1;x;x=a[x])
  {
    f[x][id]=1;
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
