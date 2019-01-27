#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int young[500005]={0};
pair<int,int> loc[500005];
int n,m,x,y;

int ab(int x){
	return x>0? x:-x;
}

int maxn(int x,int y){
	return x>y? x:y;
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&loc[i].first,&loc[i].second);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			young[i]=maxn(young[i],(ab(loc[i].first-x)+ab(loc[i].second-y)));
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",young[i]);
	}
	return 0;
} 
