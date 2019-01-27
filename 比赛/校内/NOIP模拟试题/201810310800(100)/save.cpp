#include<iostream>
using namespace std;
int n=0,m=0,ans=0;
int main()
{
  int i=0,a=0,u=0,v=0;
  freopen("save.in","r",stdin);freopen("save.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=m;++i)
  {
  	cin>>u>>v;
  }
  for(i=1;i<=n;++i)
  {
  	cin>>a;
  	ans+=a;
  }
  cout<<ans<<endl;
  return 0;
}
