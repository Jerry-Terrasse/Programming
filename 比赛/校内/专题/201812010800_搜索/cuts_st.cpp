#include<iostream>
#define MAXN 110
#define sim(x,y); {if((x)>(y))x^=y^=x^=y;}
using namespace std;
int f[MAXN][MAXN],n=0,m=0;
void dfs(int,int);
inline int min(const int&,const int&);
int main()
{
  register int i=0,j=0;
  f[1][1]=1;
  //cin>>n>>m;
  for(n=1;n<=100;++n)
  {
    for(m=n;m<=100;++m)
    {
      dfs(n,m);
    }
  }
  //dfs(n,m);
  //cout<<f[n][m]<<endl;
  for(i=0;i<=100;++i)
  {
    cout<<'{';
    for(j=0;j<100;++j)
    {
      cout<<f[i][j]<<',';
    }
    cout<<f[i][100]<<'}'<<(i==100?'}':',');
  }
  return 0;
}
inline int min(const int &x,const int &y)
{
  return x>y?y:x;
}
void dfs(int n,int m)
{
  if(f[n][m])
  {
    return;
  }
  sim(n,m);
  register int ans=0,i=0,u=n,v=m-n;
  if(v&&!f[u][v])
  {
    dfs(u,v);
  }
  f[n][m]=f[u][v]+1;
  for(i=n-1;i;--i)
  {
    if(!f[n-i][i])
    {
      dfs(n-i,i);
    }
    if(!f[m-i][n])
    {
      dfs(m-i,n);
    }
    if(!f[m-i][i])
    {
      dfs(m-i,i);
    }
    if(!f[n-i][m])
    {
      dfs(n-i,m);
    }
    if((ans=1+min(f[n-i][i]+f[m-i][n],f[m-i][i]+f[n-i][m]))<f[n][m])
    {
      f[n][m]=ans;
    }
  }
  f[m][n]=f[n][m];
  //cout<<n<<' '<<m<<' '<<f[n][m]<<endl;
  return;
}