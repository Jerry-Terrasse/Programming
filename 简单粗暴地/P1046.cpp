#include<iostream>
using namespace std;
int main()
{
  int a[10],i=0,k=0,s=0;
  for(i=0;i<=9;i++)
  {
  	cin>>a[i];
  }
  cin>>k;
  k+=30;
  for(i=0;i<=9;i++)
  {
  	if(a[i]<=k)
  	{
  	  s++;
	}
  }
  cout<<s<<endl;
  return 0;
}
