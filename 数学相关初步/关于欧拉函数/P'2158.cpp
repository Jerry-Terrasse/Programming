#include<bits/stdc++.h>
using namespace std;
int n=0,s=0;
//long long a[40001];
long long dg(int);
int main()
{
  int i=0,j=0,g=0;
  scanf("%i",&n);
  n--;
  if(!n)
  {
  	printf("0\n");
  	return 0;
  }
  printf("%i",dg(n));
  return 0;
}
long long dg(int n)
{
  if(n==1)
  {
  	return 3;
  }
  long long s=dg(n-1);
  int l=0,i=1;
  for(;i<=n-1;i++)
  {
  	if(__gcd(i,n)==1)
  	{
  	  l++;
	}
  }
  s+=l*2;
  printf("%i:%i:%i\n",n,s,l);
  //printf("%i ",s);
  return s;
}
