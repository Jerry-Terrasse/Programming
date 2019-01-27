#include<cstdio>
#include<cstring>
#define MAXN 5050
using namespace std;
int f[MAXN][MAXN],n=0,t=0;
char a[MAXN];
int main()
{
  register int i=0,j=0,k=0;
  scanf("%d",&t);
  for(;t--;)
  {
  	scanf("%s",a);
  	n=strlen(a);
  	memset(f,0x3f,sizeof(f));
  	for(i=0;i<=n;++i)
  	{
  	  f[i][i]=0;
	}
	for(i=1;i<n;++i)
  	{
  	  for(j=0;j+i<=n;++j)
  	  {
  	    for(k=j;k<=j+i;++k)
  	    {
  	      f[i][j]=min(f[i][j],max(f[j][k],f[k][j+i]));
		}
		
	  }
	}
  }
  return 0;
}
