#include<iostream>
#include<iomanip>
#include<cmath>
#define x ((1+sqrt(5))/2)
#define y ((1-sqrt(5))/2)
using namespace std;
int main()
{
  int n=0;
  long double ans=0;
  cin>>n;
  ans=(pow(x,n)-pow(y,n))/(sqrt(5));
  cout<<fixed<<setprecision(2)<<ans<<endl;
  return 0;
}
