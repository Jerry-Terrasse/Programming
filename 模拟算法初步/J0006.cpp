#include<iostream>
using namespace std;
int n=0,t=0;
int main()
{
  register int i=0,j=0,ans=0;
  ios::sync_with_stdio(false);
  cin>>t;
  for(;t--;)
  {
    ans=0;
    cin>>n;
    for(i=-100;i<=100;++i)
    {
      j=n-i;
      if(j>=-100&&j<=100)
      {
        ++ans;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}