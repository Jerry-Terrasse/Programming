#include<cstdio>
#include<algorithm>
#define MAXM 200020
#define MAXN 5050
using namespace std;
struct edge
{
  int u,v,w;
  inline void input();
}a[MAXM],*p;
int us[MAXN],n=0,m=0,ans=0,cnt=1;
char c='\0';
inline void read(int&);
void write(const int&);
int find(const int&);
inline char cmp(const edge&,const edge&);
int main()
{
  register int i=0;
  read(n);read(m);
  for(p=a+1;p<=a+m;++p)
  {
  	p->input();
  }
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  sort(a+1,a+m+1,cmp);
  for(p=a+1;cnt<n;++p)
  {
  	if(find(p->u)!=find(p->v))
  	{
  	  ++cnt;
	  ans+=p->w;
	  us[us[p->u]]=us[p->v];
	}
  }
  write(ans);
  putchar('\n');
  return 0;
}
inline void edge::input()
{
  read(u);read(v);read(w);
  return;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
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
inline char cmp(const edge &x,const edge &y)
{
  return x.w<y.w;
}
inline void read(int &x)
{
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
