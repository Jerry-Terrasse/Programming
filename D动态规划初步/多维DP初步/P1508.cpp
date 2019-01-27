//P1508 Likecloud-吃、吃、吃
#include<iostream>
#include "memory.h"
#define MAXN 220
using namespace std;
int f[MAXN][MAXN],a[MAXN][MAXN],n=0,m=0,ans=0x80808080;
inline void max(int&,const int&);
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  memset(f,0xc0,sizeof(f));
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      cin>>a[i][j];
    }
  }
  f[n][m+1>>1]=a[n][m+1>>1];
  f[n][(m+1>>1)-1]=a[n][(m+1>>1)-1];
  f[n][(m+1>>1)+1]=a[n][(m+1>>1)+1];
  //cout<<(m+1>>1)<<endl;
  for(i=n-1;i;--i)
  {
    for(j=1;j<=m;++j)
    {
      max(f[i][j],f[i+1][j-1]+a[i][j]);
      max(f[i][j],f[i+1][j]+a[i][j]);
      max(f[i][j],f[i+1][j+1]+a[i][j]);
    }
  }
  for(i=1;i<=m;++i)
  {
    max(ans,f[1][i]);
  }
  cout<<ans<<endl;
  /*for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      cout<<f[i][j]<<' ';
    }
    cout<<endl;
  }*/
  return 0;
}
inline void max(int &x,const int &y)
{
  if(x<y)
  {
    x=y;
  }
  return;
}
