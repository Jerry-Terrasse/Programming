#include<cstdio>
#include<algorithm>
using namespace std;
int ans,n,m;
struct hehe{
	int a;
	int b;
	int c;
}he1[100001];
int cmp(hehe e,hehe f){
	if(e.a!=f.a)
		return e.a<f.a;
	else
		return e.b<f.b;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&he1[i].a,&he1[i].b);
		he1[i].c=he1[i].b-he1[i].a;
	}
	sort(he1+1,he1+n+1,cmp);
	for(int i=1;i<=n;++i)
		ans+=he1[i].c;
	printf("%d",ans);
	return 0;
}
