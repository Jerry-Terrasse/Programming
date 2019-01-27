#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue> 
#define MAXN 100005
#define LL long long
#define INF 2147483640
#define MOD 100000007
#define free(s) freopen("s.txt","r",stdin);
#define lowbit(x) ((x&(-x))) 
using namespace std;
const int L=1e6+5;
struct node{
    LL int x,c;
};
bool cmp(const node &a,const node &b)
{
    return a.c>b.c;
}
node p[L];
LL int l,n,rf,rb,ans,pot;
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
    scanf("%lld%lld%lld%lld",&l,&n,&rf,&rb);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].c);
    sort(p+1,p+n+1,cmp);
    ans=p[1].x*p[1].c*(rf-rb);
    pot=1;
    for(int i=2;i<=n;i++)
        if(p[i].x>p[pot].x)
        {
            ans=ans+(p[i].x-p[pot].x)*(rf-rb)*p[i].c;
            pot=i;
        }
    printf("%lld",ans);
    return 0;
}
