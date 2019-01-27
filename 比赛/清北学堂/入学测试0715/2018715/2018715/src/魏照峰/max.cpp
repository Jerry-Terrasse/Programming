#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int L,n,va,vb;
struct Side{
	int x,c;
};
Side s[101000];
bool cmp(Side a,Side b){
	if(a.c>b.c) return true;
	else
	if(a.c==b.c && a.x>b.x) return true;
	return false;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&L,&n,&va,&vb);
	for(int i=1;i<=n;i++){
		int x,c;
		scanf("%d%d",&x,&c);
		s[i].x=x; s[i].c=c;
	}
	sort(s+1,s+1+n,cmp);
	int lasti=0;//上一个位置所在处 
	long long ans=0;
	for(int i=1;i<=n;i++){
		int xi=s[i].x;
		int ci=s[i].c;
		if(xi<lasti) continue;
		ans+=ci*((xi-lasti)*(va-vb));
		lasti=xi; 
	}
	cout<<ans;
	fclose(stdin); fclose(stdout);
	return 0;
}
