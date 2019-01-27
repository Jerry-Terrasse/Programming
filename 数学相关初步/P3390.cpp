#include<iostream>
#define MAXN 110
#define ak 1000000007
using namespace std;
struct mat
{
  long long e[MAXN][MAXN];
  mat operator*(mat);
}a,ans;
long long n=0,k=0;
int main()
{
  int i=0,j=0;
  for(cin>>n>>k;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  cin>>a.e[i][j];
  	  a.e[i][j]%=ak;
    }
  }
  for(i=0;i<n;i++)
  {
  	ans.e[i][i]=1;
  }               
  for(;k;)
  {
	if(k&1)
	{
	  ans=a*ans;
	}
	a=a*a;
	k>>=1;
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  cout<<ans.e[i][j]<<' ';
	}
	cout<<endl;
  }
  return 0;
}
mat mat::operator*(mat b)
{
  mat x;
  int i=0,j=0,k=0;
  for(;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  x.e[i][j]=0;
	}
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  for(k=0;k<n;k++)
  	  {
  	    x.e[i][j]+=e[i][k]*b.e[k][j];
  	    x.e[i][j]%=ak;
      }
	}
  }
  return x;
}
