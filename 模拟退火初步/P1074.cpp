#include<iostream>
#include<ctime>
#include<cstdlib>
#include "memory.h"
#define ld long double
#define X 10
#define MAXN 10
#define MINT 1e-7
#define DT 0.999
using namespace std;
const int w[MAXN][MAXN]=
{
  {0,0,0,0,0,0,0,0,0,0},
  {0,6,6,6,6,6,6,6,6,6},
  {0,6,7,7,7,7,7,7,7,6},
  {0,6,7,8,8,8,8,8,7,6},
  {0,6,7,8,9,9,9,8,7,6},
  {0,6,7,8,9,X,9,8,7,6},
  {0,6,7,8,9,9,9,8,7,6},
  {0,6,7,8,8,8,8,8,7,6},
  {0,6,7,7,7,7,7,7,7,6},
  {0,6,6,6,6,6,6,6,6,6},
};
int a[MAXN][MAXN],b[MAXN][MAXN],n=0,ans=0,t=0;
inline void SA();
inline void make();
inline bool _mk();
inline int cal();
int main()
{
  int i=0,j=0;
  for(i=1;i<=9;++i)
  {
  	for(j=1;j<=9;++j)
  	{
  	  cin>>a[i][j];
	}
  }
  for(;(ld)clock()/CLOCKS_PER_SEC<0.977;SA());
  cout<<ans<<endl;
  return 0;
}
inline void SA()
{
  int i=0,j=0,x=0,y=0,s=0,ns=0;
  t=0x7fffffff;
  make();
  for(s=cal();t>MINT;t*=DT)
  {
  	
  }
  return;
}

inline void make()
{
  int i=0,j=0,k=0;
  
  return;
}
inline int cal()
{
  int ans=0,i=0,j=0;
  for(i=1;i<=9;++i)
  {
  	for(j=1;j<=9;++j)
  	{
  	  ans+=b[i][j]*w[i][j];
	}
  }
  return ans;
}
