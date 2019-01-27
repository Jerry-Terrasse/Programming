#include<cstdio>
#include "memory.h"
#define MAXN 1010
//#define MAXN 17
#define register signed
float f[MAXN][MAXN],p[MAXN][MAXN],ans=0;
int n=0,now=0;
inline void work();
int main()
{
  register int i=0,j=0;
  freopen("game.in","r",stdin);freopen("game.out","w",stdout);
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  {
  	for(j=0;j<i;++j)
  	{
  	  scanf("%f",&p[i][j]);
  	}
  }
  if(n<13)
  {
  	for(now=0;now<(1<<n);++now)
    {
  	  work();
    }
  }
  else
  {
  	now=0;
  	work();
  }
  printf("%.2f",ans);
  return 0;
}
inline void work()
{
  register int i=0,j=0;
  float sum=0;
  //printf("%d\n",now);
  memset(f,0,sizeof(f));
  f[0][0]=1;
  for(i=1;i<=n;++i)
  {
  	if(now<<1>>i&1)
  	{
  	  for(j=0;j<=i;++j)
  	  {
  	  	f[i][j]=f[i-1][j];
  	  }
  	}
  	else
  	{
  	  for(j=0;j<=i;++j)
  	  {
		f[i][j]=f[i-1][j]*(1-p[i][j])+f[i-1][j-1]*p[i][j-1];
  	  }
  	}
  }
  for(i=1;i<=n;++i)
  {
  	sum+=f[n][i]*i;
  }
  if(ans<sum)
  {
  	ans=sum;
  	//sav=now;
  }
  return;
}
