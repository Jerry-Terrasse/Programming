#include<iostream>
#define MAXN 66
using namespace std;
int f[MAXN],n=0,b=0,d=0,cnt=0;
inline void* judge(const int&);
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>b>>d;
  f[cnt=1]=0;
  for(i=1;cnt<n;++i)
  {
    if(judge(i))
    {
      f[++cnt]=i;
    }
  }
  for(i=1;i<=n;++i)
  {
    cout<<f[i]<<' ';
    if(!(i%10))
    {
      cout<<endl;
    }
  }
  return 0;
}
inline void* judge(const int &x)
{
  register int i=0;
  for(i=1;i<=cnt;++i)
  {
    if(__builtin_popcount(f[i]^x)<d)
    {
      return (void*)0;
    }
  }
  return (void*)1;
}