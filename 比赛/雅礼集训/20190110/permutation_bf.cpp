#include<iostream>
#define int long long
#define MAXN 200020
#define H 998244353
using namespace std;
int js[MAXN],f[MAXN],a[MAXN],n=0,A=0,B=0,ans=0;
void dfs(const int&,const int&);
inline void judge();
inline void init(const int&);
inline int C(const int&,const int&);
inline int pow(int,int);
signed main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  ans=0;
  cin>>n>>A>>B;
  if(A==0||B==0||A>n||B>n)
  {
    cout<<0<<endl;
    return 0;
  }
  if(A==1&&B==1)
  {
    cout<<(n==1)<<endl;
    return 0;
  }
  if(A==n)
  {
    cout<<(B==1)<<endl;
    return 0;
  }
  if(B==n)
  {
    cout<<(A==1)<<endl;
    return 0;
  }
  if(A+B==n+1)
  {
    init(n);
    cout<<C(n-1,A-1)<<endl;
    return 0;
  }
  dfs(1,(1<<n)-1);
  cout<<ans<<endl;
  //main();
  return 0;
}
inline int pow(int x,int y)
{
  register int ret=1;
  for(;y;y>>=1)
  {
    if(y&1)
    {
     (ret*=x)%=H;
    }
    (x*=x)%=H;
  }
  return ret;
}
inline int C(const int &n,const int &m)
{
  register int i=0,ret=1;
  ret*=js[n];
  (ret*=pow(js[m],H-2))%=H;
  (ret*=pow(js[n-m],H-2))%=H;
  return ret;
}
inline void init(const int &n)
{
  register int i=0;
  for(i=1,js[0]=1;i<=n;++i)
  {
    (js[i]=js[i-1]*i)%=H;
  }
  return;
}
inline void judge()
{
  register int i=0,x=-1,ret=0;
  for(i=1;i<=n;++i)
  {
    if(f[i]>x)
    {
      x=f[i];
      ++ret;
    }
  }
  if(ret==A)
  {
    ret=0;x=-1;
    for(i=n;i>=1;--i)
    {
      if(f[i]>x)
      {
        x=f[i];
        ++ret;
      }
    }
    if(ret==B)
    {
      ++ans;
    }
  }
  return;
}
void dfs(const int &x,const int &pre)
{
  register int i=0;
  if(x==n+1)
  {
    judge();
    return;
  }
  for(i=0;i<n;++i)
  {
    if(pre>>i&1)
    {
      f[x]=i;
      dfs(x+1,pre^(1<<i));
    }
  }
  return;
}