#include<iostream>
#define MAXN 44
#define MAXA 1000000010
using namespace std;
int a[MAXN],n=0,k=0,ans=0;
void dfs(const int&,const int&);
int main()
{
  int i=0;
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  dfs(1,k);
  cout<<ans<<endl;
  return 0;
}
void dfs(const int &x,const int &w)
{
  if(x==n+1)
  {
  	++ans;
  	return;
  }
  if(w>=a[x])
  {
  	dfs(x+1,w-a[x]);
  }
  dfs(x+1,w);
  return;
}
