#include<cstdio>
#define MAXN 100010
#define MAXL 16
using namespace std;
char a[MAXN][MAXL];
int b[MAXN],n=0,m=0;
int main()
{
  int i=0,j=0,o=0,pre=0;
  freopen("toy.in","r",stdin);freopen("toy.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i)
  {
	scanf("%d%s",&b[i],a[i]);
  }
  for(i=0;i<m;++i)
  {
  	scanf("%d%d",&o,&j);
  	if(o^b[pre])
  	{
  	  pre+=j;
	}
	else
	{
	  pre-=j;
	}
	for(;pre<0;pre+=n);
	for(;pre>=n;pre-=n);
  }
  printf("%s",a[pre]);
  return 0;
}
