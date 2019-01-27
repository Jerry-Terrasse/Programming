//P4466_50pts [国家集训队]和与积
//O(NlogN)
#include<iostream>
#include<cmath>
#include<algorithm>
//#define int long long
using namespace std;
int n=0,m=0,ans=0;
inline int gcd(const int&,const int&);
signed main()
{
  register int i=0,j=0;
  cin>>n;
  m=floor(sqrt(n));
  for(i=1;i<=m;++i)
  {
    for(j=i+1;j<=m;++j)
    {
      if(gcd(i,j)==1)
      {
        ans+=ceil(n/j/(i+j));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
inline int gcd(const int &x,const int &y)
{
  return x?gcd(y%x,x):y;
}