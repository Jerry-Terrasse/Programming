#include<iostream>
#include<iomanip>
using namespace std;
long long a=0,b=0;
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>a>>b;
  cout<<a*b<<' '<<fixed<<setprecision(5)<<(long double)a/b<<endl;
  return 0;
}