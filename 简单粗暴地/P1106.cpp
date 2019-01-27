#include<iostream>
#include<cstring>
#define MAXN 320
using namespace std;
char a[MAXN];
int n=0,k=0;
int main()
{
  register int i=0,j=0,pre=0;
  register bool flag=false;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>a>>k;
  n=strlen(a);
  for(i=n-k;i;--i)
  {
	for(j=pre+1;j+i<=n;++j)
  	{
  	  if(a[j]<a[pre])
  	  {
  	    pre=j;
	  }
	}
	if(flag||a[pre]!='0'||i==1)
	{
	  cout<<a[pre];
	  flag=true;
	}
	++pre;
  }
  return 0;
}
