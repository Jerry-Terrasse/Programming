#include<iostream>
#include<cstdlib>
#define MAXN 1010
#define rr(x) (rand()%(x))
using namespace std;
int us[MAXN];
inline int find(const int &x)
{
    return us[x]==x?x:us[x]=find(us[x]);
}
int main()
{
    int i=0,u=0,v=0,m=0,n=0,H=1000000007,r=1;
    srand((int)new char);
    n=rr(MAXN)+1;m=rr(MAXN)+1;
    cout<<n<<' '<<m<<' '<<r<<' '<<H<<endl;
    for(i=1;i<=n;++i)
    {
        us[i]=i;
    }
    for(i=1;i<=n;++i)
    {
        cout<<rr(MAXN)<<' ';
    }
    cout<<endl;
    for(i=1;i<n;)
    {
        u=rr(n)+1;
        v=rr(n)+1;
        if(find(u)!=find(v))
        {
            ++i;
            cout<<u<<' '<<v<<endl;
            us[us[u]]=us[v];
        }
    }
    for(i=1;i<=m;++i)
    {
        u=rr(4);
        switch(u)
        {
            case 0:
            cout<<4<<' '<<rr(n)+1<<endl;
            case 1:
            cout<<2<<' '<<rr(n)+1<<' '<<rr(n)+1<<endl;
            case 2:
            cout<<3<<' '<<rr(n)+1<<' '<<rr(MAXN)<<endl;
            default:
                cout<<1<<' '<<rr(n)+1<<' '<<rr(n)+1<<' '<<rr(MAXN)<<endl;
        }

    }
    return 0;
}
