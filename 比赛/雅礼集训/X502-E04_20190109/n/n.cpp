#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define ld double
#define MAXN 30030
#define MAXT 1e7
#define MINT 1e-7
#define dt 0.876
#define rr(x) (rand()*rand()%(x))
using namespace std;
int n=0,m=0;
ld f[MAXN],len[MAXN],x[MAXN],y[MAXN],a[MAXN],b[MAXN],beg[MAXN],c=0,ans=MAXT;
inline void read(int&);
void write(const int&);
inline void init();
inline void sa();
inline void calc(ld&,const ld&);
int main()
{
  register int i=0,lim=100;
  init();
  for(;(ld)clock()/CLOCKS_PER_SEC<dt*2;sa());
  //for(i=1;i<=lim;++i,sa());
  printf("%.17lf",ans);
  //printf("\n%d",clock());
  return 0;
}
inline void calc(ld &ret,const ld &it)
{
  register int i=0,j=0;
  register ld t=0;
  ret=0;
  for(i=1;i<=m;++i)
  {
    t=beg[i]+it;
    if(t>=c)
    {
      t-=c;
    }
    j=upper_bound(f+1,f+n+1,t)-f;
    t-=f[j-1];
    t/=len[j];
    a[i]=x[j]+t*(x[j+1]-x[j]);
    b[i]=y[j]+t*(y[j+1]-y[j]);
  }
  a[m+1]=a[1];b[m+1]=b[1];
  for(i=1;i<=m;++i)
  {
    if(ret<(t=sqrt((a[i]-a[i+1])*(a[i]-a[i+1])+(b[i]-b[i+1])*(b[i]-b[i+1]))))
    {
      ret=t;
    }
  }
  return;
}
inline void sa()
{
  register ld preans=0,pret=0,ret=0,t=c/2,T=MAXT;
  for(calc(ret,t);T>MINT;T*=dt)
  {
    pret=t;preans=ret;
    t+=c*rand()/RAND_MAX*T/MAXT*(rr(2)?1:-1);
    if(t>=c)
    {
      t-=c;
    }
    if(t<0)
    {
      t+=c;
    }
    calc(ret,t);
    if(ret<preans)
    {
      if(ret<ans)
      {
        ans=ret;
      }
    }
    else if(exp(-T)>(ld)rand()/RAND_MAX)
    {
      ret=preans;
      t=pret;
    }
  }
  return;
}
inline void init()
{
  register int i=0,u=0,v=0;
  freopen("n.in","r",stdin);freopen("n.out","w",stdout);
  //srand(time(NULL));
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
    read(u);read(v);
    x[i]=u;y[i]=v;
  }
  x[n+1]=x[1];y[n+1]=y[1];
  for(i=1;i<=n;++i)
  {
    len[i]=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
  }
  for(i=1;i<=n;++i)
  {
    f[i]=f[i-1]+len[i];
  }
  c=f[n];
  for(i=1;i<=m;++i)
  {
    beg[i]=c*(m-i)/m;
  }
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