#include<iostream>
#include<cmath>
using namespace std;
int leng(long);
int a[3]={0,0,0},b[3]={0,0,0};
int main()
{
  int i=0,j=0;
  for(i=0;i<=2;i++)
  {
    cin>>a[i];
    b[i]=9-leng(a[i])-(a[i]<0);
  }
  for(i=0;i<=2;i++)
  {
  	for(j=1;j<=b[i];j++)
  	{
  	  cout<<" ";
	}
	cout<<a[i];
  }
  return 0;
}
int leng(long x)
{
  if(x==0)
  {
  	return 1;
  }
  return log(abs(x))+1;
}
