//sequence_bf
#include<iostream>
#define MAXN 100010
using namespace std;
int a[MAXN],n=0,q=0,k=0,ans=0;
inline void work(const int&,const int&);
int main()
{
  register int i=0,u=0,v=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>q>>k;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  for(;q--;)
  {
    cin>>u>>v;
    work(u,v);
    cout<<ans<<endl;
  }
  return 0;
}
inline void work(const int &l,const int &r)
{
  register int i=0,j=0,sum=0,ret=0;
  for(i=l;i<=r;++i)
  {
    for(j=i,sum=a[i];j<=r;++j)
    {
      sum&=a[j];
      if(!(sum%k))
      {
        ++ret;
      }
    }
  }
  ans=ret;
  return;
}