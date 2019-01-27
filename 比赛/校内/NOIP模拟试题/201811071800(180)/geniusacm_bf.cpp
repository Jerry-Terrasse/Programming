#include<cstdio>
#include<algorithm>
#define int long long
#define register signed
#define MAXN 500050
#define min(x,y) ((x)<(y)?(x):(y))
#define sqr(x) ((x)*(x))
using namespace std;
int tmp[MAXN],a[MAXN],n=0,m=0,k=0,t=0,ans=0;
inline void read(int&);
void write(const int&);
inline bool judge();
inline int work(const int&,const int&);
signed main()
{
  register int i=0,l=0,r=0;
  read(t);
  for(;t--;)
  {
  	read(n);read(m);read(k);
  	for(i=1;i<=n;++i)
  	{
  	  read(a[i]);
  	}
  	for(l=0,r=n;l+1<r;)
  	{
  	  ans=l+r+1>>1;
  	  if(judge())
  	  {
  	  	r=ans;
  	  }
  	  else
  	  {
  	  	l=ans;
  	  }
  	}
  	write(r);
  	putchar('\n');
  }
  return 0;
}
inline int work(const int &u,const int &v)
{
  register int n=min(m,v+1-u>>1),i=0,j=0,ans=0;
  for(i=u;i<=v;++i)
  {
  	tmp[i]=a[i];
  }
  sort(tmp+u,tmp+v+1);
  for(i=u,j=v;i<u+n;++i,--j)
  {
  	ans+=sqr(tmp[i]-tmp[j]);
  }
  return ans;
}
inline bool judge()
{
  register int i=0,j=0,cnt=ans;
  for(i=1;i<=n&&cnt;--cnt,i=j)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  if(work(i,j)>k)
  	  {
  	  	break;
  	  }
  	}
  }
  if(i<=n)
  {
  	return false;
  }
  else
  {
  	return true;
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
