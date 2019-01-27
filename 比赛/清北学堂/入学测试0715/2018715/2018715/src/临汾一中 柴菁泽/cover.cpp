#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, num, maxn=0, sum=0, ah=0;
struct qwq{
	int l, r;
}a[100005];
bool cmp(qwq a, qwq b){
	if(a.l==b.l){
		return a.r>b.r;
	}
	return a.l<b.l;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1; i<=n; i++){
			cin>>a[i].l>>a[i].r;
			ah=max(ah,a[i].r-a[i].l);
		}
		cout<<ah<<endl;
		return 0;
	}
	num=k;
	for(int i=1; i<=n; i++){
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1, a+1+n, cmp);
	for(int i=1; i<=n; i++){
		sum=a[i].r;
		num=k-1;
		while(num){
			for(int j=i+1; j<=n; j++){
				if(a[j].l<=sum){
					sum=max(sum, a[j].r);
				}
				else break;
			}
			num--;
		}
		sum=sum-a[i].l;
		maxn=max(maxn, sum);
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
