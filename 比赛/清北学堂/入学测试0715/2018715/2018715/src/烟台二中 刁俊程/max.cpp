#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long t[100010];
struct hyq{
	int pos;
	int ha;
}m[101000];
int cmp(hyq a,hyq b){
	if(a.ha==b.ha) return a.pos>b.pos;
	return a.ha>b.ha;
}
int l,n,v1,v2,ans;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>v1>>v2;
	for(int i=1;i<=n;i++){
		cin>>m[i].pos>>m[i].ha;
		if(m[i].pos>l) m[i].ha=0;
	}
	sort(m+1,m+n+1,cmp);
	int now=0;
	for(int i=1;i<=n;i++){
		if(now>=m[i].pos) continue;
		ans+=m[i].ha*((m[i].pos-now)*(v1-v2));
		now=m[i].pos;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
