#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n=0,a=0,b=0,c=0,cnt=0;
int main()
{
  register int i=0,j=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
    for(j=1;i*j<=n&&i+j<=sqrt(2*n);++j)
    //for(j=1;j<=n;++j)
    {
      if(__gcd(i,j)==1)
      {
        c=i*j;
        a=i*(i+j);
        b=j*(i+j);
        if(a<=n&&b<=n&&c<=n)
          cout<<++cnt<<':'<<a<<' '<<b<<' '<<c<<endl;
      }
    }
  }
  return 0;
}