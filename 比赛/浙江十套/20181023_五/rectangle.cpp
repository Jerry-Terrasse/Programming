#include<cstdio>
#define MAXN 220
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
char a[MAXN][MAXN],c='\0';
int f[MAXN][MAXN],n=0,m=0,ans=0;
int main()
{
  int i=0,j=0,k=0,h=0;
  freopen("rectangle.in","r",stdin);freopen("rectangle.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
    {
      for(c=getchar();c!='.'&&c!='*';c=getchar());
      a[i][j]=c=='.';
    }
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
      for(k=i;k<=n&&a[k][j];++k);
      f[i][j]=k-i;
    }
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
      for(k=j,h=MAXN;k<=m;++k)
      {
      	ans+=h=min(h,f[i][k]);
	  }
    }
  }
  printf("%d\n",ans);
  return 0;
}
