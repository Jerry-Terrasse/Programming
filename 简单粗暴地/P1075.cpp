#include<iostream>
#define ll long long
using namespace std;
ll n=0;
int main()
{
  ll i=2;
  for(cin>>n;;i++)
  {
  	if(n%i==0)
  	{
  	  cout<<n/i<<endl;
  	  return 0;
	}
  }
  return 0;
}
