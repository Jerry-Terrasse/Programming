//4. 小 D 是巨佬，你是他的粉丝。只有成功解决下面 3 个问题，小 D 才会给你他的 QQ 号
//bf
#include<cstdio>
#define MAXN 220
#define P 13331
#define int long long
using namespace std;
int a[MAXN][MAXN],n=0,m=0,ans=0;
bool flag=false;
inline void read(int&);
void write(const int&);
inline void work(int,int,int,int);
signed main()
{
  register int i=0,j=0,k=0,l=0;
  freopen("matrix.in","r",stdin);freopen("matrix.out","w",stdout);
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      read(a[i][j]);
      if(a[i][j]!=(i-1)*m+j)
      {
        flag=true;
      }
    }
  }
  if(!flag)
  {
    for(i=1;i<=n;++i)
    {
      for(j=1;j<=m;++j)
      {
        ans+=(m-j+1)*i*(n-i+1);
      }
    }
    write(ans);
    putchar('\n');
    return 0;
  }
  for(i=1;i<=n;++i)
  {
    for(j=1;j<=m;++j)
    {
      for(k=i;k<=n;++k)
      {
        for(l=j;l<=m;++l)
        {
          work(i,j,k,l);
        }
      }
    }
  }
  write(ans);
  return 0;
}
inline void work(int t,int e,int r,int s)
{
  register int i=0,j=0,k=0,ret=r+1-t,bo=false;
  for(i=t;i<=r;++i)
  {
    for(j=t;j<i;++j)
    {
      for(k=e,bo=true;k<=s;++k)
      {
        if(a[i][k]!=a[j][k])
        {
          bo=false;
          break;
        }
      }
      if(bo)
      {
        --ret;
      }
    }
  }
  ans+=ret;
  return;
}
void write(const int &x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
