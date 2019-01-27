#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int const maxn = 100050;
int n,k,sum,ans[maxn],cnt;
struct edge{
	int l,r,len;
}a[maxn];

void dfs(int i,int num){ //加了多少个1 
	if(num > k){sum = 0; return;} 
	if(a[i].r >= a[i+1].l && a[i+1].r > a[i].r){
		sum = sum + a[i+1].r - a[i].r;
		ans[++cnt] = sum;
		dfs(i+1,num+1);
	}
	if(a[i].r < a[i+1].l) {sum = 0; return ;}
}

int cmp(const edge a,const edge b){
	if(a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
    cin>>n>>k;
	for(int i = 1;i <= n ;++i){cin>>a[i].l>>a[i].r;
		a[i].len = a[i].r - a[i].l;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n ;++i){
		sum = a[i].len;
		ans[++cnt] = sum;
		dfs(i,1);
	  }
	sort(ans+1,ans+1+cnt);
	cout<<ans[cnt];
	return 0;
}
