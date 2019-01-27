#include<iostream>
#include<algorithm>
#define MAXN 100010
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int a[MAXN],n=0,m=0,k=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0;
  freopen("del.in","r",stdin);freopen("del.out","w",stdout);
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  sort(a+1,a+n+1);
  m=unique(a+1,a+n+1)-a-1;
  n-=k;
  write(min(n,m));
  return 0;
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
