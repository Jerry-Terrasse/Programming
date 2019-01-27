#include<iostream>
#define MAX 33
using namespace std;
int f[MAX],n=0;
int main()
{
  register int i=0,j=0,maxf=0,a=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a;
  	for(j=0,maxf=0;j<MAX;++j)
  	{
  	  if(a>>j&1)
  	  {
  	  	maxf=max(maxf,f[j]);
  	  }
  	}
  	++maxf;
  	for(j=0;j<MAX;++j)
  	{
  	  if(a>>j&1)f[j]=maxf;
  	}
  }
  for(i=0,maxf=0;i<MAX;++i)
  {
  	maxf=max(maxf,f[i]);
  }
  cout<<maxf<<endl;
  return 0;
}
