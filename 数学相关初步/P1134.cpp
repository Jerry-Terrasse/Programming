#include<iostream>
#define ak 10
using namespace std;
long long n=0,ans=1;
int main()
{
  int i=0,j=0,a=0,k=0;
  cin>>n;
  for(i=1;i<=n;i++)
  {
  	for(j=i;!(j%2);j/=2,a++);
  	for(;!(j%5);j/=5,k++);
  	ans*=j;
  	ans%=ak;
  }
  for(;k>a;k--)
  {
  	ans*=5;
  	ans%=ak;
  }
  for(;a>k;a--)
  {
  	ans*=2;
  	ans%=ak;
  }
  cout<<ans%10<<endl;
  return 0;
}
