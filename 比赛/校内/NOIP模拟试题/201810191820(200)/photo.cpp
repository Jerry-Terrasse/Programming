#include<cstdio>
#include<algorithm>
#include "memory.h"
#define MAXN 1010
using namespace std;
inline void read(int&);
void write(const int&);
struct hum
{
  int h[2],o;
}a[MAXN];
int f[MAXN],b[MAXN],bo[MAXN],fail=false,n=0,m=0,ans=0x7fffffff,cnt=0,sum=0,minw=0;
char c='\0';
int main()
{
  int i=0,j=0,k=0;
  freopen("photo.in","r",stdin);freopen("photo.out","w",stdout);
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i].h[0]);read(a[i].h[1]);
  	b[++m]=a[i].h[0];b[++m]=a[i].h[1];
  	sum+=a[i].h[0];
  }
  sort(b+1,b+m+1);
  m=unique(b+1,b+m+1)-b-1;
  for(k=1;k<=m;++k)
  {
  	memset(f,0x3f,sizeof(f));
  	memset(bo,-1,sizeof(bo));
  	fail=false;j=n>>1;cnt=0;minw=sum;
	for(i=1;i<=n;++i)
	{
	  if(a[i].h[1]>b[k])
	  {
	  	if(a[i].h[0]>b[k])
	  	{
	  	  fail=true;
	  	  break;
		}
		else
		{
		  bo[i]=false;
		  --j;
		  if(j<0)
		  {
		  	fail=true;
		  	break;
		  }
		  a[i].o=1;
		  minw+=a[i].h[1]-a[i].h[0];
		}
	  }
	  else
	  {
	  	if(a[i].h[0]>b[k])
	  	{
	  	  bo[i]=false;
	  	  a[i].o=0;
		}
		else
		{
		  f[++cnt]=a[i].h[1]-a[i].h[0];
		  a[i].o=0;
		}
	  }
	}
	if(fail)
	{
	  continue;
	}
	sort(f+1,f+cnt+1);
	for(i=1;i<=j;++i)
	{
	  if(f[i]<0)
	  {
	  	minw+=f[i];
	  }
	  else
	  {
	  	break;
	  }
	}
	if(ans>minw*b[k])
	{
	  ans=minw*b[k];
	}
  }
  write(ans);
  putchar('\n');
  return 0;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
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
