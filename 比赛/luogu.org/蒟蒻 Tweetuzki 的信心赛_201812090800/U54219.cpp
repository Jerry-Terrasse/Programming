#include<iostream>
#include<cmath>
#define int long long
using namespace std;
int m=0,s=0;
signed main()
{
  register int i=0;
  cin>>s;
  s<<=1;
  m=floor(sqrt(s));
  for(i=m;i;--i)
  {
    if(!(s%i))
    {
      m=abs(i-s/i);
      if(m&1)
      {
        m=(m+1)/2;
        cout<<m<<' '<<m+i-1<<endl;
        return 0;
      }
    }
  }
  return 0;
}