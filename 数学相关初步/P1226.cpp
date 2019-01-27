#include<cstdio>
#include<cstdlib>
#include "memory.h"
using namespace std;
int p[9999],bo[9999];
int t=0,i=0,j=0,a=0,b=0,m=0,s=0;
int main()
{
  scanf("%i%i%i",&a,&b,&m);
  printf("%i^%i mod %i=",a,b,m);
  if(b<=0)
  {
  	s=1;s%=m;
	printf("%i\n",s);
  	return 0;
  }
  for(a%=m,s=1;b!=1;b/=2,a*=a,a%=m)
  {
    if(b%2==1)
    {
    	s*=a;
    	s%=m;
    }
  }
  s*=a;s%=m;
  printf("%i\n",s);
  return 0;
}
