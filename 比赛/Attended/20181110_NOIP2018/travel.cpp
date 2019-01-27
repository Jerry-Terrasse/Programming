#include<cstdio>
#define MAXN 10010
using namespace std;
int e[MAXN][MAXN],cnt[MAXN],n=0,m=0;
inline void read(int&);
void write(const int&);
int main()
{
    register int i=0,j=0,u=0,v=0;
    read(n);read(m);
    for(i=1;i<=m;++i)
    {
        read(u);read(v);
        e[u][++cnt[u]=v;
        e[v][++cnt[v]]=u;
    }
    for(i=1;i<=n;++i)
    {
        sort(e[i]+1,e[i]+cnt[i]+1);
    }
    if()
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
