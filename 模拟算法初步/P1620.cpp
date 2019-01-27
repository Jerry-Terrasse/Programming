#include<iostream>
#define IF else if
using namespace std;
long long cx=0,co=0,mx=0,mo=0;
int main()
{
  for(;cin>>co>>cx>>mo>>mx;)
  {
  	mo=min(mo,co);
  	mx=min(mx,cx);
	if(mo==0)
  	{
  	  cout<<mx<<endl;
	}
	IF(mx==0)
	{
	  cout<<mo<<endl;
	}
	IF((co+1)*mx<=cx)
	{
	  cout<<(co+1)*mx+co<<endl;
	}
	IF((cx+1)*mo<=co)
	{
	  cout<<(cx+1)*mo+cx<<endl;
	}
	else
	{
	  cout<<co+cx<<endl;
	}
  }
  return 0;
}
