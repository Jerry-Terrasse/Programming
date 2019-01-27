#include<iostream>
#include<cstring>
using namespace std;
string x="",y="",z="";
int main()
{
  int i=0;
  for(cin>>x>>x>>z;i<x.length();i++)
  {
  	if(x[i]>=z[i])
  	{
  	  y+=z[i];
	}
	else
	{
	  cout<<-1<<endl;
	  return 0;
	}
  }
  cout<<y<<endl;
  return 0;
}
