#include<cstdio>
#define MAXD 2000020
#define lbt(x) ((x)&-(x))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int bt[MAXD],n=0,q=0,x=0,y=0;
inline void read(int&);
void write(const int&);
inline void work(int&,int&,const int&);
inline void add(int,const int&);
inline int sum(int);
int main()
{
  register int i=0,j=0,xl=0,xr=0,yl=0,yr=0;
  //freopen("bird.in","r",stdin);freopen("bird.out","w",stdout);
  read(n);read(q);read(x);read(y);
  for(i=1;i<=n;++i)
  {
  	read(xl);read(yl);read(xr);read(yr);
	work(xl,xr,x);
	work(yl,yr,y);
	xl+=yl;xr+=yr;
	add(xl+1,1);
	add(xr+2,-1);
  }
  for(i=1;i<=q;++i)
  {
  	read(j);
  	write(sum(j+1));
  	putchar('\n');
  }
  return 0;
}
inline int sum(int x)
{
  register int ans=0;
  for(;x;x-=lbt(x))
  {
  	ans+=bt[x];
  }
  return ans;
}
inline void add(int x,const int &k)
{
  for(;x<MAXD;x+=lbt(x))
  {
  	bt[x]+=k;
  }
  return;
}
inline void work(int &l,int &r,const int &x)
{
  if(l>r)
  {
  	l^=r^=l^=r;
  }
  if(x<=l)
  {
  	l-=x;
  	r-=x;
  }
  else if(x>=r)
  {
  	r=x-r;
  	l=x-l;
  	l^=r^=l^=r;
  }
  else
  {
  	r=max(x-l,r-x);
  	l=0;
  }
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
