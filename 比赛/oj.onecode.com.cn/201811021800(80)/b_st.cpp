#include<cstdio>
#define ll long long
using namespace std;
inline void read(ll&);
void write(const ll&);
void bitwrite(const ll&);
int main()
{
  register ll t=0,a=0,b=0,n=0,ans=0,i=0,j=0,cnt=0;
  freopen("b.in","r",stdin);
  read(t);
  for(;t--;)
  {
  	ans=0;
	read(a);read(b);read(n);
  	for(i=1;i<=n;++i)
  	{
  	  b+=a;
  	  cnt+=b/16;
  	  b%=16;
	  printf("%d",__builtin_popcountll(b));
  	  putchar(' ');
  	  putchar(':');
  	  printf("%d",__builtin_popcount(cnt));
  	  putchar(' ');
  	  //printf("%5lld",ans+=__builtin_popcountll(b));
  	  //putchar(' ');
  	  //bitwrite(__builtin_popcountll(b));
  	  //putchar(' ');
  	  //bitwrite(ans);
  	  //putchar('\n');
	}
	write(ans);
	putchar('\n');
  }
  return 0;
}
void bitwrite(const ll &x)
{
  register int i=0;
  for(i=7;i>=0;--i)
  {
  	putchar(1<<i&x?'1':'0');
  }
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
inline void read(ll &x)
{
  register int c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
