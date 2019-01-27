#include<cstdio>
#include "memory.h"
using namespace std;
char s[60000001];
int u[10001];
int main()
{
  int m=0,n=0,i=0,j=0,a=0;
  scanf("%i %i",&m,&n);
  for(;i<=m-1;i++)
  {
  	memset(s,0,sizeof(s));
  	memset(u,0,sizeof(u));
	//printf("156879\n");
	for(j=0;j<=n-1;j++)
  	{
  	  scanf("%i",&a);
  	  //s[a]==0?s[a]++:s[a]--;
  	  s[a]++;
  	  u[j]=a;
	}
	//printf("456879\n");
	for(j=0;j<=10001;j++)
	{
	  if(s[u[j]]%2==1)
	  {
	  	printf("%i\n",u[j]);
	  	break;
	  }
	}
  }
  return 0;
}
