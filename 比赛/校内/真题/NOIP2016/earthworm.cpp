#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
int n=0,m=0,t=0,qq=0,u=0,v=0;
priority_queue<int>q;
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0,k=0;
  freopen("earthworm.in","r",stdin);freopen("earthworm.out","w",stdout);
  read(n);read(m);read(qq);read(u);read(v);read(t);
  for(i=1;i<=n;++i)
  {
  	read(j);
  	q.push(j);
  }
  for(i=1;i<=m;++i)
  {
  	j=q.top();
  	q.pop();
  	j+=(i-1)*qq;
  	if(!(i%t))
  	{
  	  write(j);
  	  putchar(' ');
	}
  	k=(ll)j*u/v;
  	q.push(k-i*qq);
  	j-=k;
  	q.push(j-i*qq);
  }
  putchar('\n');
  for(i=1,qq*=m;q.size();++i,q.pop())
  {
  	if(!(i%t))
  	{
  	  write(q.top()+qq);
  	  putchar(' ');
	}
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
