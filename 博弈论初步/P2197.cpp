#include<iostream>
using namespace std;
int t=0,n=0,ans=0;
int main()
{
  int i=0,a=0;
  cin>>t;
  for(;t--;)
  {
  	cin>>n;
  	for(ans=0;n--;)
  	{
  	  cin>>a;
  	  ans^=a;
  	}
  	if(ans)
  	{
  	  cout<<"Yes"<<endl;
  	}
  	else
  	{
  	  cout<<"No"<<endl;
  	}
  }
  return 0;
}
