#include<iostream>
using namespace std;
int n=0,k=0,x=0,p=0,ans=0;
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin>>n>>ans>>k>>x;
  p=10;
  for(;k;)
  {
  	if(k&1)
  	{
  	  ans*=p;
  	  ans%=n;
	}
	p*=p;
	p%=n;
	k>>=1;
  }
  ans+=x;
  ans%=n;
  cout<<ans<<endl;
  return 0;
}
