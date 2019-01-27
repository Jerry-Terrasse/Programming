#include<iostream>
using namespace std;
int main()
{
  int a[100],i=0,j=0;
  for(i=0;i<=99;i++)
  {
  	a[i]=-1;
  }
  for(i=0;i<=99;i++)
  {
  	cin>>a[i];
  	if(a[i]==0)
  	{
  	  break;
	}
  }
  for(j=i-1;j>=0;j--)
  {
  	cout<<a[j]<<' ';
  }
  cout<<endl;
  return 0;
}
