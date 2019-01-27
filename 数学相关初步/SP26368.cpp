#pragma GCC optimize(2)
#include<cstdio>
#include<cstdlib>
#include "memory.h"
using namespace std;
//int p[9999],bo[9999];
long long t=0,i=0,a=0,b=0,m=0,s=0;
int main()
{
  //freopen("temp.in","r",stdin);
  //freopen("temp.out","w",stdout);
  scanf("%lli",&t);
  for(i=0;i<t;i++)
  {
	scanf("%lli%lli%lli",&a,&b,&m);
	if(b<=0)
    {
  	  s=1;s%=m;
	  printf("%i\n",s);
  	  continue;
    }
	for(a%=m,s=1;b>1;b/=2,a*=a,a%=m)
	{
	  if(b%2==1)
	  {
	  	s*=a;
	  	s%=m;
	  }
	}
	s*=a;s%=m;
	printf("%lli\n",s);
	//printf("%lli:%lli\n",i,s);
	/*if(i==523)
	{
	  continue;
	}*/
  }
  //fclose(stdin);
  //fclose(stdout);
  return 0;
}
