#include<cstdio>
#include "memory.h"
#define MAXN 100010
using namespace std;
int f[MAXN],a[MAXN],b[MAXN],n=0,ans=0;
char c='\0';
inline void read(int&);
void write(const int&);
void dfs(const int&);
int main()
{
  register int i=0,j=0,k=0;
  bool bo=false;
  freopen("test.in","r",stdin);freopen("test.out","w",stdout);
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);read(b[i]);
  }
  for(i=1;i<=n;++i)
  {
  	ans=0;
  	memset(f,0,sizeof(f));
  	dfs(a[i]);
  	for(j=1;j<=a[i];++j)
  	{
  	  if(f[j])
  	  {
  	    for(k=1,bo=true;k<=b[i];++k)
  	    {
  	      if((a[i-k]|j)==a[i-k])
  	      {
  	        bo=false;
  	        break;
		  }
		}
		if(bo)
		{
		  ++ans;
		}
	  }
	}
	write(ans);
	putchar('\n');
  }
  return 0;
}
void dfs(const int &x)
{
  if(f[x]||!x)
  {
  	return;
  }
  register int i=0;
  f[x]=1;
  for(i=0;i<5;++i)
  {
  	if(1<<i&x)
  	{
  	  dfs(1<<i^x);
	}
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
