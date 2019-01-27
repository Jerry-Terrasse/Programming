#include<iostream>
#include "memory.h"
#include<cstring>
#define MAXL 1000010
#define p 1000000007
#define ll long long
using namespace std;
ll nx[MAXL],num[MAXL],n=0,ans=1,len=0;
char s[MAXL]="";
int main()
{
  ll i=0,j=0,k=0;
  ios::sync_with_stdio(0);
  for(cin>>n;n--;)
  {
  	memset(nx,0,sizeof(nx));
  	memset(num,0,sizeof(num));
  	memset(s,'\0',sizeof(s));
  	ans=1;
	cin>>s;
	len=strlen(s);
  	for(i=1,j=0;i<len;i++)
  	{
  	  for(;j && s[i]!=s[j];j=nx[j-1]);
  	  if(s[i]==s[j])
  	  {
  	    j++;
	  }
	  nx[i]=j;
	  for(k=j;k;k=nx[k-1])
	  {
	  	if((k<<1)<=i+1)
	  	{
	  	  num[i]++;
		}
	  }
	}
	for(i=0;i<len;i++)
	{
	  ans*=num[i]+1;
	  ans%=p;
	}
	cout<<ans<<endl;
  }
  return 0;
}
