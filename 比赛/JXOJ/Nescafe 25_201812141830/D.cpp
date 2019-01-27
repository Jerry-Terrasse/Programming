#include<cstdio>
#include<map>
#define MAXN 300030
#define INF 0x7fffffff
#define max(x) (x<0?0:x)
using namespace std;
int g[MAXN],f[MAXN],a[MAXN],b[MAXN],n=0,cnt=0,ans=INF,m=0;
map<int,int>mp;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0;
  read(n);
  for(i=1;i<=n;++i)
  {
    read(a[i]);read(b[i]);
  }
  for(i=1;i<=n;++i)
  {
    if(!mp.count(a[i]))
    {
      mp.insert(make_pair(a[i],++cnt));
    }
    if(!mp.count(b[i]))
    {
      mp.insert(make_pair(b[i],++cnt));
    }
    ++f[mp[a[i]]];
    if(a[i]!=b[i])
    {
      ++g[mp[b[i]]];
    }
  }
  m=n+1>>1;
  for(i=1;i<=cnt;++i)
  {
    if(f[i]+g[i]>=m&&ans>max(m-f[i]))
    {
      ans=max(m-f[i]);
    }
  }
  if(ans==INF)
  {
    printf("Impossible");
  }
  else
  {
    write(ans);
  }
  return 0;
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}