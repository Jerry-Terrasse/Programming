#include<cstdio>
#include "memory.h"
#define MAXN 100010
using namespace std;
struct edge
{
    int to,nxt,w;
}e[MAXN<<1];
int hd[MAXN],f[MAXN],ec=0,n=0;
void dfs(const int&,const int&);
inline void read(int&);
void write(const int&);
inline void addedge(const int&,const int&,const int&);
int main()
{
    register int i=0,u=0,v=0,w=0;
    memset(f,-1,sizeof(f));
    read(n);
    for(i=1;i<n;++i)
    {
        read(u);read(v);read(w);
        addedge(u,v,w);
    }
    dfs(1,0);
    read(n);
    for(;n--;)
    {
        read(u);read(v);
        write(f[u]^f[v]);
        putchar('\n');
    }
    return 0;
}
void dfs(const int &x,const int &s)
{
    register int i=0;
    f[x]=s;
    for(i=hd[x];i;i=e[i].nxt)
    {
        if(f[e[i].to]==-1)
        {
            dfs(e[i].to,s^e[i].w);
        }
    }
    return;
}
inline void addedge(const int &u,const int &v,const int &w)
{
    e[++ec].to=v;
    e[ec].w=w;
    e[ec].nxt=hd[u];
    hd[u]=ec;
    e[++ec].to=u;
    e[ec].w=w;
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
