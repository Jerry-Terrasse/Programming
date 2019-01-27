#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int maxn=1e5+10;
struct edge{
    int next,to;
}e[maxn*2];
struct node{
    int l,r,ls,rs,sum,lazy;
}a[maxn*2];
int n,m,r,rt,mod,v[maxn],head[maxn],cnt,f[maxn],d[maxn],son[maxn],size[maxn],top[maxn],id[maxn],rk[maxn];
void add(int x,int y)
{
    e[++cnt].next=head[x];
    e[cnt].to=y;
    head[x]=cnt;
}
void dfs1(int x)
{
    size[x]=1,d[x]=d[f[x]]+1;
    for(int v,i=head[x];i;i=e[i].next)
        if((v=e[i].to)!=f[x])
        {
            f[v]=x,dfs1(v),size[x]+=size[v];
            if(size[son[x]]<size[v])
                son[x]=v;
        }
}
void dfs2(int x,int tp)
{
    top[x]=tp,id[x]=++cnt,rk[cnt]=x;
    if(son[x])
        dfs2(son[x],tp);
    for(int v,i=head[x];i;i=e[i].next)
        if((v=e[i].to)!=f[x]&&v!=son[x])
            dfs2(v,v);
}
inline void pushup(int x)
{
    a[x].sum=(a[a[x].ls].sum+a[a[x].rs].sum)%mod;
}
void build(int l,int r,int x)
{
    if(l==r)
    {
        a[x].sum=v[rk[l]],a[x].l=a[x].r=l;
        return;
    }
    int mid=l+r>>1;
    a[x].ls=cnt++,a[x].rs=cnt++;
    build(l,mid,a[x].ls),build(mid+1,r,a[x].rs);
    a[x].l=a[a[x].ls].l,a[x].r=a[a[x].rs].r;
    pushup(x);
}
inline int len(int x)
{
    return a[x].r-a[x].l+1;
}
inline void pushdown(int x)
{
    if(a[x].lazy)
    {
        int ls=a[x].ls,rs=a[x].rs,lz=a[x].lazy;
        (a[ls].lazy+=lz)%=mod,(a[rs].lazy+=lz)%=mod;
        (a[ls].sum+=lz*len(ls))%=mod,(a[rs].sum+=lz*len(rs))%=mod;
        a[x].lazy=0;
    }
}
void update(int l,int r,int c,int x)
{
    if(a[x].l>=l&&a[x].r<=r)
    {
        (a[x].lazy+=c)%=mod,(a[x].sum+=len(x)*c)%=mod;
        return;
    }
    pushdown(x);
    int mid=a[x].l+a[x].r>>1;
    if(mid>=l)
        update(l,r,c,a[x].ls);
    if(mid<r)
        update(l,r,c,a[x].rs);
    pushup(x);
}
int query(int l,int r,int x)
{
    if(a[x].l>=l&&a[x].r<=r)
        return a[x].sum;
    pushdown(x);
    int mid=a[x].l+a[x].r>>1,tot=0;
    if(mid>=l)
        tot+=query(l,r,a[x].ls);
    if(mid<r)
        tot+=query(l,r,a[x].rs);
    return tot%mod;
}
inline int sum(int x,int y)
{
    int ret=0;
    while(top[x]!=top[y])
    {
        if(d[top[x]]<d[top[y]])
            swap(x,y);
        (ret+=query(id[top[x]],id[x],rt))%=mod;
        x=f[top[x]];
    }
    if(id[x]>id[y])
        swap(x,y);
    return (ret+query(id[x],id[y],rt))%mod;
}
inline void updates(int x,int y,int c)
{
    while(top[x]!=top[y])
    {
        if(d[top[x]]<d[top[y]])
            swap(x,y);
        update(id[top[x]],id[x],c,rt);
        x=f[top[x]];
    }
    if(id[x]>id[y])
        swap(x,y);
    update(id[x],id[y],c,rt);
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&r,&mod);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    for(int x,y,i=1;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        add(x,y),add(y,x);
    }
    cnt=0,dfs1(r),dfs2(r,r);
    cnt=0,build(1,n,rt=cnt++);
    for(int op,x,y,k,i=1;i<=m;i++)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            updates(x,y,k);
        }
        else if(op==2)
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",sum(x,y));
        }
        else if(op==3)
        {
            scanf("%lld%lld",&x,&y);
            update(id[x],id[x]+size[x]-1,y,rt);
        }
        else
        {
            scanf("%lld",&x);
            printf("%lld\n",query(id[x],id[x]+size[x]-1,rt));
        }
    }
    return 0;
}
