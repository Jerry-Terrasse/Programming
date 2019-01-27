#include<iostream>
using namespace std;
long long n=0,x=0;
int main()
{
  int i=0,s=0;
  for(cin>>x>>n,x--;i<n;i++,x++)
  {
  	x%=7;
	if(x>=5)
  	{
  	  continue;
	}
	s+=250;
  }
  cout<<s<<endl;
  return 0; 
}
