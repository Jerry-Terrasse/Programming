#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long n=0,a[100000];
void so(long,long);
int main()
{
  //freopen("P'1177.in","r",stdin);
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
  //fclose(stdin);
  return 0;
}
void so(long l,long r)
{
  if(l>=r)
    return;
  long i=l,j=r,v=a[l];
  for(;i<j;)
  {
  	for(;(a[j]>=v)&&(i<j);j--);
  	swap(a[i],a[j]);
  	for(;(a[i]<=v)&&(i<j);i++);
  	swap(a[i],a[j]);
  	return;
  }
  so(l,i-1);
  so(i+1,r);
  return;
}
