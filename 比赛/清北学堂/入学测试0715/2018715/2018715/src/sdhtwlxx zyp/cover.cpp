#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int const N = 100050;

int n,k,sum,ans[N],cnt;
struct edge{
	int l,r,len;
}a[N];

inline int read(){
	int x = 0;
	int flag = true;
	int k = getchar();
	while(k != '-' && !isdigit(k))
	    k = getchar();
	if(k == '-'){
	   k = getchar();
	   flag = false;
	}
	while(isdigit(k)){
		x = x * 10 + k - '0';
		k = getchar();
	}
	return (flag ? x : -x);
}

void dfs(int i,int num){ 
	if(num > k){
		sum = 0; 
		return;
	} 
	if(a[i].r >= a[i+1].l && a[i+1].r > a[i].r){
		sum = sum + a[i+1].r - a[i].r;
		ans[++cnt] = sum;
		dfs(i+1,num+1);
	}
	if(a[i].r < a[i+1].l) {sum = 0; return ;}
}

inline int cmp(const edge a,const edge b){
	if(a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n = read(); k = read();
	for(int i = 1;i <= n ;++i){
		a[i].l = read(); a[i].r = read();
		a[i].len = a[i].r - a[i].l;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n ;++i){
		sum = a[i].len;
		ans[++cnt] = sum;
		dfs(i,1);
	  }
	sort(ans+1,ans+1+cnt);
	printf("%d",ans[cnt]);
	return 0;
}
