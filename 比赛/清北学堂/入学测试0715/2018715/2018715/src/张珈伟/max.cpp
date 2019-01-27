#include <cstdio>
#include <algorithm>
#include <queue>

const int MAXN = 100010;
using namespace std;
int vis[MAXN];
struct item{
	int h,b;
	inline bool operator < (item rhs) const {
		if(b == rhs.b) return h < rhs.h;
		return b < rhs.b;
	}
};
priority_queue<item> q;

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int l,n,a,b;
	scanf("%d%d%d%d",&l,&n,&a,&b);
	int lim = l * (a - b);
	for(int i = 1;i <= n;i++) {
		int t;
		int h;
		scanf("%d%d",&h,&t);
		q.push({h,t});
	}
	int h = 0;
	int ans = 0;
	while(!q.empty()){
		item t = q.top();
		if(t.h > h) {
			ans += t.b * (a - b) * (t.h - h);
			h = t.h;
		}
		q.pop();
	}
	printf("%d",ans);
}
