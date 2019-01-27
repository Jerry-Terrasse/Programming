#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,m,a,b,c,zs[1000005],sum[1000005],cnt=1,ans;
bool ss[1000005];

inline void getprime(LL n)
{
    memset(ss,1,sizeof(ss));
    ss[0]=ss[1]=0;
    for (LL i=2;i*i<=n;i++)
    {
        if (ss[i]) zs[cnt++]=i;
        for (LL j=1;j<cnt && zs[j]*i*zs[j]*i<=n;j++) ss[zs[j]*i]=0;
    }
    cnt--;
}

inline void pre(LL n)
{
    for (LL i=1;i<=cnt;i++)
    {
        while (n%zs[i]==0)
        {
            n/=zs[i];
            sum[i]++;
        }
    }
}

inline bool work(int x)
{
    if (x==1) return 1;
    for (int i=1;i<=cnt;i++)
    {
        int now=0;
        while (x%zs[i]==0) 
        {
            x/=zs[i];
            now++;
        }
        //cout<<zs[i]<<" "<<now<<endl;
        if (now!=sum[i] && now!=0) return 0;
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    getprime(n);
    pre(n);
    //for (int i=1;i<=cnt;i++) cout<<zs[i]<<" "<<sum[i]<<endl;
    int mid=sqrt(n);
    for (int i=mid;i;i--)
    {
        if (n%i==0)
        {
            //cout<<i<<endl;
            if (work(i))
            {
                ans=i;
                break;
            }
        }
    }
    //cout<<ans<<endl;
    printf("%lld",ans+n/ans);
    //system("pause");
    return 0;
}
