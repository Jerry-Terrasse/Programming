#include<iostream>
#define MAXN 110
using namespace std;
struct matrix
{
  int e[MAXN][MAXN];
  matrix operator*(matrix);
}a,ans;
int n=0,k=0;
int main()
{
  int i=0,j=0;
  for(cin>>n>>k;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  cin>>a.e[i][j];
  	  ans.e[i][j]=a.e[i][j];
	}
  }
  k--;
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
matrix matrix::operator*(matrix b)
{
  matrix x;
  int i=0,j=0,k=0;
  for(;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  for(k=0;k<n;k++)
  	  {
  	    x.e[i][j]+=e[i][k]*b.e[k][j];
      }
	}
  }
  return x;
}
