#include<cstdio>
#include "memory.h"
#define int long long
#define H 1000000007
#define MAXN 1000010
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int num[MAXN],nxt[MAXN],t=0,ans=0;
char a[MAXN];
inline void work();
signed main()
{
  register int i=0;
  scanf("%lld",&t);
  for(;t--;)
  {
    scanf("%s",a+1);
    work();
    for(i=ans=1;a[i];++i)
    {
      (ans*=num[i]+1)%=H;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
inline void work()
{
  register int i=0,j=0;
  memset(nxt,0,sizeof(nxt));
  memset(num,0,sizeof(num));
  for(i=2;a[i];++i)
  {
    for(;j&&a[j+1]!=a[i];j=nxt[j]);
    if(a[j+1]==a[i])
    {
      ++j;
    }
    nxt[i]=j;
  }
  for(i=1;a[i];++i)
  {
    for(j=nxt[i];j>(i>>1);j=nxt[j]);
    for(;j;j=nxt[j],++num[i]);
  }
  return;
}