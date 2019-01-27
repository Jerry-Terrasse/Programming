#include<iostream>
#define ll long long
using namespace std;
ll n=1,m=0,k=0,p=10;
int main()
{
  ll i=0;
  cin>>k>>m;
  k*=9;
  k++;
  k%=m;
  p%=m;
  for(;;n++)
  {
  	if(p==k)
  	{
  	  break;
	}
	p=(p<<1)+(p<<3);
	p%=m;
  }
  cout<<n<<endl;
  return 0;
}
