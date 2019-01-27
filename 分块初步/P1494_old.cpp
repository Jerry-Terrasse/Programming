//P1494 [国家集训队]小Z的袜子
//ugly but ac
#include<iostream>
#include<algorithm>
#include<cmath>
#include "memory.h"
#define ll long long
#define MAXN 50050
using namespace std;
struct query
{
  int id,l,r;
  ll son,mom;
}md[MAXN];//MoDui
int f[MAXN],a[MAXN],n=0,m=0,oldm=0,s=0;
inline bool cmp1(const query&,const query&);
inline bool cmp2(const query&,const query&);
inline bool cmp3(const query&,const query&);
int main()
{
  register int i=0,j=0,l=0,r=0;
  register query *p=NULL;
  register ll ans=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;oldm=m;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  for(i=1;i<=oldm;++i)
  {
    cin>>md[i].l>>md[i].r;
    md[i].id=i;
    if(md[i].l==md[i].r)
    {
      --m;
      md[i].l=n+1;
      md[i].son=0;
      md[i].mom=1;
    }
    else
    {
      md[i].mom=(ll)(md[i].r-md[i].l+1)*(md[i].r-md[i].l)>>1;
    }
  }
  sort(md+1,md+oldm+1,cmp1);
  s=sqrt(m);
  for(i=1;s*i<m;++i)
  {
    sort(md+(i-1)*s+1,md+i*s+1,cmp2);
  }
  sort(md+(i-1)*s+1,md+m+1,cmp2);
  for(i=1;s*i<m;++i)
  {
    p=md+(i-1)*s+1;l=p->l;r=p->r;
    memset(f,0,sizeof(f));ans=0;
    for(j=l;j<=r;++j)
    {
      ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      ++f[a[j]];
      ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
    }
    p->son=ans;
    for(++p;p<=md+s*i;++p)
    {
      for(j=l-1;j>=p->l;--j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        ++f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      for(j=l;j<p->l;++j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        --f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      for(j=r+1;j<=p->r;++j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        ++f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      p->son=ans;
      l=p->l;r=p->r;
    }
  }
  if((i-1)*s<m)
  {
    p=md+(i-1)*s+1;l=p->l;r=p->r;
    memset(f,0,sizeof(f));ans=0;
    for(j=l;j<=r;++j)
    {
      ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      ++f[a[j]];
      ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
    }
    p->son=ans;
    for(++p;p<=md+m;++p)
    {
      for(j=l-1;j>=p->l;--j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        ++f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      for(j=l;j<p->l;++j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        --f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      for(j=r+1;j<=p->r;++j)
      {
        ans-=(ll)f[a[j]]*(f[a[j]]-1)>>1;
        ++f[a[j]];
        ans+=(ll)f[a[j]]*(f[a[j]]-1)>>1;
      }
      p->son=ans;
      l=p->l;r=p->r;
    }
  }
  sort(md+1,md+oldm+1,cmp3);
  for(p=md+1;p<=md+oldm;++p)
  {
    i=__gcd(p->son,p->mom);
    p->son/=i;
    p->mom/=i;
    cout<<p->son<<'/'<<p->mom<<endl;
  }
  return 0;
}
inline bool cmp3(const query &x,const query &y)
{
  return x.id<y.id;
}
inline bool cmp2(const query &x,const query &y)
{
  return x.r<y.r;
}
inline bool cmp1(const query &x,const query &y)
{
  return x.l<y.l;
}