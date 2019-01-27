//U54221 Tweetuzki 爱伊图
#include<iostream>
#include<algorithm>
#define MAXM 100010
#define MAXN 17
using namespace std;
struct rel
{
  int id,val;
}ans[MAXM];
int n=0,m=0,cnt=0;
char a[MAXN][MAXM];
inline void work(const int&,const int&);
inline void find(const int&,const int&);
inline bool cmp(const rel&,const rel&);
int main()
{
  register int i=0,j=0;
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      cin>>a[i][j];
      a[i][j]=a[i][j]=='#';
    }
  }
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      if(a[i][j])
      {
        work(i,j);
      }
    }
  }
  sort(ans+1,ans+cnt+1,cmp);
  for(i=1;i<=cnt;++i)
  {
    cout<<ans[i].val;
  }
  return 0;
}
inline bool cmp(const rel &a,const rel &b)
{
  return a.id<b.id;
}
inline void find(const int &x,const int &y)
{
  register int i=0,j=0,ret=0;
  for(i=0;i<5;++i)
  {
    for(j=0;j<3;++j)
    {
      ret<<=1;
      ret+=a[x+i][y+j];
    }
  }
  switch(ret)
  {
    case 29671:
      ans[++cnt].id=y;
      ans[cnt].val=2;
      break;
    case 29647:
      ans[++cnt].id=y;
      ans[cnt].val=3;
      break;
    case 23497:
      ans[++cnt].id=y;
      ans[cnt].val=4;
      break;
    case 31183:
      ans[++cnt].id=y;
      ans[cnt].val=5;
      break;
    case 31215:
      ans[++cnt].id=y;
      ans[cnt].val=6;
      break;
    case 29257:
      ans[++cnt].id=y;
      ans[cnt].val=7;
      break;
    case 31727:
      ans[++cnt].id=y;
      ans[cnt].val=8;
      break;
    case 31695:
      ans[++cnt].id=y;
      ans[cnt].val=9;
      break;
    case 31599:
      ans[++cnt].id=y;
      ans[cnt].val=0;
      break;
    default:
      cout<<"??????????"<<ret<<endl;
  }
  return;
}
inline void work(const int &x,const int &y)
{
  register int i=0,j=0;
  register bool bo=false;
  for(i=1;i<5;++i)
  {
    if(!a[x+i][y])
    {
      bo=true;
      break;
    }
  }
  for(i=0;i<5;++i)
  {
    if(a[x+i][y+1])
    {
      bo=true;
      break;
    }
  }
  if(bo)
  {
    find(x,y);
    for(i=0;i<5;++i)
    {
      for(j=0;j<3;++j)
      {
        a[x+i][y+j]=0;
      }
    }
  }
  else
  {
    ans[++cnt].id=y;
    ans[cnt].val=1;
    for(i=0;i<5;++i)
    {
      a[x+i][y]=0;
    }
  }
  return;
}