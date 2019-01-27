#include<cstdio>
#define ll long long
#define MAXN 10000010
using namespace std;
ll x[MAXN],n=0,a=0,b=0,c=0,d=0,ans=0;
char ch='\0';
inline void read(ll&);
void write(const ll&);
int main()
{
  register int i=0,j=0;
  read(n);read(a);read(b);read(c);read(d);read(*x);
  for(i=1;i<=n;++i)
  {
  	x[i]=((x[i-1]*a+b)*x[i-1]+c)%d;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  if(__builtin_popcount(x[i]^x[j])&1)
  	  {
  	    ++ans;
	  }
	}
  }
  write(ans);
  putchar('\n');
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
  for(x=0;ch<'0'||ch>'9';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())
  {
    x=(x<<1)+(x<<3)+(ch^48);
  }
  return;
}
