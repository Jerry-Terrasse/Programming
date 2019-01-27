#include<iostream>
#include<cmath>
#define MAXN 220
using namespace std;
int a[MAXN],n=0;
int dfs(int,int);
int main()
{
  int i=1;
  for(cin>>n;i<=n;++i)
  {
  	cin>>a[i];
  }
  cout<<dfs(1,n)<<endl;
  return 0;
}
int dfs(int l,int r)
{
  if(l==r)
  {
  	return 0;
  }
  int i=0,ans=0x7fffffff;
  for(i=l;i<r;++i)
  {
  	ans=min(ans,dfs(l,i)+dfs(i+1,r)+abs(a[i]-a[r]));
  }
  return ans;
}
