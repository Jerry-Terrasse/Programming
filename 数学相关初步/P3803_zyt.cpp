#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAX 1000001
struct complex{
    double a,b;
    complex (double x=0,double y=0){
        a=x;
        b=y;
    }
} F[MAX<<1],G[MAX];
complex operator + (complex x,complex y){
    return complex(x.a+y.a,x.b+y.b);
}
complex operator - (complex x,complex y){
    return complex(x.a-y.a,x.b-y.b);
}
complex operator * (complex x,complex y){
    return complex(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);
}
int n,m,Lim=1;
void FFT(int len,complex *A,int op){
    if(!len)
        return;
    complex A1[len+1],A2[len+1];
    for(int i=0;i<len;i++){
        A1[i]=A[i<<1];
        A2[i]=A[i<<1|1];
    }
    FFT(len>>1,A1,op);
    FFT(len>>1,A2,op);
    complex Wn(cos(M_PI/len),op*sin(M_PI/len)),w(1,0);
    for(int i=0;i<len;w=w*Wn,i++){
        A[i]=A1[i]+w*A2[i];
        A[i+len]=A1[i]-w*A2[i];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        scanf("%lf",&F[i].a);
    for(int i=0;i<=m;i++)
        scanf("%lf",&G[i].a);
    while(Lim<=n+m)
        Lim<<=1;
    FFT(Lim>>1,F,1);
    FFT(Lim>>1,G,1);
    for(int i=0;i<Lim;i++)
        F[i]=F[i]*G[i];
    FFT(Lim>>1,F,-1);
    for(int i=0;i<=n+m;i++)
        printf("%.0f ",F[i].a/Lim);
    return 0;
}
