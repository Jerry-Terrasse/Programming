//P4392 [BOI2007]Sound 静音问题
#include<cstdio>
#define MAXN 1000010
#define MAXM 10010
using namespace std;
struct queue
{
  int mem[MAXN],*head,*tail;
  inline queue();
}q,r;
int a[MAXN],n=0,m=0,c=0;
bool flag=false;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0;
  read(n);read(m);read(c);
  if(n<m)
  {
    puts("NONE");
    return 0;
  }
  for(i=0;i<n;++i)
  {
    read(a[i]);
  }
  for(i=0;i<m;++i)
  {
    for(;q.tail-q.head&&a[*(q.tail-1)]>=a[i];--q.tail);
    *q.tail=i;++q.tail;
    for(;r.tail-r.head&&a[*(r.tail-1)]<=a[i];--r.tail);
    *r.tail=i;++r.tail;
  }
  if(a[*r.head]-a[*q.head]<=c)
  {
    flag=true;
    puts("1");
  }
  for(;i<n;++i)
  {
    for(;q.tail-q.head&&a[*(q.tail-1)]>=a[i];--q.tail);
    *q.tail=i;++q.tail;
    if(*q.head+m==i)
    {
      ++q.head;
    }
    for(;r.tail-r.head&&a[*(r.tail-1)]<=a[i];--r.tail);
    *r.tail=i;++r.tail;
    if(*r.head+m==i)
    {
      ++r.head;
    }
    if(a[*r.head]-a[*q.head]<=c)
    {
      flag=true;
      write(i+2-m);
      putchar('\n');
    }
  }
  if(!flag)
  {
    puts("NONE");
  }
  return 0;
}
inline queue::queue()
{
  head=tail=mem;
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