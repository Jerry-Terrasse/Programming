#include<iostream>
using namespace std;
int n=0,ans=0;
void dfs(const int&,const int&);
int main()
{
  cin>>n;
  dfs(n,n);
  cout<<ans<<endl;
  return 0;
}
void dfs(const int &x,const int &s)
{
  if(!x)
  {
    ++ans;
    return;
  }
  register int i=0;
  for(i=max(s-x+1,0);i<=s;++i)
  {
    dfs(x-1,s-i);
  }
  return;
}