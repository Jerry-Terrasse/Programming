#include<iostream>
using namespace std;
int a=0,b=0;
int main()
{
  double x=0,v=7.142857142857143d;
  cin>>a>>b;
  a-=b;
  b=2*b+a;
  for(x=0;x<a;x+=v*=0.98);
  if(b>=(x+=v*=0.98))
  {
  	cout<<'y'<<endl;
  }
  else
  {
  	cout<<'n'<<endl;
  }
  return 0;
}
