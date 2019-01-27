#include<iostream>
#define ld long double
#define MAXN 100010
using namespace std;
int n=0,m=0,cnt=0,ans=0;
ld a[MAXN];
int main()
{
  int i=1,p=0,l=0,r=0;
  for(cin>>n;i<=n;++i)
  {
  	cin>>a[i];
  }
  for(cin>>m;m--;)
  {
  	cin>>l>>r;
	ans=0;p=a[l];cnt=1;
	for(++l;l<=r;++l)
  	{
  	  if(a[l]==p)
  	  {
  	    ++cnt;
	  }
	  else
	  {
	  	ans=max(ans,cnt);
	  	cnt=1;
	  	p=a[l];
	  }
	}
	cout<<max(ans,cnt)<<endl;
  }
  return 0;
}
