#include<cstdio>
#define int long long
#define MAX 1000010
#define H 1000000007
//#define H 3
//#define register signed
using namespace std;
int mem[MAX],f[2],g[2],k=0,l=0,r=0,ans=0,cnt=0;
inline void read(int&);
void write(const int&);
inline int pow(int,int);
inline int arc(const int&);
signed main()
{
  register int i=0,pro=1;
  read(k);read(l);read(r);
  --(k+=l);
  f[1]=1;
  for(i=1;i<=l;++i)
  {
  	(f[i&1]+=f[i&1^1])%=H;
  }
  g[0]=f[0];g[1]=f[1];
  if(f[l&1])
  {
  	pro=f[l&1];
  }
  else
  {
  	cnt=1;
  }
  for(i=l+1;i<=k;++i)
  {
	(g[i&1]+=g[i&1^1])%=H;
	if(g[i&1])
	{
	  (pro*=g[i&1])%=H;
	}
	else
	{
	  ++cnt;
	}
  }
  if(!cnt)
  {
  	ans=pro;
  }
  for(i=l+1,++k;i<=r;++i,++k)
  {
  	if(f[i&1^1])
  	{
  	  (pro*=arc(f[i&1^1]))%=H;
  	}
  	else
  	{
  	  --cnt;
  	}
  	(f[i&1]+=f[i&1^1])%=H;
  	(g[k&1]+=g[k&1^1])%=H;
  	if(g[k&1])
  	{
  	  (pro*=g[k&1])%=H;
  	}
  	else
  	{
  	  ++cnt;
  	}
  	if(!cnt)
  	{
  	  (ans+=pro)%=H;
  	}
	/*(pro*=arc(f[i&1^1]))%=H;
  	(f[i&1]+=f[i&1^1])%=H;
  	(g[k&1]+=g[k&1^1])%=H;
  	(pro*=g[k&1])%=H;
  	(ans+=pro)%=H;*/
  }
  write(ans);
  return 0;
}
inline int arc(const int &x)
{
  if(x<MAX)
  {
  	if(mem[x])
  	{
  	  return mem[x];
  	}
  	else
  	{
  	  return mem[x]=pow(x,H-2);
  	}
  }
  else
  {
  	return pow(x,H-2);
  }
}
inline int pow(int a,int b)
{
  int ans=1;
  for(;b;b>>=1)
  {
  	if(b&1)
  	{
  	  (ans*=a)%=H;
  	}
  	(a*=a)%=H;
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
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
