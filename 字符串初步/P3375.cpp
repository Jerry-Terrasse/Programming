#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
int nx[MAXN],f[MAXN],ans=0;
string s="",t="";
int main()
{
  int i=0,j=0;
  cin>>s>>t;
  for(i=1;i<t.length();i++)
  {
  	for(;j>0 && t[i]!=t[j];j=nx[j-1]);
  	if(t[i]==t[j])
  	{
  	  j++;
    }
    nx[i]=j;
  }
  for(i=0,j=0;i<s.length();i++)
  {
  	for(;j>0 && (j==t.length() || s[i]!=t[j]);j=nx[j-1]);
  	if(s[i]==t[j])
  	{
  	  j++;
    }
    f[i]=j;
    if(j==t.length())
    {
      //ans++;
      cout<<i+2-t.length()<<endl;
    }
  }
  //cout<<ans<<endl;
  for(i=0;i<t.length();i++)
  {
    cout<<nx[i]<<' ';
  }
  cout<<endl;
  /*for(i=0;i<s.length();i++)
  {
    cout<<f[i]<<' ';
  }
  cout<<endl;*/
  return 0;
}
