#include<iostream>
using namespace std;
int n=0,m=0,a=0x7FFFFFFF,b=0x00000000,ans=0,ani=0;
int main()
{
  int i=0,t=0,bit=0;
  string s="";
  ios::sync_with_stdio(0);
  //freopen("P2114#1.in","r",stdin);
  cin>>n>>m;
  for(;i<n;i++)
  {
  	cin>>s>>t;
  	if(s[0]=='A')
  	{
  	  a&=t;b&=t;
  	  continue;
	}
  	if(s[0]=='O')
  	{
  	  a|=t;b|=t;
  	  continue;
	}
  	if(s[0]=='X')
  	{
  	  a^=t;b^=t;
  	  continue;
	}
  }
  //cout<<"1:"<<a<<endl;
  //cout<<"0:"<<b<<endl;
  for(i=30;i>=0;i--)
  {
  	bit=(1<<i)&b;
	if((1<<i|ani)<=m)
  	{
  	  if(bit<(1<<i&a))
  	  {
  	    ani|=1<<i;
		bit=1<<i&a;
	  }
	}
	if(bit)
  	{
  	  ans|=bit;
	}
  }
  cout<<ans<<endl;
  //fclose(stdin);
  return 0;
}
