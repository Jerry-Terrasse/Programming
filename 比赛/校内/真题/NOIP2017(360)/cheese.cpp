#include<cstdio>
#define int long long
#define MAXN 1010
#define sqr(x) ((x)*(x))
#define dis(i,j) (sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]))
using namespace std;
int us[MAXN],x[MAXN],y[MAXN],z[MAXN],n=0,r=0,h=0,t=0;
inline void read(int&);
void write(const int&);
inline void init();
inline int find(const int&);
signed main()
{
  register int i=0,j=0;
  //freopen("cheese.in","r",stdin);
  //freopen("cheese.out","w",stdout);
  read(t);
  for(;t--;)
  {
  	read(n);read(h);read(r);
  	for(i=1;i<=n;++i)
  	{
  	  read(x[i]);read(y[i]);read(z[i]);
	}
	init();
	for(i=1;i<=n;++i)
	{
	  if(z[i]<=r)
	  {
	  	us[find(i)]=find(0);
	  }
	  if(z[i]+r>=h)
	  {
	  	us[find(i)]=find(n+1);
	  }
	}
	for(i=1,r<<=1,r*=r;i<=n;++i)
	{
	  for(j=1;j<i;++j)
	  {
	  	if(dis(i,j)<=r)
	  	{
	  	  us[find(j)]=find(i);
		}
	  }
	}
	if(find(0)==find(n+1))
	{
	  puts("Yes");
	}
	else
	{
	  puts("No");
	}
  }
  return 0;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline void init()
{
  register int i=0;
  for(i=0;i<=n;++i)
  {
  	us[i]=i;
  }
  us[n+1]=n+1;
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
