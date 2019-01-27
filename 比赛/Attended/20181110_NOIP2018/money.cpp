#include<cstdio>
#include<algorithm>
#include<bitset>
#define MAXN 110
#define MAXA 25050
using namespace std;
int a[MAXN],t=0,n=0,ans=0;
bitset<MAXA>bt;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0,k=0,m=0;
  read(t);
  for(;t--;)
  {
  	read(n);
  	bt&=0;ans=n;
  	for(i=1;i<=n;++i)
  	{
  	  read(a[i]);
  	}
  	sort(a+1,a+n+1);
  	bt[0]=1;
	for(i=1;i<=n;++i)
  	{
  	  if(bt[a[i]])
  	  {
  	  	--ans;
  	  }
  	  else
  	  {
  	  	m=MAXA/a[i]+1;
  	  	for(k=0;(1<<k)<m;++k);
  	  	for(j=0;j<=k;++j)
  	  	{
  	  	  bt|=bt<<a[i];
  	  	  a[i]<<=1;
  	  	}
  	  }
  	}
  	write(ans);
  	putchar('\n');
  }
  return 0;
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
