#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXN 22
#define H 998244353
using namespace std;
int f[1<<MAXN],a[1<<MAXN],all=0,n=0,m=0,ans=0;
inline void read(int&);
void write(const int&);
inline void bitread(int&);
int dfs(const int&);
int main()
{
  register int i=0,j=0;
  memset(f,-1,sizeof(f));
  read(n);read(m);
  all=(1<<n)-1;
  for(i=1;i<=m;++i)
  {
  	bitread(j);
  	read(a[~j&all]);
  }
  f[0]=1;
  dfs(all);
  write(ans);
  return 0;
}
int dfs(const int &now)
{
  if(f[now]!=-1)
  {
  	ans+=f[now]*a[now];
	return f[now];
  }
  register int nxt=now;
  for(f[now]=0;nxt;nxt=nxt-1&now)
  {
  	f[now]+=dfs(now^nxt);
  }
  ans+=f[now]*a[now];
  return f[now];
}
inline void bitread(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(c^48);
  }
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
