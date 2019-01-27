#include<iostream>
#include<cmath>
using namespace std;
long double x=0;
int n=0;
int main()
{
  cin>>x;
  x=1-x/100;
  n=ceil(log(x)/log(0.98));
  cout<<n<<endl;
  return 0;
}
