#include<cstdio>
#include<cstdlib>
#define MAXN 200020
#define rr(x) (rand()%(x))
using namespace std;
struct edge
{
  int to,w,nxt;
}e[MAXN<<1];
int f[MAXN][22],bo[MAXN],w[MAXN],fa[MAXN],head[MAXN],n=0,q=0,r=0,cnt=0;
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&,const int&);
void build(const int&,const int&);
//void dfs(const int&,const int&);
int main()
{
  register int i=0,j=0,u=0,v=0,w=0;
  //srand((int)new char);
  read(n);read(q);//read(r);
//  for(i=1;i<n;++i)
  {
  //  read(u);read(v);read(w);
    //addedge(u,v,w);
  }
  //build(r,0);
  //for(i=1;i<=n;++i)
  {
    //f[i][0]=fa[i];
  }
 // for(i=2;i<22;++i)
  {
   // f[j][i]=f[f[j][i-1]][i-1];
  }
  //dfs(r,0);
  for(i=1;i<=q;write(0),putchar('\n'),++i);
  return 0;
}
void build(const int &x,const int &fafa)
{
  register int i=0;
  fa[x]=fafa;
  for(i=head[x];i;i=e[i].nxt)
  {
    w[e[i].to]=e[i].w;
    build(e[i].to,x);
  }
  return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
  e[++cnt].to=v;
  e[cnt].w=w;
  e[cnt].nxt=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].w=w;
  e[cnt].nxt=head[v];
  head[v]=cnt;
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
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
