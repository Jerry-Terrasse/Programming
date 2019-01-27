#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  long long i=0,j=0,a=0,b=0;
  bool k=false;
  //cin>>a>>b;
  a=2;b=1000010;
  for(i=max((int)a,2);i<=b;i++)
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
  return 0;
}
