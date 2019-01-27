#include<cstdio>
#define ll long long
#define MAXN 100010
using namespace std;
ll a[MAXN],b[MAXN],c[MAXN],n=0,t=0;
char ch='\0';
inline bool read(ll&);
void write(ll);
void _write(ll);
int main()
{
  ll i=2,s=0;
  for(read(n);i<=n;++i)
  {
  	for(;read(s);)
  	{
  	  a[i]+=s;
  	  a[i]*=60;
	}
	a[i]+=s;
  }
  for(i=2;i<n;++i)
  {
  	read(b[i]);read(c[i]);
  }
  for(i=2;i<n;++i)
  {
  	t+=a[i];
  	if(t%(b[i]+c[i])>=b[i])
  	{
  	  t+=c[i]-(t%(b[i]+c[i])-b[i]);
	}
  }
  t+=a[n];
  write(t);
  return 0;
}
void _write(ll x)
{
  if(x<10)
  {
  	putchar('0');
  }
  printf("%d",x);
  return;
}
void write(ll x)
{
  _write(x/3600);
  x%=3600;
  putchar(':');
  _write(x/60);
  x%=60;
  putchar(':');
  _write(x);
  putchar('\n');
  return;
}
inline bool read(ll &x)
{
  for(x=0;ch<'0'||ch>'9';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())
  {
  	x=(x<<1)+(x<<3)-'0'+ch;
  }
  return ch==':';
}
