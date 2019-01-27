#include<iostream>
#include<algorithm>
#define MAXN 16
using namespace std;
int a[MAXN],n=0,x=0,sum=0,ans=0;
int main()
{
  int i=0;
  freopen("shopping.in","r",stdin);freopen("shopping.out","w",stdout);
  cin>>x>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  if(a[1]!=1)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  for(;sum<x;++ans)
  {
  	for(i=n;a[i]>sum+1;--i);
  	sum+=a[i];
  }
  cout<<ans<<endl;
  return 0;
}
