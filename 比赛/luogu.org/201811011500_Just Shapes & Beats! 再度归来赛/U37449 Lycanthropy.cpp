#include<cstdio>
#define MAXN 1000010
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int k[MAXN],b[MAXN],n=0,m=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,v=0,x=0;
  read(n);read(m);
  for(;n--;)
  {
  	read(v);read(x);
  	++k[max(1,x-3*v)];
  	--k[max(1,x-2*v)];
  	--k[max(1,x-2*v)];
  	++k[x];
  	++k[x];
  	--k[min(x+2*v,m+1)];
  	--k[min(x+2*v,m+1)];
  	++k[min(x+3*v,m+1)];
  	b[max(1,x-3*v)]+=-x+3*v;
  	b[max(1,x-2*v)]-=-x+3*v;
  	b[max(1,x-2*v)]+=x-v;
  	b[x]-=x-v;
  	b[x]-=x+v;
  	b[min(x+2*v,m+1)]+=x+v;
  	b[min(x+2*v,m+1)]+=x+3*v-2;
  	b[min(x+3*v,m+1)]-=x+3*v-2;
  }
  for(i=1;i<=m;++i)
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
  	  k[i]=~k[i]+1;
	}
  	write(k[i]);
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
