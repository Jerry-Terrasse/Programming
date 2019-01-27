#include<iostream>
#define ld long double
using namespace std;
int a[MAXN],use[MAXN],n=0,m=0;
ld ans=0,av=0,sum=0;
int dfs(int,int);
int main()
{
  int i=0;
  for(cin>>n>>m;i<=n;++i)
  {
  	cin>>a[i];
  	sum+=a[i];
  }
  av=sum/m;
  ans=dfs(n,m);
  return 0;
}
int dfs(int x,int y)
{
  int ans=0x7fffffff,i=0,j=0;
  
  return ans;
}
