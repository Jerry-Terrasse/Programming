#include<iostream>
using namespace std;
int n=0,d=0;
int main()
{
  freopen("big.in","r",stdin);freopen("big.out","w",stdout);
  for(register int i=0;i<=1e9;++i);
  cin>>d>>n;
  cout<<((n-d>0?n-d:n>>1)==0?1:(n-d>0?n-d:n>>1))<<endl;
  return 0;
}
