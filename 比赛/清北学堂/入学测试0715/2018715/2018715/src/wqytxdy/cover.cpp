#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
const int N=1e5+3;
struct qujian{
	int l;int r;	
}a[N];
int f[305][305];
inline bool cmp(qujian x,qujian y){
	if(x.l!=y.l)
	return x.l<y.l;
	return x.r>y.r;
}
inline int len(int x,int y){
	return a[y].r-a[x].r;
}
int ans=-99999;
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].l,&a[i].r);	
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
   f[i][1]=a[i].r-a[i].l;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=min(i,k);++j){
		for(int h=i-1;h>=1;h--){
			if(a[i].l<=a[h].r)
			f[i][j]=max(f[i][j],f[h][j-1]+len(h,i));
			else
			f[i][j]=max(f[i][j],f[h][j-1]+a[i].r-a[i].l);
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;	
}
