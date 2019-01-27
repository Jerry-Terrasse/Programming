#include<cstdio>
#include<algorithm>
#define MAXN 300030
using namespace std;
int a[MAXN],b[MAXN],n=0,m=0;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  for(i=1;i<=m;++i)
  {
  	read(b[i]);
  }
  for(i=1;i<=m;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  if(a[j]==b[i])
  	  {
  	    a[j]=-1;
  	    break;
	  }
	}
  }
  for(i=1;i<n;++i)
  {
  	for(j=1;j<n;++j)
  	{
  	  if(a[j]>a[j+1])
  	  {
  	    swap(a[j],a[j+1]);
	  }
	}
  }
  for(i=m+1;i<=n;++i)
  {
  	write(a[i]);
  	putchar(' ');
  }
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
