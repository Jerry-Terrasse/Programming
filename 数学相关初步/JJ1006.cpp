#include<cstdio>
#include<algorithm>
#include<cmath>
#define num 100000
using namespace std;
long long zs[num];
long long n=0,s=0;
long long rem[1000000];
int m=0;
inline void priming();
long long dg(long long);
int main()
{
  int i=0,j=0,a=0;
  priming();
  scanf("%lli",&n); 
  rem[1]=1;
  for(;i<n;i++)
  {
  	scanf("%lli",&a);
	s+=dg(a);
  }
  printf("%lli\n",s);
  return 0;
}
long long dg(long long x)
{
  if(x<1e6 && rem[x])
  {
  	return rem[x];
  }
  int i=0;
  long long ans=1+x;
  for(;zs[i]<=sqrt(x);i++)
  {
  	if(x%zs[i]==0)
  	{
  	  ans=max(ans,1+dg(zs[i])*x/zs[i]);
  	  ans=max(ans,1+dg(x/zs[i])*zs[i]);
	}
  }
  if(x<1e6)
  {
  	return rem[x]=ans;
  }
  return ans;
}
inline void priming()
{
  int j=0,n=29,i=9,k=0;
  zs[0]=2;
  zs[1]=3;
  zs[2]=5;
  zs[3]=7;
  zs[4]=11;
  zs[5]=13;
  zs[6]=17;
  zs[7]=19;
  zs[8]=23;
  while (i<num)
  {
    j=0;
    k=sqrt(n);
    while (zs[j]<=k)
    {
      if(n%zs[j]==0)
	  {
	  	break;
	  }
	  j++;
    }
    if(zs[j]>k)
	{
	  zs[i]=n;
	  i++;
	}
    n+=2;
  }
  return;
}
