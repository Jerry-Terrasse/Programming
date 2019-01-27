#include<cstdio>
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
struct pr
{
  int dis,x,y;
  inline bool operator<(const pr&);
  inline pr(const int&,const int&,const int&);
};
int a[MAXN],n=0;
bool use[MAXN];
char b[MAXN];
priority_queue<pr>q;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  read(n);
  scanf("%s",b);
  for(i=n;i;--i)
  {
  	b[i]=b[i-1];
  }
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  for(i=2;i<=n;++i)
  {
  	if(b[i]!=b[i-1])
  	{
  	  q.push(pr(i-1,i));
  	}
  }
  
  return 0;
}
inline pr::pr(const int &idis,const int &ix,const int &iy)
{
  dis=abs(a[ix]-a[iy]);x=ix;y=iy;
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
inline bool pr::operator<(const pr &b)
{
  return dis<b.dis||(dis==b.dis&&x<b.x)||(dis==b.dis&&x==b.x&&y<b.y);
}
