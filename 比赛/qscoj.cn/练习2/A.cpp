#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
string s="",t="";
int nx[MAXN],f[MAXN],ans=0;
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
  	for(;j>0 && (j==t.length()||s[i]!=t[j]);j=nx[j-1]);
  	if(s[i]==t[j])
  	{
  	  j++;
	}
	f[i]=j;
	if(j==t.length())
	{
	  ans++;
	}
  }
  cout<<ans<<endl;
  return 0;
}
