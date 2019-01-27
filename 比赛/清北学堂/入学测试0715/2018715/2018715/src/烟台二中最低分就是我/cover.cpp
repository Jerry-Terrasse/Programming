#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define l first
#define r second
using namespace std;
typedef pair<int,int> pp;

pp sec[100020];
int n, k, ll, rr, ans = -1;
int main(){
	freopen("cover.in","r",stdin);freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1 ; i<=n ; i++)
		scanf("%d%d",&sec[i].l,&sec[i].r);
		
	sort(sec+1,sec+n+1);
	
for(int i=1 ; i<=n ; i++){
	int cur = 0, ii = i, kk = k;
	int ll = sec[ii].l, rr = -1;
	while(kk){
		while(sec[ii].l <=ll ){
			rr = max(rr,sec[ii].r);
			++ii;
		}
		ll = rr+1;
		--kk;
	}
	ans = max(ans,rr-sec[i].l);
}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
