#include<iostream>
using namespace std;
int cnt=0;
int main()
{
  long long i=0,j=0,bo=false;
  for(i=2147483647;;--i)
  {
  	for(bo=true,j=2;j*j<=i;++j)
  	{
  	  if(!(i%j))
  	  {
  	    bo=false;
  	    break;
	  }
	}
	if(bo)
	{
	  cout<<i<<endl;
	  ++cnt;
	  if(cnt==10)
	  {
	  	return 0;
	  }
	}
  }
  return 0;
}
