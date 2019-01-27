#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long n=0,a[100000];
void so(long,long);
int main()
{
  //freopen("P1177.in","r",stdin);
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
  int i=l-1,j=r+1,v=a[l/2];
  for(;i<=j;)
  {
  	i++,j--;
	for(;(a[j]>=v)&&(i<j);j--);
  	for(;(a[i]<=v)&&(i<j);i++);
	if(i<=j)swap(a[i],a[j]);
  }
  if(l<j)so(l,j);
  if(i<r)so(i,r);
  /*if(l<i-1)so(l,i-1);
  if(max(1,j)-1<r)so(max(1,j)-1,r);*/
  /*if(j-1<0)
  {
  	so(0,r);
  }
  else
  {
  	so(j-1,r);
  }*/
  return;
}
