#include<iostream>
using namespace std;
int a=0,s[42],n=0;
int main()
{
  int i=0;
  for(;i<10;i++)
  {
  	cin>>a;
  	a%=42;
  	s[a]=1;
  }
  for(i=0;i<42;i++)
  {
  	if(s[i])
  	{
  	  n++;
	}
  }
  cout<<n<<endl;
  return 0;
}
