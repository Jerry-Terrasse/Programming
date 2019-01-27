#include<iostream>
using namespace std;
int r=0,g=0;
inline int ak(int);
int main()
{
  cin>>r>>g;
  if(r==0 && g==0)
  {
  	cout<<"NO"<<endl;
  	return 0;
  }
  if(ak(r-g)<=1)
  {
  	cout<<"YES"<<endl;
  }
  else
  {
  	cout<<"NO"<<endl;
  }
  return 0;
}
inline int ak(int x)
{
  return x<0?-x:x;
}
