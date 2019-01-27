//P1714 切蛋糕
#include<cstdio>
#include<queue>
#define MAXN 500050
using namespace std;
int a[MAXN],n=0,m=0,ans=0x80000000;
deque<int>q;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0;
  read(n);read(m);
  for(i=1;i<=n;++i)
  {
    read(a[i]);
    a[i]+=a[i-1];
  }
  q.push_back(1);
  for(i=2;i<=n;++i)
  {
    if(ans<a[i]-a[q.front()])
    {
      ans=a[i]-a[q.front()];
    }
    for(;q.size()&&a[i]<=a[q.back()];q.pop_back());
    q.push_back(i);
    if(i==q.front()+m)
    {
      q.pop_front();
    }
  }
  write(ans);
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
  register bool f=false;
  for(x=0;c<'0'|c>'9';c=getchar())
  {
    if(c=='-')
    {
      f=true;
    }
  }
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  if(f)
  {
    x=~x+1;
  }
  return;
}