#include<iostream>
using namespace std;
int n=0,a=0,b=0;
int main()
{
  int i=0,s=0x3FFFFFFF,t=0;
  for(cin>>n;i<3;i++)
  {
  	cin>>a>>b;
  	if((double)n/a==(int)n/a)
  	{
  	  t=n*b/a;
	}
	else
	{
	  t=(n/a+1)*b;
	}
	s=(s>t)?t:s;
  }
  cout<<s<<endl;
  return 0;
}
