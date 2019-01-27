#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
string cmd="";
int q[MAXN],h=1,t=1,n=0,ans=0;
int main()
{
  int i=1,j=0,x=0;
  for(cin>>n;i<=n;++i)
  {
  	cin>>cmd;
  	if(cmd[0]=='s')
  	{
  	  cin>>x>>cmd;
  	  q[t++]=x;
	}
	else if(cmd[0]=='m')
	{
	  ans=0x7fffffff;
	  for(j=h;j<t;++j)
	  {
	  	ans=min(ans,q[j]);
	  }
	  if(ans==0x7fffffff)
	  {
	  	cout<<"So happy!no bug!"<<endl;
	  }
	  else
	  {
	  	cout<<ans<<"bug"<<endl;
	  }
	}
	else
	{
	  if(h<t)
	  {
	  	++h;
	  }
	  else
	  {
	  	cout<<"So happy!no bug!"<<endl;
	  }
	}
  }
  return 0;
}
