#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n,k;
int ans;
struct set{
	int l,r,len;
}s[100050];
bool cmp(set x,set y){
	return x.l<y.l;
}
bool cmp1(set x,set y){
	return x.len>y.len;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	int minn=0x7fffffff,maxn=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i].l,&s[i].r);
		s[i].len=s[i].r-s[i].l;
		minn=min(minn,s[i].l);
		maxn=max(maxn,s[i].r);
	}
	sort(s+1,s+n,cmp);int last=0,p=k;
	for(int i=1;i<=n;i++){
		while(s[i].l<=last){
			i++;
		}
		p--;if(p<0)break;
		last=s[i].r;
	}
	if(p<0){
		sort(s+1,s+n,cmp1);
		for(int i=1;i<=k;i++){
			ans+=s[i].len;
		}
		cout<<ans<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}








