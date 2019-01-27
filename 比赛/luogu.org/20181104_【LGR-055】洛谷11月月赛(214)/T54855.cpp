#include<cstdio>
using namespace std;
inline void read(int&);
void write(const int&);
int main()
{
  register int f[2]={1,1},i=0,n=0;
  read(n);
  for(i=3;f[i&1]!=0|f[i&1^1]!=1;++i)
  {
  	(f[i&1^1]+=f[i&1])%=n;
  }
  write(i-1);
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
