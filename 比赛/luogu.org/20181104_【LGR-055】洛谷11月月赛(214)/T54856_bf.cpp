#include<iostream>
#define ll long long
#define MAXN 330
#define sqr(x) ((x)*(x))
using namespace std;
int a[MAXN],use[MAXN],n=0;
ll ans=0;
inline void read(int&);
void write(const int&);
void dfs(const int&,const int&,const ll&);
int main()
{
  register int i=0;
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  dfs(1,0,0);
  write(ans);
  return 0;
}
void dfs(const int &x,const int &pre,const ll &sum)
{
  if(x>n)
  {
	if(ans<sum)
	{
	  ans=sum;
	}
	return;
  }
  register int i=0;
  for(i=1;i<=n;++i)
  {
  	if(!use[i])
  	{
  	  use[i]=1;
  	  dfs(x+1,i,sum+sqr(a[pre]-a[i]));
      use[i]=0;
	}
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
