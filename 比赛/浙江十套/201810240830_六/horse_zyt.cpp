#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1000010
int n,ans,t[MAX],q[MAX];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++)
        scanf("%d",&q[i]);
    sort(q+1,q+n+1,cmp);
    for(int i=1,j=1,ii=n,jj=n;i<=ii;){
        if(t[i]>q[j]){
            ans+=200;
            i++;
            j++;
        }
        else if(t[i]<q[j]){
            ans-=200;
            j++;
            ii--;
        }
        else{
            if(t[ii]>q[jj]){
                ans+=200;
                ii--;
                jj--;
            }
            else{
                if(t[ii]<q[j])
                    ans-=200;
                ii--;
                j++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
