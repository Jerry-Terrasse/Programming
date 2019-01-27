#include<cstdio>
#define int long long
#define MAXN 55
#define MAXL 2020
#define MAX 100010
#define MAXN 55
#define H 998244353
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int f[MAXN][MAX<<1],l[MAXN],r[MAXN],n=0,k=0,a=0,minf=0,maxf=0;
inline void read(int&);
void write(const int&);
inline int ksm(int,int);
inline int _ksm(const int&,const int&);
signed main()
{
  register int i=0,j=0,s=0,sum=0,pro=1;
  freopen("power.in","r",stdin);freopen("power.out","w",stdout);
  read(n);read(k);read(a);
  for(i=1;i<=n;++i)
  {
    read(l[i]);read(r[i]);
  }
  for(i=1,f[0][MAX]=1;i<=n;++i)
  {
    minf+=l[i];
    maxf+=r[i];
    for(j=minf;j<=maxf;++j)
    {
      for(s=l[i];s<=r[i];++s)
      {
        f[i][j+MAX]+=f[i-1][j-s+MAX];
      }
    }
  }
  for(i=minf;i<=min(a,maxf);++i)
  {
    (sum+=f[n][i+MAX])%=H;
  }
  (sum*=_ksm(a,k))%=H;
  for(;i<=maxf;++i)
  {
    (sum+=_ksm(i,k)*f[n][i+MAX])%=H;
  }
  for(i=1;i<=n;++i)
  {
    (pro*=r[i]-l[i]+1)%=H;
  }
  (sum*=_ksm(pro,H-2))%=H;
  if(sum<0)
  {
    sum+=H;
  }
  //sum=ksm(sum,k);
  write(sum);
  return 0;
}
inline int _ksm(const int &x,const int &y)
{
  if(x<0)
  {
    if(y&1)
    {
      return (H-ksm(-x,y)%H);
    }
    else
    {
      return ksm(-x,y);
    }
  }
  return ksm(x,y);
}
inline int ksm(int x,int y)
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
  register bool bo=false;
  for(x=0;c<'0'||c>'9';c=getchar())
  {
    if(c=='-')
    {
      bo=true;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  if(bo)
  {
    x=~x+1;
  }
  return;
}
