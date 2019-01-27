#include<iostream>
#include "memory.h"
#define MAXN 128
using namespace std;
int a[MAXN][MAXN],b[MAXN][MAXN],n=0,m=0,t=0;
int main()
{
  register int i=0,j=0,k=0;
  register bool ok=false,bo=false;
  freopen("am.in","r",stdin);freopen("am.out","w",stdout);
  cin>>t;
  for(; t--;)
  {
    cin>>n>>m;
    memset(b,-1,sizeof(b));
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
        cin>>a[i][j];
      }
    }
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
        if(!a[i][j])
        {
          for(k=1; k<=n; ++k)
          {
            b[k][j]=0;
          }
          for(k=1; k<=m; ++k)
          {
            b[i][k]=0;
          }
        }
      }
    }
    for(i=1,ok=true; ok&&i<=n; ++i)
    {
      for(j=1; ok&&j<=m; ++j)
      {
        if(a[i][j])
        {
          for(k=1,bo=true; bo&&k<=n; ++k)
          {
            if(b[k][j])
            {
              bo=false;
              break;
            }
          }
          for(k=1; bo&&k<=m; ++k)
          {
            if(b[i][k])
            {
              bo=false;
              break;
            }
          }
          if(bo)
          {
            ok=false;
          }
        }
      }
    }
    if(ok)
    {
      cout<<"YES"<<endl;
      for(i=1; i<=n; ++i)
      {
        for(j=1; j<=m; ++j)
        {
          cout<<-b[i][j]<<' ';
        }
        cout<<endl;
      }
    }
    else
    {
      cout<<"NO"<<endl;
    }
  }

  return 0;
}
