#include <cstdio>
#include <algorithm>
#include <queue>

const int MAXN = 100010;
using namespace std;

struct item{
	int l;
	int r;
	inline bool operator < (item rhs) const {
		return l < rhs.l;
	}
}A[MAXN];
int dp[MAXN][110];
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) {
		int L,R;
		scanf("%d%d",&L,&R);	
		A[i].l = L;
		A[i].r = R;
	}
	sort(A + 1,A + n + 1);
	int cur = 0;
	int ans = 0;
	for(int o = 1;o <= n;o++){
		int t = 0;
		int l = 0;
		int r = 0;
		for(int j = o;j < min(o + k,n + 1);j++){
				if(A[j].l > r){
					l = A[j].l;
					r = A[j].r;
				}
				else {
					r = max(r,A[j].r);
					t = max(t,r - l);
					ans = max(ans,t);
				}
		}
		//printf("%d %d\n",l,r);
		t = max(t,r - l);
		ans = max(ans,t);
	}
	printf("%d",ans);
}
