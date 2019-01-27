#include<cstdio>
#include<iostream>
#include<bitset>
#include<algorithm>
#define MAXN 110
#define MAXK 31
using namespace std;
int st[2][MAXN],tim=0,n=0,m=0,cnt=0;
string outer[MAXK];
bitset<MAXN>ans[MAXK],a[4],f;
inline void init();
void dfs(const int&);
inline void judge();
inline void convert(const int&);
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(i=2;i--;)
  {
    for(cin>>st[i][j=1];st[i][j]!=-1;)
    {
      cin>>st[i][++j];
    }
  }
  init();
  dfs(0);
  for(i=1;i<=cnt;++i)
  {
    convert(i);
  }
  sort(outer+1,outer+cnt+1);
  cnt=unique(outer+1,outer+cnt+1)-outer-1;
  for(i=1;i<=cnt;++i)
  {
    cout<<outer[i]<<endl;
  }
  if(!cnt)
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
inline void convert(const int &x)
{
  register int i=0;
  outer[x].clear();
  for(i=1;i<=n;++i)
  {
    outer[x].push_back(ans[x][i]^48);
  }
  return;
}
inline void judge()
{
  if(tim>m)
  {
    return;
  }
  register int i=0,j=0;
  //cout<<f.to_string()<<endl;
  for(i=2;i--;)
  {
    for(j=1;st[i][j]!=-1;++j)
    {
      if(f[st[i][j]]!=i)
      {
        return;
      }
    }
  }
  ans[++cnt]=f;
  //convert(cnt);
  //cout<<outer[cnt]<<endl;
  return;
}
void dfs(const int &x)
{
  if(x==4)
  {
    judge();
    return;
  }
  dfs(x+1);
  f^=a[x];
  ++tim;
  dfs(x+1);
  f^=a[x];
  --tim;
  return;
}
inline void init()
{
  register int i=0;
  a[0]=~a[0];f=a[0];
  for(i=1;i<=n;++i)
  {
    if(i&1)
    {
      a[1][i]=1;
    }
    else
    {
      a[2][i]=1;
    }
  }
  for(i=1;i<=n;i+=3)
  {
    a[3][i]=1;
  }
  return;
}
