#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 100010
using namespace std;
struct card
{
  int a,b,c,id;
  inline void input(const int&);
  inline bool operator==(const card&);
}a[MAXN];
int d[MAXN],st[MAXN],f[MAXN],col[MAXN],l[MAXN],r[MAXN],h=0,t=0,n=0,m=0,maxf=0;
char c='\0';
map<int,int>mp;
inline bool cmp1(const card&,const card&);
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  freopen("card.in","r",stdin);freopen("card.out","w",stdout);
  read(n);
  for(i=1;i<=n;++i)
  {
  	a[i].input(i);
  }
  sort(col+1,col+n+1);
  m=unique(col+1,col+n+1)-col-1;
  for(i=1;i<=m;++i)
  {
  	mp.insert(make_pair(col[i],i));
  }
  for(i=1;i<=n;++i)
  {
  	a[i].c=mp[a[i].a];
  }
  sort(a+1,a+n+1,cmp1);
  for(i=1,r[0]=1;i<=m;++i)
  {
  	l[i]=r[i-1];
  	for(r[i]=l[i]+1;a[r[i]].c==a[l[i]].c;++r[i]);
  }
  for(i=1;i<=m;++i)
  {
  	for(j=l[i];j<r[i];++j)
  	{
  	  if(a[j]==a[j-1])
  	  {
  	    ++d[i];
	  }
	}
  }
  for(i=1;i<=m;++i)
  {
  	h=t=0;
	for(j=l[i];j<r[i];++j)
  	{
  	  st[t]=a[j].b;
  	  for(;st[h]<st[t]-n+1;++h);
  	  ++t;
  	  f[j]=t-h-d[i];
	}
  }
  for(i=1;i<=n;++i)
  {
  	maxf=max(maxf,f[i]);
  }
  write(n-maxf);
  return 0;
}
inline bool card::operator==(const card &x)
{
  return a==x.a&&b==x.b;
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
inline bool cmp1(const card &a,const card &b)
{
  return a.c<b.c||(a.c==b.c&&a.b<b.b);
}
inline void card::input(const int &x)
{
  read(a);read(b);
  id=x;
  col[x]=a;
  return;
}
