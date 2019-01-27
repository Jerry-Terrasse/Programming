#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct haha{
	int l,r,p;
}a[100010];
int n,k,ll,end,cnt;
bool cmp(haha a,haha b){
	return a.r<b.r;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	end=a[1].r,cnt=1;
	ll=a[1].l;
	while(k--){
		for(int i=n;i>cnt;i--){
			if(!a[cnt].p&&a[i].l<=end){
				a[cnt].p=1;
				ll=min(ll,a[i].l);
				cnt=i;
				end=a[cnt].r;
			}
		}
	}
	int ans;
	ans=end-ll;
	cout<<ans;
	return 0;
}
