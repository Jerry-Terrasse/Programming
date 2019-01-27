#include<cstdio>
#include<bitset>
#define MAXX 1000010
#define MAXN 44
//#define register signed
using namespace std;
int a=0,n=0,x=0;
bitset<MAXX>bt;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  read(n);read(x);
  bt[0]=1;
  for(i=1;i<=n;++i){
    read(a);
    bt|=bt<<a;
  }
  for(i=x;i;--i){
    if(bt[i]){
      write(x-i);
      return 0;
    }
  }
  write(x);
  return 0;
}
void write(const int &x)
{
  if(x>9){
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar()){
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
