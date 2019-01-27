//P1006 传纸条
#include<iostream>
#define MAXN 55
using namespace std;
const int dx[4]={0,-1,0,-1};
const int dy[4]={0,0,-1,-1};
int f[MAXN<<1][MAXN][MAXN],a[MAXN][MAXN],n=0,m=0;
inline void max(int&,const int&);
int main()
{
  register int i=0,j=0,k=0,l=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      cin>>a[i][j];
    }
  }
  for(i=3;i<n+m;++i)
  {
    for(j=1;j<i&&j<=n;++j)
    {
      for(k=1;k<i&&k<=n;++k)
      {
        if(j==k)
        {
          continue;
        }
        for(l=0;l<4;++l)
        {
          max(f[i][j][k],f[i-1][j+dx[l]][k+dy[l]]);
        }
        f[i][j][k]+=a[j][i-j];
        f[i][j][k]+=a[k][i-k];
      }
    }
  }
  cout<<f[n+m-1][n][n-1]<<endl;
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