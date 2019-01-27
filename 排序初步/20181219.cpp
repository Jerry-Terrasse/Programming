#include<cstdio>
#define MAXN 100010
using namespace std;
void read(int&);
inline void write(const int&);
int main()
{
  register int i=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(f[i]);
  }
  return 0;
}
inline void write(const int &x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}