#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l, n, va, vb, past=0, now=0, bj, value;
long long ans=0;
struct view{
	int x, c;
}a[10005];
bool cmp(view a, view b){
	if(a.c==b.c) return a.x<b.x;
	return a.c>b.c;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1; i<=n; i++){
		cin>>a[i].x>>a[i].c;
	}
	sort(a+1, a+1+n, cmp);
	now=a[1].x;
	value=a[1].c;
	bj=1;
	while(bj<n){
		ans+=(now-past)*value;
		for(int i=bj+1; i<=n; i++){
			if(a[i].x>now){
				value=a[i].c;
				past=now;
				now=a[i].x;
				bj=i;
				break;
			}
		}
	}
	ans+=(now-past)*value;
	cout<<ans<<endl;;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
