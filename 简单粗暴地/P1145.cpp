#include<iostream>
using namespace std;
int g=0,k=0,m=0;
int main()
{
  int i=0;
  bool bo=false;
  cin>>k;
  for(m=k+1;;m++)
  {
  	for(g=k,i=m-1,bo=true;g;)
  	{
  	  //cout<<i%(k+g)<<endl;
	  i%=k+g;
	  if(i%(k+g)<k)
  	  {
  	    bo=false;
  	    break;
	  }
	  else
	  {
	  	i+=m-1;
	  	g--;
	  }
	}
	if(bo)
	{
	  cout<<m<<endl;
	  break;
	}
  }
  return 0;
}
