#include<iostream>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define MAXN 1010
#define rr(x) (rand()%(x))
using namespace std;
int a[MAXN],b[MAXN],p[MAXN],use[MAXN],n=0,ans=0;
inline void work();
inline void make();
inline void calc(int&);
int main()
{
  register int i=0;
  freopen("pig.in","r",stdin);freopen("pig.out","w",stdout);
  srand(71806291);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>p[i];
  }
  for(;(float)clock()/CLOCKS_PER_SEC<0.997;work());
  //for(i=10;i--;work());
  cout<<ans<<endl;
  return 0;
}
inline void calc(int &ans)
{
  register int i=0;
  for(i=0;i<n;++i)
  {
  	ans+=max(0,a[b[i]]-p[b[i]]*i);
  }
  return;
}
inline void make()
{
  register int i=0,x=0;
  memset(use,0,sizeof(use));
  for(i=0;i<n;)
  {
  	x=rr(n)+1;
  	if(use[x])
  	{
  	  continue;
	}
	use[x]=1;
	b[i]=x;
	++i;
  }
  return;
}
inline void work()
{
  register int i=0,now=0;
  make();
  calc(now);
  if(ans<now)
  {
  	ans=now;
  }
  return;
}
