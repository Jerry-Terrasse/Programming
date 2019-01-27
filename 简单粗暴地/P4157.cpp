#include<cstdio>
#define H 10
#define MAXN 300030
using namespace std;
struct lll
{
  int a[MAXN],l;
  inline lll();
  inline void operator*=(const int&);
  inline void output();
}ans;
int n=0;
inline void work(const int&,const int&);
int main()
{
  register int i=0;
  scanf("%d",&n);
  i=n%3;
  if(i==0)
  {
    work(n/3,1);
  }
  else if(i==1)
  {
    work(n/3-1,4);
  }
  else
  {
    work(n/3,2);
  }
  ans.output();
  return 0;
}
inline void lll::output()
{
  register int i=0;
  printf("%d\n",l);
  if(l>=100)
  {
    for(i=0;i<100;++i)
    {
      putchar(a[l-i]^48);
    }
  }
  else
  {
    for(i=l;i;--i)
    {
      putchar(a[i]^48);
    }
  }
  putchar('\n');
  return;
}
inline void lll::operator*=(const int &x)
{
  register int i=0;
  for(i=1;i<=l;++i)
  {
    a[i]*=x;
  }
  for(i=1;i<=l;++i)
  {
    a[i+1]+=a[i]/H;
    a[i]%=H;
  }
  for(;a[i];++i)
  {
    a[i+1]+=a[i]/H;
    a[i]%=H;
  }
  l=i-1;
  return;
}
inline void work(const int &k,const int &x)
{
  register int i=0;
  ans.a[1]=x;
  for(i=1;i<=k;++i)
  {
    ans*=3;
  }
  return;
}
inline lll::lll()
{
  l=1;
  return;
}