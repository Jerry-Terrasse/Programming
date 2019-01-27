#include<iostream>
#include<cmath>
#include<iomanip>
#define ld long double
#define Pi 3.1415926535897932
using namespace std;
int main()
{
  register ld r=0,o=0,n=0,a=0,b=0,c=0,ans=0;
  cin>>n>>r;
  o=cos(2*Pi/n);
  a=o*2+2;
  b=r*4*o-r*4;
  c=r*r*2*o-r*r*2;
  ans=(-b+sqrt(b*b-a*4*c))/(a*2);
  cout<<fixed<<setprecision(11)<<ans<<endl;
  return 0;
}