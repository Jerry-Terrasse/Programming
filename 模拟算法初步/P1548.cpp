#include<iostream>
using namespace std;
int n=0,m=0,ans=0;
int main()
{
  int i=0,j=0;
  cin>>n>>m;
  if(n>m)
  {
  	swap(m,n);
  }//n<=m
  for(i=1;i<=n;i++)
  {
  	ans+=(n-i+1)*(m-i+1);
  }
  cout<<ans<<' ';
  ans=1+~ans;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=m;j++)
  	{
  	  ans+=(n-i+1)*(m-j+1);
	}
  }
  cout<<ans<<endl;
  return 0;
}
