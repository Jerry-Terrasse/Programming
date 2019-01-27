#include<cstdio>
#define MAXN 2020
using namespace std;
int f[MAXN][MAXN],t=0,n=0,m=0,H=0;
inline void read(int&);
void write(const int&);
inline void init();
int main()
{
  freopen("problem.in","r",stdin);freopen("problem.out","w",stdout);
  n=MAXN-1;
  read(t);read(H);
  init();
  for(;t--;)
  {
  	read(n);read(m);
  	write(f[n][m]);
  	putchar('\n');
  }
  return 0;
}
inline void init()
{
  register int i=0,j=0;
  for(i=0;i<=n;++i)
  {
  	f[i][0]=1;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=i;++j)
  	{
  	  (f[i][j]=f[i-1][j]+f[i-1][j-1])%=H;
	}
  }
  for(i=0;i<=n;++i)
  {
  	for(j=0;j<=i;++j)
  	{
  	  f[i][j]=!f[i][j];
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
