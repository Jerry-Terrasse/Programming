#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
#define MAXN 10010
#define MAXK 1010
using namespace std;
int a[MAXN],n=0,k=0;
priority_queue<int,vector<int>,greater<int> >q;
inline void work1();
inline void read(int&);
inline void work2();
signed main()
{
  register int i=0,j=0;
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
  register int i=0,u=0,ans=0;
  for(i=1;i<=k;++i)
  {
  	ans+=a[i];
  	q.push(a[i]);
  }
  for(;i<=n;++i)
  {
	ans+=a[i]+(u=q.top());
	q.pop();
  	q.push(u+=a[i]);
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
