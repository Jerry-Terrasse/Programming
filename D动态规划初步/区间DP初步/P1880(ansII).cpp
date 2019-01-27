#include<iostream>
#include<cstdio>
using namespace std;
int a[2005],sum[2005];
int fmi[2005][2005],fma[2005][2005],
    smi[2005][2005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        sum[i]=sum[i-1]+a[i];
        smi[i][i]=i;
        }
    for(int i=1+n;i<=(n<<1);i++){
        sum[i]=sum[i-1]+a[i];
        smi[i][i]=i;
        }
    for(int i=(n<<1)-1;i;i--)
        for(int j=i+1;j<=(n<<1);j++){
            int jc=0,tmp=0x3f3f3f3f;
            fma[i][j]=max(fma[i][j-1],fma[i+1][j])+sum[j]-sum[i-1];
            /*注意这句，
              求最大值不能用四边形不等式，
              因为最大值不满足单调性，
              但最大值有一个性质，
              即总是在两个端点的最大者中取到。
            */
            for(int k=smi[i][j-1];k<=smi[i+1][j];k++){
                int tt=fmi[i][k]+fmi[k+1][j]+(sum[j]-sum[i-1]);
                if(tt<tmp){
                    tmp=tt;
                    jc=k;
                    }
                }
            smi[i][j]=jc;
            fmi[i][j]=tmp;
            }
    int ama=0,ami=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ama=max(ama,fma[i][i+n-1]);
        ami=min(ami,fmi[i][i+n-1]);
        }
    printf("%d\n%d",ami,ama);

    return 0;
    }
