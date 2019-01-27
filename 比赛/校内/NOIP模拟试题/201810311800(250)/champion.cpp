#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 44
#define MAXA 1000000010
using namespace std;
int f[2][1<<(MAXN>>1)],a[MAXN],cnt[2],n=0,m=0,k=0,o=0;
ll ans=0;
char c='\0';
inline void read(int&);
void write(const ll&);
void dfs(const int&,const int&);
int main()
{
  register int i=0;
  freopen("champion.in","r",stdin);freopen("champion.out","w",stdout);
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  m=n+1>>1;
  dfs(1,0);
  m=n+1;o=1;
  dfs(n+1>>1,0);
  sort(f[1]+1,f[1]+cnt[1]+1);
  for(i=1;i<=cnt[0];++i)
  {
  	ans+=upper_bound(f[1]+1,f[1]+cnt[1]+1,k-f[0][i])-f[1]-1;
  }
  write(ans);
  return 0;
}
void dfs(const int &x,const int &w)
{
  if(x==m)
  {
  	f[o][++cnt[o]]=w;
  	return;
  }
  if(w+a[x]<=k)
  {
  	dfs(x+1,w+a[x]);
  }
  dfs(x+1,w);
  return;
}
void write(const ll &x)
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
