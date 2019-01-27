#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
struct line{
	int l, r;
}a[100001];
bool cmp(line x, line y){
	return x.l<y.l;
}
int main(){
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&a[i].l, &a[i].r);
	sort(a+1, a+n+1, cmp);
	int qv=n-k;
	for(int i=1; i<=qv; i++){
		int j=1, minn=0x7fffffff, t;
		while(a[j].l<=a[1].r){
			if(a[j].r<minn){
				minn=a[j].r;
				t=j;
			}
			j++;
		}
		a[t].r=a[t].l;
	}
	int maxn=0, mion=0x7fffffff;
	for(int i=1; i<=k; i++){
		maxn=max(maxn, a[i].r);
		mion=min(mion, a[i].l);
	}
	printf("%d", maxn-mion);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
