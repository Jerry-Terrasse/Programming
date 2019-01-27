#include<cstdio>
#define ll long long
#define MAXN 100010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
ll a[MAXN],b[MAXN],f[MAXN],n=0,k=0,maxf=0;
char c='\0';
inline void read(ll&);
void write(const ll&);
int main()
{
  register int i=0;
  freopen("dish.in","r",stdin);freopen("dish.out","w",stdout);
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  for(i=1;i<=n;++i)
  {
  	b[i]=b[i-1]+a[i];
  }
  for(i=1;i<=k;++i)
  {
  	f[k]+=a[i]*i;
  }
  for(;i<=n;++i)
  {
  	f[i]=f[i-1]-b[i-1]+b[i-k-1]+a[i]*k;
  }
  for(i=k;i<=n;++i)
  {
  	maxf=max(maxf,f[i]);
  }
  write(maxf);
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
