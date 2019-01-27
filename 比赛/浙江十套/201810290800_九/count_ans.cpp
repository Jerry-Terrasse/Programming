#include<cstdio>
#define MAXN 3000010
#define Ha 10000007
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int h[MAXN],s[MAXN],p[10],a=0,b=0,k=0;
char vis[MAXN],c='\0';
long long ans=0;
inline int S(int);
inline void init();
int H(const int&);
inline void read(int&);
void write(const int&);
inline int pow(int,int);
int main()
{
  register int i=0;
  read(k);read(a);read(b);
  init();
  for(i=a;i<=b;++i)
  {
  	ans+=H(i);
  	if(ans>=Ha)
  	{
  	  ans-=Ha;
	}
  }
  write(ans%Ha);
  return 0;
}
inline int pow(int a,int b)
{
  int ans=1;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  ans*=a;
	}
	a*=a;
  }
  return ans;
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
int H(const int &x)
{
  if(h[x])
  {
  	return h[x];
  }
  if(vis[x]==2)
  {
  	return x;
  }
  ++vis[x];
  return h[x]=min(min(x,S(x)),H(S(x)));
}
inline void init()
{
  register int i=0,j=0;
  for(i=1;i<10;++i)
  {
  	p[i]=pow(i,k);
  }
  return;
}
inline int S(int x)
{
  if(s[x])
  {
  	return s[x];
  }
  register int ans=0;
  for(;x;x/=10)
  {
  	ans+=p[x%10];
  }
  return s[x]=ans;
}
