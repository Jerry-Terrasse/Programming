#include<cstdio>
#include<algorithm>
#define MAXN 44
#define int long long
//#define register signed
using namespace std;
int f[2][1<<(MAXN>>1)],a[MAXN],cnt[2],n=0,o=0,m=0,x=0,ans=0;
inline void read(int&);
void write(const int&);
void dfs(const int&,const int&);
inline int max(const int&,const int&);
signed main()
{
  register int i=0,j=0;
  freopen("cake.in","r",stdin);freopen("cake.out","w",stdout);
  read(n);read(x);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  m=n>>1;o=0;
  dfs(1,0);
  m=n;o=1;
  dfs((n>>1)+1,0);
  sort(f[1]+1,f[1]+cnt[1]+1);
  for(i=1;i<=*cnt;++i)
  {
  	m=upper_bound(f[1]+1,f[1]+cnt[1]+1,x-f[0][i])-f[1]-1;
  	ans=max(ans,f[0][i]+f[1][m]);
  }
  write(x-ans);
  return 0;
}
inline int max(const int &a,const int &b)
{
  return a<b?b:a;
}
void dfs(const int &p,const int &ans)
{
  if(p==m+1)
  {
  	f[o][++cnt[o]]=ans;
  	return;
  }
  if(ans+a[p]<=x)
  {
  	dfs(p+1,ans+a[p]);
  }
  dfs(p+1,ans);
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
