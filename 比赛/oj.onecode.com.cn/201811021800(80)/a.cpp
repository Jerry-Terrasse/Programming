#pragma GCC optmize(2)
#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 300030
using namespace std;
int a[MAXN],n=0,m=0,cnt=0;
map<int,int>mp;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,j=0;
  register map<int,int>::iterator it;
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
  	read(j);
  	if(mp.count(j))
  	{
  	  ++mp[j];
	}
	else
	{
	  mp.insert(make_pair(j,1));
	}
  }
  for(i=1;i<=m;++i)
  {
  	read(j);
  	--mp[j];
  }
  for(it=mp.begin();it!=mp.end();++it)
  {
  	for(i=it->second;i--;)
  	{
  	  a[++cnt]=it->first;
	}
  }
  sort(a+1,a+cnt+1);
  for(i=1;i<=cnt;++i)
  {
  	write(a[i]);
  	putchar(' ');
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
  register int c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
