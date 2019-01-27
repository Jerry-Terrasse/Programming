//P3372 【模板】线段树 1
//Fenwick Tree
#include<iostream>
#define int long long
//#define ld int
#define MAXN 100010
#define lbt(x) ((x)&-(x))
using namespace std;
int n=0,m=0;
int a[MAXN],f[MAXN],g[MAXN];
inline void add(int*,int,const int&);
inline int sum(int*,int);
inline int sum(const int&,const int&);
inline int sum(const int&);
inline void add(const int&,const int&,const int&);
inline void add(const int&);
signed main()
{
  register int i=0,u=0,v=0;
  register int x=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  for(i=n;i;--i)
  {
    a[i]-=a[i-1];
    add(f,i,a[i]);
    add(g,i,a[i]*i);
  }
  for(;m--;)
  {
    cin>>i>>u>>v;
    if(i==1)
    {
      cin>>x;
      add(u,v,x);
    }
    else
    {
      cout<<sum(u,v)<<endl;
    }
  }
  return 0;
}
inline void add(const int &p,const int &dlt)
{
  add(f,p,dlt);
  add(g,p,p*dlt);
  return;
}
inline void add(const int &u,const int &v,const int &dlt)
{
  add(u,dlt);
  add(v+1,-dlt);
  return;
}
inline int sum(const int &p)
{
  return sum(f,p)*(p+1)-sum(g,p);
}
inline int sum(const int &u,const int &v)
{
  return sum(v)-sum(u-1);
}
inline int sum(int *f,int p)
{
  register int ret=0;
  for(;p;p-=lbt(p))
  {
    ret+=f[p];
  }
  return ret;
}
inline void add(int *f,int p,const int &dlt)
{
  for(;p<=n;p+=lbt(p))
  {
    f[p]+=dlt;
  }
  return;
}