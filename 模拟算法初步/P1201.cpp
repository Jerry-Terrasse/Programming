#include<cstdio>
#include<map>
#define H 13331
#define MAXN 17
using namespace std;
int f[MAXN],n=0;
char a[MAXN][MAXN];
map<int,int>mp;
inline int Hash(char*);
int main()
{
  register int i=0,u=0,e=0;
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  {
    scanf("%s",a[i]);
    mp.insert(make_pair(Hash(a[i]),i));
  }
  for(i=1;i<=n;++i)
  {
    scanf("%s%d%d",*a,&u,&e);
    if(e)
    {
      u/=e;
    }
    else
    {
      u=0;
    }
    f[mp[Hash(*a)]]-=u*e;
    for(;e--;)
    {
      scanf("%s",*a);
      f[mp[Hash(*a)]]+=u;
    }
  }
  for(i=1;i<=n;++i)
  {
    printf("%s %d\n",a[i],f[i]);
  }
  return 0;
}
inline int Hash(char *a)
{
  int ret=0;
  for(;*a;++a)
  {
    ret*=H;
    ret+=*a;
  }
  return ret;
}