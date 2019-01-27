#include<cstdio>
using namespace std;
const char r[10]={6,2,5,5,4,5,6,3,7,6};
int ans=0,s=0,n=0,a=0,b=0,c=0;
inline int u(int);
int main()
{
  int k=0,m=0;
  scanf("%i",&n);
  n-=4;
  for(a=0;a<=1200;a++)
  {
  	m=u(a);
  	if(m>n-4)
  	{
  	  continue;
	}
	k=0;
	for(b=a+1;b<=1200;b++)
  	{
  	  if(m+u(b)+u(a+b)==n)
  	  {
  	  	k++;
	  }
	}
	k*=2;
	if(n==u(a)*2+u(2*a))
	{
	  s+=k+1;
	}
	else
	{
	  s+=k;
	}
  }
  printf("%i\n",s);
  return 0;
}
inline int u(int x)
{
  if(x<=0)
  {
  	return 6;
  }
  int a=x,s=0;
  for(;a>0;a/=10)
  {
  	s+=r[a%10];
  }
  return s;
}
