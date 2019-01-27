#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int i=0,j=0,a=0,b=0;
  bool k=false;
  cin>>a>>b;
  for(i=max(2,a);i<=b;i++)
  {
    k=true;
	for(j=2;j<=sqrt(i);j++)
    {
      if(i%j==0)
      {
      	k=false;
        break;
	  }
	}
	if(k)
	{
	  cout<<i<<",";
	}
  }
}
