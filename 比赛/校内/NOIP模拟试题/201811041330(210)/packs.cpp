#include<cstdio>
#include<bitset>
#define MAXN 110
#define MAXAN 100010
using namespace std;
int a[MAXN],b[MAXN],n=0,m=0;
bitset<MAXAN>sta[MAXN],stb[MAXN];
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  freopen("packs.in","r",stdin);freopen("packs.out","w",stdout);
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  read(m);
  for(i=1;i<=m;++i)
  {
  	read(b[i]);
  }
  sta[0][0]=stb[0][0]=1;
  for(i=1;i<=n;++i)
  {
  	for(j=i;j;--j)
  	{
  	  sta[j]|=sta[j-1]<<a[i];
	}
  }
  for(i=1;i<=m;++i)
  {
  	for(j=i;j;--j)
  	{
  	  stb[j]|=stb[j-1]<<b[i];
	}
  }
  n+=m;
  for(i=2;i<=n;++i)
  {
  	for(j=1;j<i;++j)
  	{
  	  if((sta[j]&stb[i-j]).count())
  	  {
  	    write(i);
  	    return 0;
	  }
	}
  }
  puts("impossible");
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
