#include<iostream>
#define H 1000000000
using namespace std;
long long n=0,ans=1,t=-1;
int main()
{
  int i=0,j=0,a=0,k=0;
  if(t==-1)
  {
  	freopen("num.in","r",stdin);freopen("num.out","w",stdout);
	cin>>t;
  }
  if(t==0)
  {
  	return 0;
  }
  --t;
  cin>>n;
  for(i=1;i<=n;i++)
  {
  	for(j=i;!(j%2);j/=2,a++);
  	for(;!(j%5);j/=5,k++);
  	ans*=j;
  	ans%=H;
  }
  for(;k>a;k--)
  {
  	ans*=5;
  	ans%=H;
  }
  for(;a>k;a--)
  {
  	ans*=2;
  	ans%=H;
  }
  cout<<ans%10<<endl;
  main();
  return 0;
}
