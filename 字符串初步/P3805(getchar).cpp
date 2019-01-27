//s:$#a#b#a#b#a#\0
//i:012345678901 2
//p:112141614121 1
//s:$#a#a#a#\0
//i:01234567 8
//p:11234321 1
#include<iostream>
#include<cstring>
#define MAXN 11000010<<1
using namespace std;
long long p[MAXN],m=0,t=0,ans=1;
string s="";
int main()
{
  long long i=0,j=0;
  char c='\0';
  for(s="$";isalpha(c=getchar());)
  {
  	s+='#';
  	s+=c;
  }
  s+='#';
  //cout<<s<<endl;
  p[0]=1;
  for(i=1;i<s.length();i++)
  {
  	if(m>i)
  	{
  	  //cout<<t<<1-i<<endl<<m+1-i<<endl;
      p[i]=min(p[(t<<1)-i],m+1-i);
    }
    else
    {
      p[i]=1;
    }
    for(;s[i-p[i]]==s[i+p[i]];p[i]++);
    if(m<p[i]+i-1)
    {
      m=p[i]+i-1;
      t=i;
    }
    if(ans<p[i])
    {
      ans=p[i];
    }
    //cout<<p[i]<<' ';
  }
  cout<<ans-1<<endl;
  return 0;
}
