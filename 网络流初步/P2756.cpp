//P2756 飞行员配对方案问题
#include<cstdio>
#include<queue>
#include "memory.h"
#define MAXN 1010
#define INF 0x7fffffff
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct edge
{
  int frm,to,nxt,w;
}e[MAXN<<1];
int hd[MAXN],pre[MAXN],f[MAXN],uvs[MAXN],ec=1,n=0,m=0,s=0,t=0,ans=0;
queue<int>q;
inline bool read(int&);
void write(const int&);
inline void addedge(const int&,const int&);
inline void ek();
inline int bfs();
inline void init();
int main()
{
  register int i=0,u=0,v=0;
  read(m);read(n);n+=m;s=n+1;t=s+1;
  for(i=1;i<=m;++i)
  {
    addedge(s,i);
  }
  for(;i<=n;++i)
  {
    addedge(i,t);
  }
  for(;read(u);)
  {
    read(v);
    addedge(u,v);
  }
  ek();
  if(ans)
  {
    write(ans);
    putchar('\n');
    for(i=n+1<<1;i<=ec;i+=2)
    {
      if(!e[i].w)
      {
        write(e[i].frm);
        putchar(' ');
        write(e[i].to);
        putchar('\n');
      }
    }
  }
  else
  {
    puts("No Solution!");
  }
  return 0;
}
inline void ek()
{
  register int i=0,dlt=0;
  for(;dlt=bfs();ans+=dlt)
  {
    for(i=pre[t];i;i=pre[e[i].frm])
    {
      e[i].w-=dlt;
      e[i^1].w+=dlt;
    }
  }
  return;
}
inline void init()
{
  for(;q.size();q.pop());
  memset(uvs,-1,sizeof(uvs));
  q.push(s);f[s]=INF;uvs[s]=0;
  return;
}
inline int bfs()
{
  register int i=0,u=0,v=0;
  init();
  for(;q.size();q.pop())
  {
    u=q.front();
    for(i=hd[u];i;i=e[i].nxt)
    {
      v=e[i].to;
      if(uvs[v]&&e[i].w)
      {
        f[v]=min(f[u],e[i].w);
        pre[v]=i;
        if(v==t)
        {
          return f[v];
        }
        q.push(v);
        uvs[v]=0;
      }
    }
  }
  return 0;
}
inline void addedge(const int &u,const int &v)
{
  e[++ec].frm=u;
  e[ec].to=v;
  e[ec].w=1;
  e[ec].nxt=hd[u];
  hd[u]=ec;
  e[++ec].frm=v;
  e[ec].to=u;
  e[ec].w=0;
  e[ec].nxt=hd[v];
  hd[v]=ec;
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
inline bool read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar())
  {
    if(c=='-')
    {
      return false;
    }
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return true;
}