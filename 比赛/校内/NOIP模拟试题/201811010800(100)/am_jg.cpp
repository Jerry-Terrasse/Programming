#include<iostream>
#include<fstream>
#include<cstring>
#include "memory.h"
#define MAXN 110
using namespace std;
int a[MAXN][MAXN],b[MAXN][MAXN],ans[MAXN][MAXN],n=0,m=0,t=0;
ifstream fin1;
ifstream fin2;
string ln="";
int main()
{
  register int i=0,j=0,k=0;
  fin1.open("am.in");
  fin2.open("am.out");
  fin1>>t;
  for(; t--;)
  {
    fin1>>n>>m;
    fin2>>ln;
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
		fin1>>ans[i][j];
      }
    }
    if(ln=="NO")
    {
      continue;
	}
	for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
		fin2>>a[i][j];
      }
    }
    memset(b,0,sizeof(b));
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
        if(a[i][j])
        {
          for(k=1; k<=n; ++k)
          {
            b[k][j]=1;
          }
          for(k=1; k<=m; ++k)
          {
            b[i][k]=1;
          }
        }
      }
    }
    for(i=1; i<=n; ++i)
    {
      for(j=1; j<=m; ++j)
      {
        if(b[i][j]!=ans[i][j])
        {
          return t+1;
		}
      }
    }
  }
  return 0;
}
