#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long n=0,a[100000];
void so(long,long);
int main()
{
  long i=0;
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[i]);
  }
  so(0,n-1);
  for(i=0;i<n;i++)
  {
  	printf("%i ",a[i]);
  }
  printf("\n");
  return 0;
}
void so(long l,long r)
{
  if(l>=r)
    return;
  int i=l,j=r,v=a[(l+r)/2];
  for(;i<=j;)
  {
  	for(;(a[j]>v)&&(j--||1););
  	for(;(a[i]<v)&&(i++||1););
	if(i<=j)
	{
	  swap(a[i],a[j]);
	  i++;j--;
	}
  }
  so(l,j);
  so(i,r);
  return;
}
