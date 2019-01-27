#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,q,u,v,t;
long long tmp,t1,t2;
long long add=0;
long long a[100010];
queue <int> Q;
queue <long long > q1;
queue <long long > q2;

int maxnum(){
    int res=-0x3f3f3f3f;int num=0;
    if(!q1.empty() && res < q1.front()){
        res=q1.front();
        num=1;
    }
    if(!q2.empty() && res < q2.front()){
        res=q2.front();
        num=2;
    }
    if(!Q.empty() && res < Q.front()){
        res=Q.front();
        num=3;
    }
    if(num==1) q1.pop();
    else{
        if(num==2) q2.pop();
        else{
            if(num==3) Q.pop();
        }
    }
    return res;
}

int main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--){
        Q.push(a[i]);
    }
    for(int i=1;i<=m;i++,add+=q){
        tmp=maxnum()+add;
        if(i%t==0) printf("%lld ",tmp);
        t1=max(tmp*u/v-add-q,tmp-tmp*u/v-add-q);
        q1.push(t1);
        t2=min(tmp*u/v-add-q,tmp-tmp*u/v-add-q);
        q2.push(t2);
    }
    printf("\n");
    for(int i=1;!Q.empty()||!q2.empty()||!Q.empty();i++){
        long long  ans=maxnum();
        if(i%t==0) printf("%lld ",ans+add);
    }
    return 0;
} 
