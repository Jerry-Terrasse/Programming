#include<cstdio>
#include<algorithm>
#define int long long
#define MAXN 10010
#define MAXK 1010
using namespace std;
int f[MAXK],a[MAXN],n=0,k=0;
inline void work1();
inline void read(int&);
inline void work2();
signed main()
{
  int i=0,j=0;
  read(n);read(k);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  sort(a+1,a+n+1);
  work1();
  work2();
  return 0;
}
inline void work2()
{
  int cnt=0,i=0,j=0,ans=0;
  for(cnt=1;cnt<=k;++cnt)
  {
  	ans+=f[cnt]=a[cnt];
  }
  for(;cnt<=n;++cnt)
  {
  	ans+=a[cnt]+f[1];
  	f[1]+=a[cnt];
  	sort(f+1,f+k+1);
  }
  printf("%.2f",(float)ans/n);
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
inline void work1()
{
  int ans=0,i=0;
  for(i=1;i<=n;++i)
  {
  	ans+=a[i]*(n+1-i);
  }
  printf("%.2f\n",(float)ans/n);
  return;
}
