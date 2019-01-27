#include<cstdio>
#include<cstring>
#define MAXN 100010
#define H 1000000007
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int f[4],aim[4],n=0,la=0,lb=0,ans=0;
char ia[MAXN],ib[MAXN],a[MAXN],b[MAXN],*beg=NULL;
inline void work();
inline void inc();
int main()
{
  register int i=0;
  register char *p=NULL,*q=NULL;
  scanf("%s%s%d%d%d%d",ia+1,ib+1,aim,aim+1,aim+2,aim+3);
  *a=*b=*ia=*ib=48;
  la=strlen(ia);lb=strlen(ib);
  if(la<lb||(la==lb&&strcmp(ia,ib)==-1))
  {
    n=lb;
    for(p=a+lb,q=ia+la;q!=ia;*p=*q,--p,--q);
    beg=p;
    for(;p!=a;*p=48,--p);
    for(p=b+lb,q=ib+lb;q!=ib;*p=*q,--p,--q);
  }
  else if(la>lb||(la==lb&&strcmp(ia,ib)!=-1))
  {
    n=la;
    for(p=a+la,q=ib+lb;q!=ib;*p=*q,--p,--q);
    beg=p;
    for(;p!=a;*p=48,--p);
    for(p=b+la,q=ia+la;q!=ia;*p=*q,--p,--q);
  }
  for(;strcmp(a,b)==-1;inc())
  {
    work();
  }
  work();
  printf("%d",ans);
  return 0;
}
inline void work()
{
  register char *p=beg+1;
  memset(f,0,sizeof(f));
  for(;p!=a+n;++p)
  {
    ++f[((*p^48)<<1)+(*(p+1)^48)];
  }
  if(f[0]==aim[0]&&f[1]==aim[1]&&f[2]==aim[2]&&f[3]==aim[3])
  {
    ++ans;
    if(ans==H)
    {
      ans=0;
    }
  }
  return;
}
inline void inc()
{
  register char *p=a+n-1;
  for(;p!=a;--p)
  {
    if(*p=='0')
    {
      *p='1';
      beg=min(beg,p-1);
      return;
    }
    *p='0';
  }
  return;
}