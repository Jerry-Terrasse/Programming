#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define num 500010
using namespace std;

pair<int,int> young[500005];
pair<int,int> zx,zs,yx,ys;
int n,m,x,y,ans;

int ab(int x){
	return x>0? x:-x;
}

int maxn(int x,int y){
	return x>y? x:y;
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	zx=make_pair(0,0);
	zs=make_pair(0,num);
	ys=make_pair(num,num);
	yx=make_pair(num,0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&young[i].first,&young[i].second);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x+y>zx.first+zx.second) zx=make_pair(x,y);
		if(x+num-y>zs.first+num-zs.second) zs=make_pair(x,y);
		if(num-x+num-y>num-ys.first+num-ys.second) ys=make_pair(x,y);
		if(num-x+y>num-yx.first+yx.second) yx=make_pair(x,y);
		
	}
	for(int i=1;i<=n;i++){
		ans=0;
		ans=maxn(ans,ab(zx.first-young[i].first)+ab(zx.second-young[i].second));
		ans=maxn(ans,ab(zs.first-young[i].first)+ab(zs.second-young[i].second));
		ans=maxn(ans,ab(yx.first-young[i].first)+ab(yx.second-young[i].second));
		ans=maxn(ans,ab(ys.first-young[i].first)+ab(ys.second-young[i].second));
		printf("%d\n",ans);
	}
	return 0;
} 
