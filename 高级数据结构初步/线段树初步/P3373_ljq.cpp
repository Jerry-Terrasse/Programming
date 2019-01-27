#include <iostream>
#include <cstdio>
#define MAX 400000+5
#define mid ((L+R)>>1)
#define Lidx (idx<<1)
#define Ridx ((idx<<1)|1)
using namespace std;

#define int long long

struct Node
{
    int leng,add,mul,val;
};

int N,M,P,x,y,k,dat[MAX];
Node T[MAX<<2];

void build(int L,int R,int idx)
{
    T[idx].leng=R-L+1;
    T[idx].mul=1;
    if (L!=R)
    {
        build(L,mid,Lidx);
        build(mid+1,R,Ridx);
        T[idx].val=(T[Lidx].val+T[Ridx].val)%P;
    }
    else T[idx].val=dat[L]%P;
}

void push(int idx)
{
    T[Lidx].val=(T[Lidx].val*T[idx].mul+T[idx].add*T[Lidx].leng)%P;
    T[Ridx].val=(T[Ridx].val*T[idx].mul+T[idx].add*T[Ridx].leng)%P;
    T[Lidx].mul*=T[idx].mul;
    T[Lidx].mul%=P;
    T[Ridx].mul*=T[idx].mul;
    T[Ridx].mul%=P;
    T[Lidx].add=(T[Lidx].add*T[idx].mul+T[idx].add)%P;
    T[Ridx].add=(T[Ridx].add*T[idx].mul+T[idx].add)%P;
    T[idx].add=0; T[idx].mul=1;
}

void add(int L,int R,int idx)
{
    push(idx);
    if (y<L || R<x)
        return;
    if (x<=L && R<=y)
    {
        T[idx].val=(T[idx].val+k*(R-L+1))%P;
        T[idx].add=(k+T[idx].add)%P;
    }
    else
    {
        add(L,mid,Lidx);
        add(mid+1,R,Ridx);
        T[idx].val=(T[Lidx].val+T[Ridx].val)%P;
    }
}

void mul(int L,int R,int idx)
{
    push(idx);
    if (y<L || R<x)
        return;
    if (x<=L && R<=y)
    {
        T[idx].val*=k; T[idx].val%=P;
        T[idx].mul*=k; T[idx].mul%=P;
        T[idx].add*=k; T[idx].add%=P;
    }
    else
    {
        push(idx);
        mul(L,mid,Lidx);
        mul(mid+1,R,Ridx);
        T[idx].val=(T[Lidx].val+T[Ridx].val)%P;
    }
}

int sum(int L,int R,int idx)
{
    if (y<L || R<x)
        return 0;
    if (x<=L && R<=y)
        return T[idx].val;
    int ans=0;
    push(idx);
    return (sum(L,mid,Lidx)+sum(mid+1,R,Ridx))%P;
}

#undef int

int main()
{

#define int long long

    scanf("%d%d%d",&N,&M,&P);
    for (int i=1; i<=N; i++)
        scanf("%d",dat+i);
    build(1,N,1);
    for (int i=1,ord; i<=M; i++)
    {
        scanf("%d%d%d",&ord,&x,&y);
        switch (ord)
        {
            case 1:
                scanf("%d",&k);
                mul(1,N,1);
                break;
            case 2:
                scanf("%d",&k);
                add(1,N,1);
                break;
            case 3:
                printf("%d\n",sum(1,N,1));
                break;
        }
    }
    return 0;
}
