#include<cstdio>
#define MAXN 1000010
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int a[MAXN<<4],aa[MAXN<<4],*k=a+(MAXN<<1),*b=aa+(MAXN<<1),n=0,m=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,v=0,x=0,mini=0x3f3f3f3f,maxi=0x80808080;
  read(n);read(m);
  for(;n--;)
  {
  	read(v);read(x);
  	mini=min(mini,x-3*v);
  	maxi=max(maxi,x+3*v);
  	++k[x-3*v];
  	k[x-2*v]+=2;
  	k[x]+=2;
  	k[x+2*v]-=2;
  	++k[x+3*v];
  	b[x-3*v]+=-x+3*v;
  	b[x-2*v]+=2*x-4*v;
  	b[x]-=2*x;
  	b[x+2*v]+=2*x+4*v;
  	b[x+3*v]-=x+3*v;
  }
  for(i=mini;i<=maxi;++i)
  {
  	k[i]+=k[i-1];
  	b[i]+=b[i-1];
  }
  for(i=1;i<=m;++i)
  {
  	k[i]*=i;
  	k[i]+=b[i];
  	if(k[i]<0)
  	{
  	  putchar('-');
  	  k[i]=-k[i];
	}
  	write(k[i]);
  	putchar(' ');
  }
  return 0;
}
/*inline void out()
{
  int i=0;
  for(i=1;i<=m;++i)
  {
  	k[i]+=k[i-1];
  	//b[i]+=b[i-1];
  	printf("%d ",k[i]);
  }
  for(i=m;i;--i)
  {
  	k[i]-=k[i-1];
  	//b[i]-=b[i-1];
  }
  return;
}*/
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
