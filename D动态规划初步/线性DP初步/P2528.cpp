#include<iostream>
#define MAXN 22
using namespace std;
long long f[MAXN][MAXN*MAXN],n=0,t=0;
int main()
{
  long long i=0,j=0,k=0;
  cin>>n>>t;
  if(!t)
  {
  	cout<<1<<endl;
  	for(i=1;i<=n;i++)
  	{
  	  cout<<i<<' ';
	}
	cout<<endl;
	return 0;
  }
  f[2][1]=f[2][0]=1;
  for(i=3;i<=n;i++)
  {
  	for(j=0;j<=i*(i-1)/2;j++)
  	{
  	  for(k=0;k<i;k++)
  	  {
  	  	if(k<=j)f[i][j]+=f[i-1][j-k];
	  }
	}
  }
  cout<<f[n][t]<<endl;
  k=0;
  for(i=1;i<=n;i++)
  {
  	f[0][i]=i;
  }
  for(i=n-1;i>=1;i--)
  {
  	for(j=n;j>i;j--)
  	{
  	  k++;
  	  f[0][i]^=f[0][j];
  	  f[0][j]^=f[0][i];
  	  f[0][i]^=f[0][j];
  	  if(k==t)
  	  {
  	  	goto ac;
	  }
	}
  }
  ac:;
  for(i=1;i<=n;i++)
  {
  	cout<<f[0][i]<<' ';
  }
  cout<<endl;
  return 0;
}
