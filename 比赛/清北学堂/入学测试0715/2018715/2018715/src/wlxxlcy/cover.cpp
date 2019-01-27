#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct str{
    long long l; long long r;
}st[1000001];
long long i,s,k,a,maxn,n,m,len;
bool cmp(str x,str y){
    return x.l<y.l;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
    cin>>n>>k;
    for (i=1; i<=n; i++){
        cin>>st[i].l>>st[i].r;
		len=max(st[i].r-st[i].l,len);
	}
	if(k==1)
	{
		printf("%lld",len);
		return 0;
	}
    sort(st+1,st+n+1,cmp);
    a=st[1].l; s=st[1].r;
    while(k>0){
    for (i=2; i<=n; i++){
    if (st[i].l>s)
	{  m+=s-a+1; 
	   a=st[i].l; 
	   s=st[i].r; 
	   continue;
	}
    else 
      if (st[i].r>s) s=st[i].r;
    }
    k--;
	}
    cout<<m+s-a;
    return 0;
}
