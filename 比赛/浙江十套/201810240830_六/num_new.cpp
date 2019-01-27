#include<cstdio>
#include "memory.h"
#define MAXL 5050
#define isdigit(x) ((x>='0')&&(x<='9'))
using namespace std;
struct lll
{
  int dat[MAXL],len;
  inline lll();
  inline void init();
  inline void input(const int&);
  inline void operator/=(const int&);
}n;
const int sht1[10]={1,1,2,6,4,4,4,8,4,6};
const int sht2[4]={1,3,9,7};
int work();
int t=0;
int main()
{
  int i=0;
  freopen("num.in","r",stdin);freopen("num.out","w",stdout);
  scanf("%d\n",&t);
  for(;t--;)
  {
  	n.init();
  	n.input(0);
  	putchar(work()^48);
  	putchar('\n');
  }
  return 0;
}
int work();
inline void lll::operator/=(const int &x)
{
  int i=len;
  for(;i;--i)
  {
  	dat[i-1]+=dat[i]%x*10;
  	dat[i]/=x;
  }
  for(;!dat[len];--len);
  dat[0]=0;
  return;
}
int work()
{
  if(n.len<=1&&n.dat[1]<=1)
  {
  	return 1;
  }
  int ans=6;
  ans*=sht1[n.dat[1]];
  n/=5;
  ans*=sht2[(n.dat[2]*10+n.dat[1])%4];
  ans*=work();
  return ans%10;
}
inline void lll::input(const int &x)
{
  char c=getchar();
  if(isdigit(c))
  {
  	input(x+1);
  	dat[len-x]=c^48;
  }
  else
  {
  	len=x;
  }
  return;
}
inline void lll::init()
{
  memset(dat,0,sizeof(dat));
  len=0;
  return;
}
inline lll::lll()
{
  init();
}
