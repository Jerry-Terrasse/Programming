//P4466_bf [国家集训队]和与积
#include<iostream>
#define int long long
using namespace std;
int n=0,ans=0;
signed main()
{
  register int i=0,j=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
    for(j=i+1;j<=n;++j)
    {
      if(!(i*j%(i+j)))
      {
        ++ans;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}