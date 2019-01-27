#include<iostream>
using namespace std;
int main()
{
  long long a=0,s=0;
  bool b=0;
  int i=0,t=0;
  cin>>a;
  if(a<0)
  {
  	a=-a;
  	b++;
  }
  //
  while(a>0)
  {
  	t=a%10;
  	a=a/10;
  	s=s*10+t;
  }
  if(b)
  {
  	s=-s;
  }
  cout<<s<<endl;
  return 0;
}
