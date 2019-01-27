#include<iostream>
#define ll long long
using namespace std;
int n=0,m=0;
ll f=0,ans=0;
int main()
{
  register int i=0;
  cin>>n>>m;
  ans=f=n;
  for(i=2;i<=m;++i)
  {
  	ans+=((f*=(n+1-i))/=i);
  }
  cout<<ans<<endl;
  return 0;
}
