#include<iostream>
#include<iomanip>
#define ld long double
using namespace std;
inline bool ok(int);
int main()
{
  register int i=0;
  for(i=1;i<1e9;++i)
  {
  	if(ok(i))
  	{
  	  cout<<i<<',';
	}
  }
  return 0;
}
inline bool ok(int x)
{
  for(register int k=0;x;x/=10)
  {
  	k=x%10;
	if(k!=4&&k!=7)
	{
	  return false;
	}
  }
  return true;
}
