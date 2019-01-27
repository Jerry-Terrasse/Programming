//P3806 【模板】点分治1
#include<cstdio>
#define MAXN 10010
using namespace std;
struct edge
{
  int to,nxt,w;
}e[MAXN<<1];
int n=0;
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,u=0,v=0,w=0;
  read(n);
  for(i=1;i<n;++i)
  {
    read(u);read(v);read(w);
    addedge(u,v,w);
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