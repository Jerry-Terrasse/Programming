#include<cstdio>
#define ll long long
using namespace std;
inline void read(ll&);
void write(const ll&);
int main()
{
  register ll t=0,a=0,b=0,n=0,ans=0,i=0,j=0;
  read(t);
  for(;t--;)
  {
  	ans&=0;
	read(a);read(b);read(n);
  	for(i=1;i<=n;++i)
  	{
  	  ans+=__builtin_popcountll(b+=a);
	}
	write(ans);
	putchar('\n');
  }
  return 0;
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
