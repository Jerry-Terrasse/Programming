#include<cstdio>
#define MAXN 1010
#define MAXM 100030
using namespace std;
int a[MAXN][MAXM],n=0,m=0,q=0,ans=0;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0,x=0,y=0;
  freopen("phalanx.in","r",stdin);freopen("phalanx.out","w",stdout);
  read(n);read(m);read(q);
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  a[i][j]=++x;
	}
  }
  for(;q--;)
  {
  	read(x);read(y);
  	write(ans=a[x][y]);
  	putchar('\n');
  	for(i=y;i<m;++i)
  	{
  	  a[x][i]=a[x][i+1];
	}
	for(i=x;i<n;++i)
	{
	  a[i][m]=a[i+1][m];
	}
	a[n][m]=ans;
  }
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
  register char c=getchar(),f=0;
  for(x=0;c<'0'|c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  f=1;
	}
  }
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  if(f)
  {
  	++(x=~x);
  }
  return;
}
