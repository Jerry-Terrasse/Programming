#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct Ed{
    long long l; long long r;
}gg[1000010];
long long i,s,k,a,maxn,n,m,len;
bool cmp(Ed x,Ed y){
    return x.l<y.l;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
    cin>>n>>k;
    for (i=1; i<=n; i++){
       scanf("%lld%lld",&gg[i].l,&gg[i].r);
		len=max(gg[i].r-gg[i].l,len);
	}
	if(k==1)
	{
		printf("%lld",len);
		return 0;
	}
    sort(gg+1,gg+n+1,cmp);
    a=gg[1].l; s=gg[1].r;
    while(k>0){
    for (i=2;i<=n;i++){
    if (gg[i].l>s)
	{  m+=s-a+1; 
	   a=gg[i].l; 
	   s=gg[i].r; 
	   continue;
	}
    else 
      if (gg[i].r>s) s=gg[i].r;
    }
    k--;
	}
    cout<<m+s-a;
    return 0;
}
