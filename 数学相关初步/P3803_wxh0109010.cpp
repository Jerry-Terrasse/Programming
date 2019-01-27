#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);

struct cp
{
    double a,b;
    cp operator +(const cp &o)const
    {
        return (cp)
        {
            a+o.a,b+o.b
        };
    }
    cp operator -(const cp &o)const
    {
        return (cp)
        {
            a-o.a,b-o.b
        };
    }
    cp operator *(const cp &o)const
    {
        return (cp)
        {
            a*o.a-b*o.b,b*o.a+a*o.b
        };
    }
    cp operator *(const double &o)const
    {
        return (cp)
        {
            a*o,b*o
        };
    }
    cp operator !()const
    {
        return (cp)
        {
            a,-b
        };
    }
} x[1<<21|1],y[1<<21|1],z[1<<21|1],w[1<<21|1];
void fft(cp x[],int k,int v)
{
    for(int i=0,j=0; i<k; i++)
    {
        if(i>j)swap(x[i],x[j]);
        for(int l=k>>1; (j^=l)<l; l>>=1);
    }
    w[0]=(cp)
    {
        1,0
    };
    for(int i=2; i<=k; i<<=1)
    {
        cp g=(cp)
        {
            cos(2*pi/i),(v?-1:1)*sin(2*pi/i)
        };
        for(int j=(i>>1); j>=0; j-=2)w[j]=w[j>>1];
        for(int j=1; j<i>>1; j+=2)w[j]=w[j-1]*g;
        for(int j=0; j<k; j+=i)
        {
            cp *a=x+j,*b=a+(i>>1);
            for(int l=0; l<i>>1; l++)
            {
                cp o=b[l]*w[l];
                b[l]=a[l]-o;
                a[l]=a[l]+o;
            }
        }
    }
    if(v)for(int i=0; i<k; i++)x[i]=(cp)
        {
            x[i].a/k,x[i].b/k
        };
}
struct buf
{
    char a[33554431],*s;
    char b[33554431],*t;
    buf():s(a),t(b)
    {
        a[fread(a,1,sizeof a,stdin)]=0;
    }
    ~buf()
    {
        fwrite(b,1,t-b,stdout);
    }
    operator int()
    {
        int x=0;
        while(*s<48)++s;
        while(*s>32)
            x=x*10+*s++-48;
        return x;
    }
    void out(int x)
    {
        static char c[12];
        char*i=c;
        if(!x)*t++=48;
        else
        {
            while(x)
            {
                int y=x/10;
                *i++=x-y*10+48,x=y;
            }
            while(i!=c)*t++=*--i;
        }
        *t++=' ';
    }
} it;
int n,m,l,K;
int main()
{
    n=it,m=it;
    for(int i=0; i<=n; i++)(i&1?x[i>>1].b:x[i>>1].a)=it;
    for(int i=0; i<=m; i++)(i&1?y[i>>1].b:y[i>>1].a)=it;
    for(K=1; K<=n+m>>1; K<<=1);
    fft(x,K,0);
    fft(y,K,0);
    for(int i=0; i<K; i++)
    {
        int j=K-1&K-i;
        z[i]=(x[i]*y[i]*4-(x[i]-!x[j])*(y[i]-!y[j])*(((i&K>>1)?(cp)
        {
            1,0
}-w[i^K>>1]:w[i]+(cp)
        {
            1,0
        })))*0.25;
    }
    fft(z,K,1);
    for(int i=0; i<=n+m; i++)if(i&1)it.out((int)(z[i>>1].b+0.1));
        else it.out((int)(z[i>>1].a+0.1));
    return 0;
}
