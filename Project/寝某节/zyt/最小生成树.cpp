#include<iostream>
#include<algorithm>
using namespace std;
struct edge {
	int u,v,w;
} e[200001];
int n,m,ans,cnt,f[5001];
bool cmp(edge x,edge y) {
	return x.w<y.w;
}
int find(int a) {
	return f[a]==a?a:f[a]=find(f[a]);
}
void kruskal() {
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		ans+=e[i].w;
		cnt++;
		f[fu]=fv;
		if(cnt==n-1) {
			cout<<ans;
			break;
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)f[i]=i;
	for(int i=1; i<=m; i++)cin>>e[i].u>>e[i].v>>e[i].w;
	kruskal();
	if(cnt!=n-1)cout<<"orz";
	return 0;
}
