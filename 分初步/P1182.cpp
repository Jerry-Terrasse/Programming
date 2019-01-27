#include<cstdio>
#define MAXN 100010
using namespace std;
int a[MAXN],n=0,m=0,l=0,r=0,ans=0;
inline void read(int&);
inline void write(const int&);
int main()
{
  int i=1,k=0,s=0;
  for(read(n),read(m);i<=n;i++)
  {
  	read(a[i]);
  	if(l<a[i])
  	{
  	  l=a[i];
	}
	r+=a[i];
  }
  for(l--;l+1<r;)
  {
  	ans=(l+r+1)>>1;
  	for(i=1,k=m-1,s=0;k>=0&&i<=n;i++)
  	{
  	  if(s+a[i]<=ans)
  	  {
  	    s+=a[i];
	  }
	  else
	  {
	  	s=a[i];
	  	k--;
	  }
	}
	if(k<0)
	{
	  l=ans;
	}
	else
	{
	  r=ans;
	}
  }
  write(r);
  putchar('\n');
  return 0;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+c-'0';
  }
  return;
}
inline void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
