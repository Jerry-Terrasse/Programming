#include<cstdio>
#include<algorithm>
#define MAXN 1000010
#define lbt(x) ((x)&-(x))
using namespace std;
struct que
{
  int l,r,ans,id;
}q[MAXN];
int a[MAXN],c[MAXN],use[MAXN],ans[MAXN],n=0,m=0;
char ch='\0';
inline bool cmp1(const que&,const que&);
inline void add(int,const int&);
inline int sum(int);
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0;
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(a[i]);
  }
  read(m);
  for(i=1;i<=m;++i)
  {
  	read(q[i].l);read(q[i].r);
  	q[i].id=i;
  }
  sort(q+1,q+m+1,cmp1);
  for(i=1,j=1;i<=m;++i)
  {
  	for(;j<=q[i].r;++j)
  	{
  	  if(use[a[j]])
  	  {
  	    add(use[a[j]],-1);
	  }
	  use[a[j]]=j;
	  add(j,1);
	}
	ans[q[i].id]=sum(q[i].r)-sum(q[i].l-1);
  }
  for(i=1;i<=m;++i)
  {
  	write(ans[i]);
  	putchar('\n');
  }
  return 0;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
inline void read(int &x)
{
  for(x=0;ch<'0'||ch>'9';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())
  {
  	x=(x<<3)+(x<<1)+(ch^48);
  }
  return;
}
inline int sum(int x)
{
  int ans=0;
  for(;x;x-=lbt(x))
  {
  	ans+=c[x];
  }
  return ans;
}
inline void add(int x,const int &k)
{
  for(;x<=n;x+=lbt(x))
  {
  	c[x]+=k;
  }
  return;
}
inline bool cmp1(const que &a,const que &b)
{
  return a.r<b.r;
}
