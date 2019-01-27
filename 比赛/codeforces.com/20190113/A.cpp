#include<iostream>
#define MAXN 1010
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
int a[MAXN],f[2],g[2],n=0,k=0,ans=0,id=0;
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
    ++g[a[i]==1];
  }
  for(i=1;i<=k;++i)
  {
    f[0]=f[1]=0;
    for(j=0;i+j*k<=n;++j)
    {
      ++f[a[i+j*k]==1];
    }
    if(ans<abs(g[0]-f[0]-g[1]+f[1]))
    {
      ans=abs(g[0]-f[0]-g[1]+f[1]);
      //id=i;
    }
  }
  cout<<ans<<endl;
  //cout<<id<<endl;
  return 0;
}