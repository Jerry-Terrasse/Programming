#include<iostream>
#define MAXN 1000010
using namespace std;
string f="",s="";
int nx[MAXN],ans[MAXN];
int main()
{
  int i=0,l=0;
  cin>>f>>s;
  nx[0]=0;
  for(i=1;i<s.length();i++)//next[i-1]-->next[i]
  {
  	for(;l>0 && s[i]!=s[l];)
  	{
  	  l=nx[l-1];
	}
  	if(s[i]==s[l])
  	{
  	  l++;
	}
	nx[i]=l;
  }
  ans[0]=0;
  for(i=0;i<f.length();i++)
  {
  	for(;l>0 && (l==s.length() || f[i]!=s[l]);)
  	{
  	  l=nx[l-1];
	}
	if(f[i]==s[l])
	{
	  l++;
	}
	ans[i]=l;
	if(l==s.length())
	{
	  cout<<i+1<<endl;
	}
  }
  for(i=0;i<s.length();i++)cout<<nx[i]<<' ';
  return 0;
}
