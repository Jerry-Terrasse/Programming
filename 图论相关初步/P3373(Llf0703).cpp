#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct Tree{
    LL left,right,sum,deltaj,deltac;
} tree[500005];
LL f[100005];
LL n,m,p,a,b,c,t,g,ans;
void build(LL x,LL l,LL r)
{
    tree[x].left=l;
    tree[x].right=r;
    tree[x].deltac=1;
    for (int i=l;i<r;i++) tree[x].sum+=f[i];
    if (r-l>1)
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2,r);
    }
}
void update(LL x)
{
    tree[x*2].sum=(tree[x*2].sum*tree[x].deltac+tree[x].deltaj*(tree[x*2].right-tree[x*2].left))%p;
    tree[x*2+1].sum=(tree[x*2+1].sum*tree[x].deltac+tree[x].deltaj*(tree[x*2+1].right-tree[x*2+1].left))%p;
    tree[x*2].deltac=(tree[x].deltac*tree[x*2].deltac)%p;
    tree[x*2+1].deltac=(tree[x].deltac*tree[x*2+1].deltac)%p;
    tree[x*2].deltaj=(tree[x*2].deltaj*tree[x].deltac+tree[x].deltaj)%p;
    tree[x*2+1].deltaj=(tree[x*2+1].deltaj*tree[x].deltac+tree[x].deltaj)%p;
    tree[x].deltac=1;
    tree[x].deltaj=0;
}
void changej(LL x,LL l,LL r,LL delta)
{
    if (l<=tree[x].left && r>=tree[x].right) 
    {
        tree[x].sum=(tree[x].sum+delta*(tree[x].right-tree[x].left))%p;
        tree[x].deltaj=(delta+tree[x].deltaj)%p;
    }
    else
    {
        if (tree[x].deltaj!=0 || tree[x].deltac!=1) update(x);
        if (l<(tree[x].left+tree[x].right)/2) changej(x*2,l,r,delta);
        if (r>(tree[x].left+tree[x].right)/2) changej(x*2+1,l,r,delta);
        tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum)%p;
    }
}
void changec(LL x,LL l,LL r,LL delta)
{
    if (l<=tree[x].left && r>=tree[x].right)
    {
        tree[x].sum=(tree[x].sum*delta)%p;
        tree[x].deltac=(delta*tree[x].deltac)%p;
        tree[x].deltaj=(delta*tree[x].deltaj)%p;
    }
    else
    {
        if (tree[x].deltac!=1 || tree[x].deltaj!=0) update(x);
        if (l<(tree[x].left+tree[x].right)/2) changec(x*2,l,r,delta);
        if (r>(tree[x].left+tree[x].right)/2) changec(x*2+1,l,r,delta);
        tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum)%p;
    }
}
LL query(LL x,LL l,LL r)
{
    if (l<=tree[x].left && r>=tree[x].right) return tree[x].sum%p;
    else
    {
        if (tree[x].deltac!=1 || tree[x].deltaj!=0) update(x);
        LL ans=0;
        if (l<(tree[x].left+tree[x].right)/2) ans+=query(x*2,l,r);
        if (r>(tree[x].left+tree[x].right)/2) ans+=query(x*2+1,l,r);
        return ans%p;
    }
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for (int i=1;i<=n;i++) scanf("%lld",&f[i]);
    build(1,1,n+1);
    for (int i=1;i<=m;i++)
    {
        scanf("%lld",&a);
        if (a==1)
        {
            scanf("%lld%lld%lld",&t,&g,&c);
            changec(1,t,g+1,c);
        }
        if (a==2)
        {
            scanf("%lld%lld%lld",&t,&g,&c);
            changej(1,t,g+1,c);
        }
        if (a==3)
        {
            scanf("%lld%lld",&t,&g);
            ans=query(1,t,g+1)%p;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
