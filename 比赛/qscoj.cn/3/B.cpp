#include<iostream>
#include<cstring>
#define MAXQ 10010
using namespace std;
int p[MAXQ],q=0,m=0,u=0,len=3;
char s[MAXQ]="$#@",k[MAXQ]="",t[MAXQ]="";
inline void man();
int main()
{
  int i=0;
  for(cin>>q>>k;i<q;man(),i++)
  {
    if(k[i]=='-')
    {
      len-=2;
      s[len-1]='@';
      continue;
	}
	s[len-1]=k[i];
	s[len]='#';
	s[len+1]='@';
	len+=2;
	//cout<<endl<<s<<' ';
  }
  return 0;
}
inline void man()
{
  int i=0,ans=0;
  p[0]=1;m=0;u=0;
  for(i=1;i<len;i++)
  {
  	if(i<m)
  	{
  	  p[i]=min(p[2*u-i],m+1-i);
	}
	else
	{
	  p[i]=1;
	}
	for(;s[i+p[i]]==s[i-p[i]];p[i]++);
	if(i+p[i]-1<m)
	{
	  m=i+p[i]-1;
	  u=i;
	}
	if(i&1)
	{
	  ans+=p[i]>>1;
	}
	else
	{
	  ans+=(p[i]+1)>>1;
	}
  }
  cout<<ans<<' ';
  return;
}
//s:$#a#b#a#b#a#\0
//i:012345678901 2
//p:112141614121 1
//s:$#a#a#a#\0
//i:01234567 8
//p:11234321 1
