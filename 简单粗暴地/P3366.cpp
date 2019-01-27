#include<cstdio>
#include<algorithm>
#define MAXM 200020
#define MAXN 5050
using namespace std;
struct edge
{
  int u,v,w;
  inline void input();
}a[MAXM];
int us[MAXN],b[MAXM],n=0,m=0,ans=0,cnt=1;
char c='\0';
inline void read(int&);
void write(const int&);
int find(const int&);
inline char cmp(const int&,const int&);
int main()
{
  register int i=0;
  read(n);read(m);
  for(i=1;i<=m;++i)
  {
  	a[i].input();
  	b[i]=i;
  }
  sort(b+1,b+m+1,cmp);
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  for(i=1;cnt<n;++i)
  {
  	if(find(a[b[i]].u)!=find(a[b[i]].v))
  	{
  	  ++cnt;
	  ans+=a[b[i]].w;
	  us[us[a[b[i]].u]]=us[a[b[i]].v];
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
inline char cmp(const int &x,const int &y)
{
  return a[x].w<a[y].w;
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
