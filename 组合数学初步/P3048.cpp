#include<iostream>
#define int long long
#define MAXK 17
#define register signed
using namespace std;
int a[MAXK],n=0,m=0,k=0;
inline int C(const int&,const int&);
void dfs(const int&,const int&);
signed main()
{
  register int i=0,j=0;
  cin>>n>>k;
  for(i=0;(m=C(i+k-1,k-1))<n;++i,n-=m);
  dfs(1,m=i);
  return 0;
}
void dfs(const int &x,const int &p)
{
  if(x==k)
  {
    a[k]=p;
    --n;
    if(!n)
    {
      for(register int i=1;i<=k;++i)
      {
        cout<<'1';
        for(;a[i]--;)
        {
          cout<<'0';
        }
      }
      cout<<endl;
      exit(0);
    }
    return;
  }
  for(a[x]=p;a[x]>=0;--a[x])
  {
    dfs(x+1,p-a[x]);
  }
  return;
}
inline int C(const int &n,const int &m)
{
  register int i=0,ans=1;
  for(i=n-m+1;i<=n;++i)
  {
    ans*=i;
  }
  for(i=m;i;--i)
  {
    ans/=i;
  }
  return ans;
}