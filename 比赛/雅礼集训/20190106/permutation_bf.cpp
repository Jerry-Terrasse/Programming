#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 5050
#define MAXA 40000040
using namespace std;
int f[MAXN],cnt=0,n=0,k=0;
ll ans[MAXA],a[MAXN];
inline void read(int&);
inline void read(ll&);
void write(const int&);
inline void work();
inline bool cmp(const ll&,const ll&);
int main()
{
  register int i=0;
  freopen("permutation.in","r",stdin);freopen("permutation.out","w",stdout);
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
  }
  for(i=1;i<=n;++i)
  {
    f[i]=i;
  }
  sort(a+1,a+n+1,cmp);
  if(k==1)
  {
    work();
    write(ans[0]);
    putchar('\n');
    return 0;
  }
  for(work();cnt<MAXA&&cnt*n<1e8&&next_permutation(f+1,f+n+1);)
  {
    work();
  }
  sort(ans,ans+cnt);
  for(i=0;i<k;++i)
  {
    write(ans[i]);
    putchar('\n');
  }
  return 0;
}
inline bool cmp(const ll &x,const ll &y)
{
  return x>y;
}
inline void work()
{
  register int i=0;
  register ll ret=0;
  for(i=1;i<=n;++i)
  {
    ret+=a[i]*f[i];
  }
  ans[cnt++]=ret;
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
inline void read(ll &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
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