#include<cstdio>
using namespace std;
long long ans=0;
int main()
{
  long long a[3]={0,0,0},b[3]={0,0,0},i=0;
  scanf("%lld:%lld:%lld",&a[0],&a[1],&a[2]);
  scanf("%lld:%lld:%lld",&b[0],&b[1],&b[2]);
  for(;i<3;i++)
  {
  	ans*=60;
  	ans+=b[i]-a[i];
  }
  scanf("%lld",&i);
  ans*=i;
  printf("%lld",ans);
  return 0;
}
