#include <cstdio>
#include <climits>
#include<algorithm>
#define N_MAX 100005

int n,k;
int l[N_MAX],r[N_MAX];
int ans = INT_MIN;

void dfs(int x,int y,int ll,int rr){
	if(y == 0){
		ans = std::max(ans,rr - ll);
		//printf("%d %d\n",ll,rr);
		return;
	}
	if((ll >l[x] || rr < r[x]) && y > 0 && x < n)dfs(x + 1,y - 1,std::min(ll,l[x]),std::max(rr,r[x]));
	if(x < n&&y >= 0)dfs(x + 1,y,ll,rr);
}

int main(int argc,char *argv[]){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= 3;i++)scanf("%d %d",&l[i],&r[i]);
	dfs(1,k,INT_MAX,INT_MIN);
	printf("%d",ans);
	return 0;
}
