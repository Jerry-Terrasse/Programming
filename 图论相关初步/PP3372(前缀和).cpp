#include<cstdio>
#include<iostream>
#define MAXN 100010
using namespace std;
long long n=0,m=0,a[MAXN];
int main()
{
  long long i=0,x=0,y=0,j=0,k=0;
  scanf("%li%li",&n,&m);
  for(i=1;i<=n;i++)
  {
  	scanf("%li",&a[i]);
  	a[i]+=a[i-1];
  }
  for(i=1;i<=m;i++)
  {
  	scanf("%i",&x);
  	if(x&1)
  	{
  	  scanf("%li%li%li",&x,&y,&k);
	  for(j=x;j<=y;j++)
	  {
	  	a[j]+=k*(j+1-x);
	  }
	  k*=y+1-x;
	  for(j=y+1;j<=n;j++)
	  {
	  	a[j]+=k;
	  }
	}
	else
	{
	  scanf("%li%li",&x,&y);
	  //printf("%ld%ld\n",a[y]-a[x-1]);
	  cout<<a[y]-a[x-1]<<endl;
	}
  }
  return 0;
}
