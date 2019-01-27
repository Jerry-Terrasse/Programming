#include<cstdio>
#define ll long long
#define max(x,y) ((x)<(y)?(y):(x))
ll ans=0,n=0;
int main()
{
  register ll i=0,a=0,pre=0;
  scanf("%lld",&n);
  for(i=1;i<=n;++i)
  {
  	scanf("%lld",&a);
  	ans+=max(a-pre,0);
  	pre=a;
  }
  printf("%lld",ans);
  return 0;
}
