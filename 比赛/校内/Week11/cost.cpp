#include<cstdio>
#include "memory.h"
#include<cmath>
#include<vector>
#include<set>
#define MAXN 10010
using namespace std;
int n=0,m=0,d[MAXN][MAXN];
int main()
{
  freopen("cost.in","r",stdin);
  freopen("cost.out","w",stdout);
  int i=0,j=0,k=0,a=0,b=0,w=0;
  scanf("%i%i",&n,&m);
  memset(d,0x3f,sizeof(d));
  for(i=1;i<=n;i++)
  {
  	d[i][i]=0;
  }
  for(i=1;i<=m;i++)
  {
  	scanf("%i%i%i",&a,&b,&w);
  	d[a][b]=w;
  	d[b][a]=w;
  }
  for(k=1;k<=n;k++)
  {
  	for(i=1;i<=n;i++)
  	{
  	  for(j=1;j<=n;j++)
  	  {
  	    int kk=max(d[i][k],d[k][j]);
  	    if(kk==0x3f3f3f3f)
  	    {
  	      kk=min(d[i][k],d[k][j]);
		}
  	    d[i][j]=min(d[i][j],kk);
	  }
	}
  }
  scanf("%i",&n);//q
  for(i=0;i<n;i++)
  {
  	scanf("%i%i",&a,&b);
  	printf("%i%i ",d[a][b]);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
