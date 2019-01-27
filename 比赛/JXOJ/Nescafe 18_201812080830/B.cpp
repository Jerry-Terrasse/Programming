#include<cstdio>
#include<cstdlib>
#define MAXN 12
using namespace std;
int n=0,k=0,all=0;
//bitset<1<<MAXN>f,use;
bool f[1<<MAXN],use[1<<MAXN];
void dfs(const int&,const int&);
int main()
{
  register int i=0;
  scanf("%d",&k);
  n=1<<k;all=(1<<k>>1)-1;
  printf("%d ",n);
  use[0]=1;
  dfs(k,0);
  return 0;
}
void dfs(const int &x,const int &pre)
{
  if(x==n)
  {
    for(register int i=1;i<k;++i)
    {
      if(use[pre<<i&n-1])
      {
        return;
      }
    }
    for(register int i=0;i<n;++i)
    {
      putchar(f[i]^48);
    }
    exit(0);
  }
  if(!use[pre<<1])
  {
    f[x]=0;
    use[pre<<1]=1;
    dfs(x+1,pre<<1&all);
    use[pre<<1]=0;
  }
  if(!use[pre<<1|1])
  {
    f[x]=1;
    use[pre<<1|1]=1;
    dfs(x+1,(pre<<1|1)&all);
    use[pre<<1|1]=0;
  }
  return;
}